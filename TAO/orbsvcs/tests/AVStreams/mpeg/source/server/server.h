/* -*- c++ -*- */

/* $Id$ */

// ============================================================================
//
// = LIBRARY
//    server
// 
// = FILENAME
//    server.h
//
// = AUTHORS
//    Sumedh Mungee (sumedh@cs.wustl.edu)
//    Nagarajan Surendran (naga@cs.wustl.edu)
// 
// ============================================================================

#if !defined (TAO_AV_SERVER_H)
#define      TAO_AV_SERVER_H

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <time.h>
#include <sys/time.h>
#include "../include/common.h"
#include "../mpeg_server/proto.h"
#include "fileio.h"
#include "routine.h"
#include "com.h"
#include "ace/Get_Opt.h"

#include "ace/Acceptor.h"
#include "ace/Svc_Handler.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/INET_Addr.h"
#include "ace/SOCK_CODgram.h"
#include "ace/Select_Reactor.h"

#ifdef NATIVE_ATM
#include "atmcom.h"
#endif

#include "../mpeg_server/Video_Server.h"

class AV_Svc_Handler;

class AV_Acceptor 
  : public virtual ACE_Acceptor <AV_Svc_Handler, 
                                 ACE_SOCK_ACCEPTOR>
{
  // =TITLE
  //   This defines a AV_Acceptor which is an Acceptor and
  // overrides the make_svc_handler method of the Acceptor.
  //
  // =DESCRIPTION
  //   This class overrides the Acceptor's make_svc_handler so that a
  // AV_Svc_Handler can be created with a non-default constructor.
public:  
  virtual int make_svc_handler (AV_Svc_Handler *&sh);
  // Create a new  <AV_Svc_Handler> passing 'this' to the service handler
};

class AV_Svc_Handler 
  : public virtual ACE_Svc_Handler <ACE_SOCK_STREAM, 
                                    ACE_NULL_SYNCH>
{
  // =TITLE
  //   This class defines the service handler for a new connection to
  // the AV_Server.
  //
  // =DESCRIPTION
  //   This calls the handle_connection method for a new connection
  // which demuxes the connection to a video or audio server depending
  // on the connection request.
public:
  // = Initialization method.
  AV_Svc_Handler (ACE_Reactor * = 0,
                    AV_Acceptor * = 0);

  virtual int open (void *);
  // Perform the work of the SVC_HANDLER. Called by the acceptor
  // when a new connection shows up
  
  virtual int handle_connection (ACE_HANDLE = ACE_INVALID_HANDLE);
  // Handle one client connection.

  virtual int svc (void);
  // Thread method

  virtual int close (u_long);
  // Called if ACE_Svc_Handler is closed down unexpectedly.

  int handle_timeout (const ACE_Time_Value &,
                                  const void *arg);
  // handle the timeout 

private:

  ACE_SOCK_CODgram dgram_;
  // the UDP data socket

  ACE_INET_Addr server_data_addr_;
  // Data (UDP) Address of this server.
  
  ACE_INET_Addr client_data_addr_;
  // Data (UDP) Address of the client.

  AV_Acceptor *acceptor_;
  // Pointer to the Acceptor that created us so that we can remove it
  // from the <ACE_Reactor> when we <fork>.

  // %% need a similar dude for audio!
  Video_Server *vs_;
};

class AV_Server_Sig_Handler 
  : public virtual ACE_Event_Handler
{
public:
  AV_Server_Sig_Handler (void);

  virtual ACE_HANDLE get_handle (void) const;

  int register_handler (void);
  // this will register this sig_handler
  // with the reactor for SIGCHLD,SIGTERM,SIGINT

  virtual int shutdown (ACE_HANDLE, 
                        ACE_Reactor_Mask);

  virtual int handle_input (ACE_HANDLE);
  // handle input on the dummy handle.

  virtual int handle_signal (ACE_HANDLE signum,
                             siginfo_t * = 0,
                             ucontext_t* = 0);
  // handles the SIGCHLD,SIGTERM,SIGINT for the parent process i.e
  // the main thread..

  void int_handler (int sig);
  // Signal handler function for SIGTERM,SIGBUS,SIGINT

  void clear_child (int sig);
  // Signal handler function for SIGCHLD
private:
  ACE_HANDLE handle_;
  // dummy handle for the sig handler.
};


class AV_Server
{
  // =TITLE
  //   Defines a class that abstracts the functionality of a 
  //   video and audio server.
  // =DESCRIPTION
  //   Using the class is as simple as calling init () first and then
  //   run. It uses an acceptor with the default ACE_Reactor::instance ().
public:
  AV_Server ();
  // constructor

  int init (int argc,
            char **argv);
  // Initialize the AV_Server

  int run ();
  // Run the AV_Server

  static void on_exit_routine (void);
  // Routine called when this process exits.

  ~AV_Server ();
  // Destructor
private:

  AV_Acceptor acceptor_;
  // the acceptor

  AV_Server_Sig_Handler *signal_handler_;
  // Signal handler for SIGCHLD,SIGINT,SIGTERM,SIGBUS

  ACE_INET_Addr server_control_addr_;
  // Control (TCP) Address of this server.

  int parse_args (int argcs,
                  char **argv);
  // parse the arguments

};

#endif // TAO_AV_SERVER_H
