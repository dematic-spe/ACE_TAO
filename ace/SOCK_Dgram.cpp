// SOCK_Dgram.cpp
// $Id$

#include "ace/SOCK_Dgram.h"
#include "ace/Handle_Set.h"
#include "ace/Synch.h"
#include "ace/Log_Msg.h"

#if defined (ACE_LACKS_INLINE_FUNCTIONS)
#include "ace/SOCK_Dgram.i"
#endif

ACE_RCSID(ace, SOCK_Dgram, "$Id$")

ACE_ALLOC_HOOK_DEFINE(ACE_SOCK_Dgram)

void
ACE_SOCK_Dgram::dump (void) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::dump");
}

// Allows a client to read from a socket without having to provide a
// buffer to read.  This method determines how much data is in the
// socket, allocates a buffer of this size, reads in the data, and
// returns the number of bytes read.

ssize_t
ACE_SOCK_Dgram::recv (iovec io_vec[],
                      ACE_Addr &addr,
                      int flags,
                      const ACE_Time_Value *timeout) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::recv");
#if defined (FIONREAD)
  ACE_Handle_Set handle_set;
  handle_set.reset ();
  handle_set.set_bit (this->get_handle ());

  // Check the status of the current socket to make sure there's data
  // to recv (or time out).
  switch (ACE_OS::select (int (this->get_handle ()) + 1,
                          handle_set,
                          0, 0,
                          timeout))
    {
    case -1:
      return -1;
      /* NOTREACHED */
    case 0:
      errno = ETIME;
      return -1;
      /* NOTREACHED */
    default:
      // Goes fine, fallthrough to get data
      break;
    }

  sockaddr *saddr = (sockaddr *) addr.get_addr ();
  int addr_len = addr.get_size ();
  u_long inlen;

  if (ACE_OS::ioctl (this->get_handle (),
                     FIONREAD, (u_long *) &inlen) == -1)
    return -1;
  else if (inlen > 0)
    {
      ACE_NEW_RETURN (io_vec->iov_base,
                      char[inlen],
                      -1);
      io_vec->iov_len = ACE_OS::recvfrom (this->get_handle (),
                                          (char *) io_vec->iov_base,
                                          inlen,
                                          flags,
                                          (sockaddr *) saddr,
                                          &addr_len);
      addr.set_size (addr_len);
      return io_vec->iov_len;
    }
  else
    return 0;
#else
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (io_vec);
  ACE_UNUSED_ARG (timeout);
  ACE_NOTSUP_RETURN (-1);
#endif /* FIONREAD */
}

// Here's the shared open function.  Note that if we are using the
// PF_INET protocol family and the address of LOCAL == the address of
// the special variable SAP_ANY then we are going to arbitrarily bind
// to a portnumber.

int
ACE_SOCK_Dgram::shared_open (const ACE_Addr &local,
                             int protocol_family)
{
  ACE_TRACE ("ACE_SOCK_Dgram::shared_open");
  int error = 0;

  if (local == ACE_Addr::sap_any
      && protocol_family == PF_INET)
    {
      if (ACE::bind_port (this->get_handle ()) == -1)
        error = 1;
    }
  else if (ACE_OS::bind (this->get_handle (),
                         ACE_reinterpret_cast (sockaddr *,
                                               local.get_addr ()),
                         local.get_size ()) == -1)
    error = 1;

  if (error != 0)
    this->close ();

  return error ? -1 : 0;
}

int
ACE_SOCK_Dgram::open (const ACE_Addr &local,
                      int protocol_family,
                      int protocol,
                      ACE_Protocol_Info *protocolinfo,
                      ACE_SOCK_GROUP g,
                      u_long flags,
                      int reuse_addr)
{
  if (ACE_SOCK::open (SOCK_DGRAM,
                      protocol_family,
                      protocol,
                      protocolinfo,
                      g,
                      flags,
                      reuse_addr) == -1)
    return -1;
  else if (this->shared_open (local,
                              protocol_family) == -1)
    return -1;
  else
    return 0;
}

// Here's the general-purpose open routine.

int
ACE_SOCK_Dgram::open (const ACE_Addr &local,
                      int protocol_family,
                      int protocol,
                      int reuse_addr)
{
  ACE_TRACE ("ACE_SOCK_Dgram::open");
  if (ACE_SOCK::open (SOCK_DGRAM,
                      protocol_family,
                      protocol,
                      reuse_addr) == -1)
    return -1;
  else
    return this->shared_open (local,
                              protocol_family);
}

// Here's the general-purpose constructor used by a connectionless
// datagram ``server''...

ACE_SOCK_Dgram::ACE_SOCK_Dgram (const ACE_Addr &local,
                                int protocol_family,
                                int protocol,
                                int reuse_addr)
{
  ACE_TRACE ("ACE_SOCK_Dgram::ACE_SOCK_Dgram");

  if (this->open (local,
                  protocol_family,
                  protocol,
                  reuse_addr) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_LIB_TEXT ("%p\n"),
                ACE_LIB_TEXT ("ACE_SOCK_Dgram")));
}

ACE_SOCK_Dgram::ACE_SOCK_Dgram (const ACE_Addr &local,
                                int protocol_family,
                                int protocol,
                                ACE_Protocol_Info *protocolinfo,
                                ACE_SOCK_GROUP g,
                                u_long flags,
                                int reuse_addr)
{
  ACE_TRACE ("ACE_SOCK_Dgram::ACE_SOCK_Dgram");
  if (this->open (local,
                  protocol_family,
                  protocol,
                  protocolinfo,
                  g,
                  flags,
                  reuse_addr) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_LIB_TEXT ("%p\n"),
                ACE_LIB_TEXT ("ACE_SOCK_Dgram")));
}

#if defined (ACE_HAS_MSG)
// Send an iovec of size N to ADDR as a datagram (connectionless
// version).

ssize_t
ACE_SOCK_Dgram::send (const iovec iov[],
                      size_t n,
                      const ACE_Addr &addr,
                      int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::send");
  msghdr send_msg;

  send_msg.msg_iov = (iovec *) iov;
  send_msg.msg_iovlen = n;
#if defined (ACE_HAS_SOCKADDR_MSG_NAME)
  send_msg.msg_name = (struct sockaddr *) addr.get_addr ();
#else
  send_msg.msg_name = (char *) addr.get_addr ();
#endif /* ACE_HAS_SOCKADDR_MSG_NAME */
  send_msg.msg_namelen = addr.get_size ();

#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
  send_msg.msg_control = 0;
  send_msg.msg_controllen = 0;
  send_msg.msg_flags = 0;
#else
  send_msg.msg_accrights    = 0;
  send_msg.msg_accrightslen = 0;
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */

  return ACE_OS::sendmsg (this->get_handle (),
                          &send_msg,
                          flags);
}

// Recv an iovec of size N to ADDR as a datagram (connectionless
// version).

ssize_t
ACE_SOCK_Dgram::recv (iovec iov[],
                      size_t n,
                      ACE_Addr &addr,
                      int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::recv");
  msghdr recv_msg;

  recv_msg.msg_iov = (iovec *) iov;
  recv_msg.msg_iovlen = n;
#if defined (ACE_HAS_SOCKADDR_MSG_NAME)
  recv_msg.msg_name = (struct sockaddr *) addr.get_addr ();
#else
  recv_msg.msg_name = (char *) addr.get_addr ();
#endif /* ACE_HAS_SOCKADDR_MSG_NAME */
  recv_msg.msg_namelen = addr.get_size ();

#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
  recv_msg.msg_control = 0 ;
  recv_msg.msg_controllen = 0 ;
#else
  recv_msg.msg_accrights = 0;
  recv_msg.msg_accrightslen = 0;
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */

  ssize_t status = ACE_OS::recvmsg (this->get_handle (),
                                    &recv_msg,
                                    flags);
  addr.set_size (recv_msg.msg_namelen);
  return status;
}

#else /* ACE_HAS_MSG */

// Send an iovec of size N to ADDR as a datagram (connectionless
// version).

ssize_t
ACE_SOCK_Dgram::send (const iovec iov[],
                      size_t n,
                      const ACE_Addr &addr,
                      int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::send");

  size_t length = 0;
  size_t i;

  // Determine the total length of all the buffers in <iov>.
  for (i = 0; i < n; i++)
#if ! (defined(__BORLANDC__) && (__BORLANDC__ >= 0x0530))
    // The iov_len is unsigned in Borland. If we go ahead and try the
    // if, it will emit a warning.
    if (iov[i].iov_len < 0)
      return -1;
    else
#endif
      length += iov[i].iov_len;

  char *buf;

#if defined (ACE_HAS_ALLOCA)
  buf = alloca (length);
#else
  ACE_NEW_RETURN (buf,
                  char[length],
                  -1);
#endif /* !defined (ACE_HAS_ALLOCA) */

  char *ptr = buf;

  for (i = 0; i < n; i++)
    {
      ACE_OS::memcpy (ptr, iov[i].iov_base, iov[i].iov_len);
      ptr += iov[i].iov_len;
    }

  ssize_t result = ACE_SOCK_Dgram::send (buf, length, addr, flags);
#if !defined (ACE_HAS_ALLOCA)
  delete [] buf;
#endif /* !defined (ACE_HAS_ALLOCA) */
  return result;
}

// Recv an iovec of size N to ADDR as a datagram (connectionless
// version).

ssize_t
ACE_SOCK_Dgram::recv (iovec iov[],
                      size_t n,
                      ACE_Addr &addr,
                      int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::recv");

  ssize_t length = 0;
  size_t i;

  for (i = 0; i < n; i++)
#if ! (defined(__BORLANDC__) && (__BORLANDC__ >= 0x0530))
    // The iov_len is unsigned in Borland. If we go ahead and try the
    // if, it will emit a warning.
    if (iov[i].iov_len < 0)
      return -1;
    else
#endif
      length += iov[i].iov_len;

  char *buf;

#if defined (ACE_HAS_ALLOCA)
  buf = alloca (length);
#else
  ACE_NEW_RETURN (buf,
                  char[length],
                  -1);
#endif /* !defined (ACE_HAS_ALLOCA) */

  length = ACE_SOCK_Dgram::recv (buf, length, addr, flags);

  if (length != -1)
    {
      char *ptr = buf;
      int copyn = length;

      for (i = 0;
           i < n && copyn > 0;
           i++)
        {
          ACE_OS::memcpy (iov[i].iov_base, ptr,
                          // iov_len is int on some platforms, size_t on others
                          copyn > (int) iov[i].iov_len
                            ? (size_t) iov[i].iov_len
                            : (size_t) copyn);
          ptr += iov[i].iov_len;
          copyn -= iov[i].iov_len;
        }
    }

#if !defined (ACE_HAS_ALLOCA)
  delete [] buf;
#endif /* !defined (ACE_HAS_ALLOCA) */
  return length;
}

#endif /* ACE_HAS_MSG */

ssize_t
ACE_SOCK_Dgram::recv (void *buf,
                      size_t n,
                      ACE_Addr &addr,
                      int flags,
                      const ACE_Time_Value *timeout) const
{
  ACE_Handle_Set handle_set;
  handle_set.reset ();
  handle_set.set_bit (this->get_handle ());

  // Check the status of the current socket.
  switch (ACE_OS::select (int (this->get_handle ()) + 1,
                          handle_set,
                          0,
                          0,
                          timeout))
    {
    case -1:
      return -1;
      /* NOTREACHED */
    case 0:
      errno = ETIME;
      return -1;
      /* NOTREACHED */
    default:
      // Goes fine, call <recv> to get data
      return this->recv (buf, n, addr, flags);
    }
}

ssize_t
ACE_SOCK_Dgram::send (const void *buf,
                      size_t n,
                      ACE_Addr &addr,
                      int flags,
                      const ACE_Time_Value *timeout) const
{
  ACE_Handle_Set handle_set;
  handle_set.reset ();
  handle_set.set_bit (this->get_handle ());

  // Check the status of the current socket.
  switch (ACE_OS::select (int (this->get_handle ()) + 1,
                          0,
                          handle_set,
                          0,
                          timeout))
    {
    case -1:
      return -1;
      /* NOTREACHED */
    case 0:
      errno = ETIME;
      return -1;
      /* NOTREACHED */
    default:
      // Goes fine, call <send> to get data
      return this->send (buf, n, addr, flags);
    }
}
