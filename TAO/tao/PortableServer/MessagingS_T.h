// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_MESSAGINGS_T_H_
#define _TAO_IDL_MESSAGINGS_T_H_

#include "ace/pre.h"
#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (ACE_HAS_USING_KEYWORD)

TAO_NAMESPACE  POA_Messaging
{
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class TAO_Export ReplyHandler_tie : public ReplyHandler
  {
  public:
    ReplyHandler_tie (T &t);
    // the T& ctor
    ReplyHandler_tie (T &t, PortableServer::POA_ptr poa);
    // ctor taking a POA
    ReplyHandler_tie (T *tp, CORBA::Boolean release=1);
    // ctor taking pointer and an ownership flag
    ReplyHandler_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release=1);
    // ctor with T*, ownership flag and a POA
    ~ReplyHandler_tie (void);
    // dtor
    
    // TIE specific functions
    T *_tied_object (void);
    // return the underlying object
    void _tied_object (T &obj);
    // set the underlying object
    void _tied_object (T *obj, CORBA::Boolean release=1);
    // set the underlying object and the ownership flag
    CORBA::Boolean _is_owner (void);
    // do we own it
    void _is_owner (CORBA::Boolean b);
    // set the ownership
    
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
        CORBA::Environment &ACE_TRY_ENV = 
          TAO_default_environment ()
      );
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    CORBA::Boolean rel_;
    
    // copy and assignment are not allowed
    ReplyHandler_tie (const ReplyHandler_tie &);
    void operator= (const ReplyHandler_tie &);
  };

}
TAO_NAMESPACE_CLOSE // module Messaging

#endif /* ACE_HAS_USING_KEYWORD */

#if defined (__ACE_INLINE__)
#include "MessagingS_T.i"
#endif /* defined INLINE */


#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "MessagingS_T.cpp"
#endif /* defined REQUIRED SOURCE */


#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("MessagingS_T.cpp")
#endif /* defined REQUIRED PRAGMA */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include "ace/post.h"
#endif /* ifndef */
