// $Id$

// ******************************************************************
// Include Section
// ******************************************************************

#include "ace/Get_Opt.h"

#include "orbsvcs/CosNotifyCommC.h"
#include "orbsvcs/CosNamingC.h"
#include "Notify_Sequence_Push_Consumer.h"
#include "goC.h"

#include "Notify_Test_Client.h"

#if !defined (PATH_MAX)
#define PATH_MAX 1024
#endif /* PATH_MAX */

// ******************************************************************
// Data Section
// ******************************************************************

static const char* ior = "file://supplier.ior";
static CORBA::Short order_policy = CosNotification::FifoOrder;
static unsigned int low = 19;
static unsigned int high = 20;

// ******************************************************************
// Subroutine Section
// ******************************************************************

class Consumer_Client : public Notify_Test_Client
{
public:
  virtual int parse_args (int argc, char* argv[]);
};


int
Consumer_Client::parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "k:l:h:d:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'k':
        ior = get_opts.optarg;
        break;

      case 'l':
        low = ACE_OS::atoi (get_opts.optarg);
        break;

      case 'h':
        high = ACE_OS::atoi (get_opts.optarg);
        break;

      case 'd':
      {
        const char* order = get_opts.optarg;
        if (ACE_OS::strcmp (order, "fifo") == 0)
          {
            order_policy = CosNotification::FifoOrder;
          }
        else if (ACE_OS::strcmp (order, "priority") == 0)
          {
            order_policy = CosNotification::PriorityOrder;
          }
        else if (ACE_OS::strcmp (order, "deadline") == 0)
          {
            order_policy = CosNotification::DeadlineOrder;
#if !defined (ACE_HAS_TIMED_MESSAGE_BLOCKS)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "This order policy requires timed message "
                               "blocks.\nPlease #define "
                               "ACE_HAS_TIMED_MESSAGE_BLOCKS in your "
                               "config.h\n"), -1);
#endif
          }
        else
          {
            ACE_ERROR_RETURN ((LM_ERROR,
                               "Unknown ordering policy: %s\n",
                               order_policy),
                              -1);
          }
        break;
      }
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-k <ior> "
                           "-l <low expected events> "
                           "-h <high expected events> "
                           "-d <fifo|priority|deadline> "
                           "\n",
                           argv [0]),
                          -1);
      }
  // Indicates sucessful parsing of the command line
  return 0;
}


static CosNotifyChannelAdmin::ConsumerAdmin_ptr
create_consumeradmin (CosNotifyChannelAdmin::EventChannel_ptr ec
                      TAO_ENV_ARG_DECL)
{
  CosNotifyChannelAdmin::AdminID adminid = 0;
  CosNotifyChannelAdmin::ConsumerAdmin_var admin =
    ec->new_for_consumers (CosNotifyChannelAdmin::OR_OP,
                           adminid
                           TAO_ENV_ARG_PARAMETER);

  ACE_CHECK_RETURN (0);

  // Setup the CA to receive all type of events
  CosNotification::EventTypeSeq added (1);
  CosNotification::EventTypeSeq removed (0);
  added.length (1);
  removed.length (0);

  added[0].domain_name =  CORBA::string_dup ("*");
  added[0].type_name = CORBA::string_dup ("*");

  admin->subscription_change (added, removed TAO_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return CosNotifyChannelAdmin::ConsumerAdmin::_duplicate (admin.in ());
}


static void
create_consumers (CosNotifyChannelAdmin::ConsumerAdmin_ptr admin,
                  Notify_Test_Client* client
                  TAO_ENV_ARG_DECL)
{
  // startup the consumer
  Notify_Sequence_Push_Consumer* consumer_1;
  ACE_NEW_THROW_EX (consumer_1,
                    Notify_Sequence_Push_Consumer ("consumer1",
                                                   order_policy,
                                                   low,
                                                   high,
                                                   client->done ()),
                    CORBA::NO_MEMORY ());

  consumer_1->init (client->root_poa () TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  consumer_1->connect (admin TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

// ******************************************************************
// Main Section
// ******************************************************************

int main (int argc, char* argv[])
{
  int status = 0;
  ACE_TRY_NEW_ENV
    {
      Consumer_Client client;

      status = client.init (argc, argv TAO_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (status == 0)
        {
          CosNotifyChannelAdmin::EventChannel_var ec =
            client.create_event_channel ("MyEventChannel", 1 TAO_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          CORBA::ORB_ptr orb = client.orb ();
          CORBA::Object_var object =
                              orb->string_to_object (ior TAO_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          sig_var sig = sig::_narrow (object.in () TAO_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          if (CORBA::is_nil (sig.in ()))
            {
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "Object reference <%s> is nil\n",
                                 ior),
                                1);
            }

          CosNotifyChannelAdmin::ConsumerAdmin_var admin =
            create_consumeradmin (ec.in () TAO_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          if (!CORBA::is_nil (admin.in ()))
            {
              create_consumers (admin.in (), &client TAO_ENV_ARG_PARAMETER);
              ACE_TRY_CHECK;

              // Tell the supplier to go
              sig->go (TAO_ENV_SINGLE_ARG_PARAMETER);
              ACE_TRY_CHECK;

              // Wait until the supplier is done
              // before we start receiving events.
              ACE_stat buf;
              char ior_file[PATH_MAX];
              const char* filepart = ACE_OS_String::strstr (ior, "file://");
              if (filepart != 0)
                {
                  ACE_OS_String::strcpy (ior_file, filepart + 7);
                  while (ACE_OS::stat (ior_file, &buf) == 0)
                    {
                      ACE_OS::sleep (1);
                    }
                }

              unsigned int try_count = 0;
              unsigned int try_max = (high - low) * 2;
              while (client.done () <= 1)
                {
                  // See if we can get any more events
                  if (client.done ())
                    {
                      ACE_OS::sleep (3);
                      try_count++;
                      if (try_count >= try_max)
                        break;
                    }
                  if (orb->work_pending ())
                    {
                      orb->perform_work ();
                    }
                }
            }
        }
    }
  ACE_CATCH (CORBA::Exception, e)
    {
      ACE_PRINT_EXCEPTION (e,
                           "Consumer exception: ");
      status = 1;
    }
  ACE_ENDTRY;

  return status;
}
