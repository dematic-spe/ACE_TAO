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

#ifndef _TAO_IDL_CORBA_DOMAINC_H_
#define _TAO_IDL_CORBA_DOMAINC_H_

#include "ace/pre.h"

#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "PolicyC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */


#if !defined (_CORBA_DOMAINMANAGER___PTR_CH_)
#define _CORBA_DOMAINMANAGER___PTR_CH_

  class CORBA_DomainManager;
  typedef CORBA_DomainManager *CORBA_DomainManager_ptr;

#endif /* end #if !defined */


#if !defined (_CORBA_DOMAINMANAGER___VAR_CH_)
#define _CORBA_DOMAINMANAGER___VAR_CH_

  class TAO_Export CORBA_DomainManager_var : public TAO_Base_var
  {
  public:
    CORBA_DomainManager_var (void); // default constructor
    CORBA_DomainManager_var (CORBA_DomainManager_ptr p) : ptr_ (p) {}
    CORBA_DomainManager_var (const CORBA_DomainManager_var &); // copy constructor
    ~CORBA_DomainManager_var (void); // destructor

    CORBA_DomainManager_var &operator= (CORBA_DomainManager_ptr);
    CORBA_DomainManager_var &operator= (const CORBA_DomainManager_var &);
    CORBA_DomainManager_ptr operator-> (void) const;

    operator const CORBA_DomainManager_ptr &() const;
    operator CORBA_DomainManager_ptr &();
    // in, inout, out, _retn
    CORBA_DomainManager_ptr in (void) const;
    CORBA_DomainManager_ptr &inout (void);
    CORBA_DomainManager_ptr &out (void);
    CORBA_DomainManager_ptr _retn (void);
    CORBA_DomainManager_ptr ptr (void) const;

    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static CORBA_DomainManager_ptr duplicate (CORBA_DomainManager_ptr);
    static void release (CORBA_DomainManager_ptr);
    static CORBA_DomainManager_ptr nil (void);
    static CORBA_DomainManager_ptr narrow (CORBA::Object *, CORBA::Environment &);
    static CORBA::Object * upcast (void *);

  private:
    CORBA_DomainManager_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    CORBA_DomainManager_var (const TAO_Base_var &rhs);
    CORBA_DomainManager_var &operator= (const TAO_Base_var &rhs);
  };


#endif /* end #if !defined */


#if !defined (_CORBA_DOMAINMANAGER___OUT_CH_)
#define _CORBA_DOMAINMANAGER___OUT_CH_

  class TAO_Export CORBA_DomainManager_out
  {
  public:
    CORBA_DomainManager_out (CORBA_DomainManager_ptr &);
    CORBA_DomainManager_out (CORBA_DomainManager_var &);
    CORBA_DomainManager_out (const CORBA_DomainManager_out &);
    CORBA_DomainManager_out &operator= (const CORBA_DomainManager_out &);
    CORBA_DomainManager_out &operator= (const CORBA_DomainManager_var &);
    CORBA_DomainManager_out &operator= (CORBA_DomainManager_ptr);
    operator CORBA_DomainManager_ptr &();
    CORBA_DomainManager_ptr &ptr (void);
    CORBA_DomainManager_ptr operator-> (void);

  private:
    CORBA_DomainManager_ptr &ptr_;
  };


#endif /* end #if !defined */


#if !defined (_CORBA_DOMAINMANAGER_CH_)
#define _CORBA_DOMAINMANAGER_CH_

  // Forward Classes Declaration
  class _TAO_CORBA_DomainManager_Proxy_Impl;
  class _TAO_CORBA_DomainManager_Remote_Proxy_Impl;
  class _TAO_CORBA_DomainManager_Proxy_Broker;
  class _TAO_CORBA_DomainManager_Remote_Proxy_Broker;

  class TAO_Export CORBA_DomainManager : public virtual CORBA::Object
  {
  public:
  #if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef CORBA_DomainManager_ptr _ptr_type;
    typedef CORBA_DomainManager_var _var_type;
  #endif /* ! __GNUC__ || g++ >= 2.8 */

    // the static operations
    static CORBA_DomainManager_ptr _duplicate (CORBA_DomainManager_ptr obj);
    static CORBA_DomainManager_ptr _narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );
    static CORBA_DomainManager_ptr _unchecked_narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );
    static CORBA_DomainManager_ptr _nil (void)
      {
        return (CORBA_DomainManager_ptr)0;
      }

    static void _tao_any_destructor (void*);

    virtual CORBA::Policy_ptr get_domain_policy (
        CORBA::PolicyType policy_type,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

    virtual CORBA::Boolean _is_a (
        const CORBA::Char *type_id,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );
    virtual void *_tao_QueryInterface (ptr_arith_t type);

    virtual const char* _interface_repository_id (void) const;

  private:
    _TAO_CORBA_DomainManager_Proxy_Broker *the_TAO_CORBA_DomainManager_Proxy_Broker_;

  protected:
    CORBA_DomainManager (int collocated = 0);

    protected:
      // This methods travese the inheritance tree and set the
      // parents piece of the given class in the right mode
      virtual void CORBA_DomainManager_setup_collocation (int collocated);

      CORBA_DomainManager (
        TAO_Stub *objref,
        CORBA::Boolean _tao_collocated = 0,
        TAO_Abstract_ServantBase *servant = 0
        );

      friend class _TAO_CORBA_DomainManager_Remote_Proxy_Impl;
      friend class _TAO_CORBA_DomainManager_ThruPOA_Proxy_Impl;
      friend class _TAO_CORBA_DomainManager_Direct_Proxy_Impl;

    virtual ~CORBA_DomainManager (void);
  private:
    CORBA_DomainManager (const CORBA_DomainManager &);
    void operator= (const CORBA_DomainManager &);
  };


// The Proxy Implementations are used by each interface to
// perform a call. Each different implementation encapsulate
// an invocation logics.


  ///////////////////////////////////////////////////////////////////////
  //                    Base  Impl. Declaration
  //

  class TAO_Export _TAO_CORBA_DomainManager_Proxy_Impl : public virtual TAO_Object_Proxy_Impl
  {
  public:
    virtual ~_TAO_CORBA_DomainManager_Proxy_Impl (void) { }

        virtual CORBA::Policy_ptr get_domain_policy (
        CORBA::Object_ptr _collocated_tao_target_,
        CORBA::PolicyType policy_type,
        CORBA::Environment &ACE_TRY_ENV
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

protected:
    _TAO_CORBA_DomainManager_Proxy_Impl (void);

  };
  //
  //                Base  Proxy Impl. Declaration
  ///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                    Remote  Impl. Declaration
//

class TAO_Export _TAO_CORBA_DomainManager_Remote_Proxy_Impl :
  public virtual _TAO_CORBA_DomainManager_Proxy_Impl,
  public virtual TAO_Remote_Object_Proxy_Impl
{
public:
  _TAO_CORBA_DomainManager_Remote_Proxy_Impl (void);

  virtual ~_TAO_CORBA_DomainManager_Remote_Proxy_Impl (void) { }

  virtual CORBA::Policy_ptr get_domain_policy (
      CORBA::Object_ptr _collocated_tao_target_,
      CORBA::PolicyType policy_type,
      CORBA::Environment &ACE_TRY_ENV
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

};

//
//                Base  Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////


// The Proxy Brokers are used by each interface to get
// the right proxy for performing a call. In the new
// collocation scheme, the proxy to be used can vary on
// a call by call basis.



///////////////////////////////////////////////////////////////////////
//                 Base Proxy Broker Declaration
//

class TAO_Export _TAO_CORBA_DomainManager_Proxy_Broker
{
public:
  virtual ~_TAO_CORBA_DomainManager_Proxy_Broker (void);
  virtual _TAO_CORBA_DomainManager_Proxy_Impl &select_proxy (
    CORBA_DomainManager *object,
    CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
  ) = 0;

protected:
  _TAO_CORBA_DomainManager_Proxy_Broker (void);

};

//
//              End Base Proxy Broker Declaration
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                 Remote Proxy Broker Declaration
//

class TAO_Export _TAO_CORBA_DomainManager_Remote_Proxy_Broker : public virtual _TAO_CORBA_DomainManager_Proxy_Broker
{
public:
  _TAO_CORBA_DomainManager_Remote_Proxy_Broker (void);

  virtual ~_TAO_CORBA_DomainManager_Remote_Proxy_Broker (void);

  virtual _TAO_CORBA_DomainManager_Proxy_Impl &select_proxy (
    CORBA_DomainManager *object,
    CORBA_Environment &ACE_TRY_ENV
  );

private:
  _TAO_CORBA_DomainManager_Remote_Proxy_Impl remote_proxy_impl_;
// This member function is used to get an handle to the unique instance
// of the Remote Proxy Broker that is available for a given
// interface.

public:
  static _TAO_CORBA_DomainManager_Remote_Proxy_Broker *the_TAO_CORBA_DomainManager_Remote_Proxy_Broker (void);
};


//
//              End Remote Proxy Broker Declaration
///////////////////////////////////////////////////////////////////////


#endif /* end #if !defined */

TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_CORBA_DomainManager;

TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong SecConstruction;


#if !defined (_CORBA_CONSTRUCTIONPOLICY___PTR_CH_)
#define _CORBA_CONSTRUCTIONPOLICY___PTR_CH_

class CORBA_ConstructionPolicy;
typedef CORBA_ConstructionPolicy *CORBA_ConstructionPolicy_ptr;

#endif /* end #if !defined */


#if !defined (_CORBA_CONSTRUCTIONPOLICY___VAR_CH_)
#define _CORBA_CONSTRUCTIONPOLICY___VAR_CH_

class TAO_Export CORBA_ConstructionPolicy_var : public TAO_Base_var
{
public:
  CORBA_ConstructionPolicy_var (void); // default constructor
  CORBA_ConstructionPolicy_var (CORBA_ConstructionPolicy_ptr p) : ptr_ (p) {}
  CORBA_ConstructionPolicy_var (const CORBA_ConstructionPolicy_var &); // copy constructor
  ~CORBA_ConstructionPolicy_var (void); // destructor

  CORBA_ConstructionPolicy_var &operator= (CORBA_ConstructionPolicy_ptr);
  CORBA_ConstructionPolicy_var &operator= (const CORBA_ConstructionPolicy_var &);
  CORBA_ConstructionPolicy_ptr operator-> (void) const;

  operator const CORBA_ConstructionPolicy_ptr &() const;
  operator CORBA_ConstructionPolicy_ptr &();
  // in, inout, out, _retn
  CORBA_ConstructionPolicy_ptr in (void) const;
  CORBA_ConstructionPolicy_ptr &inout (void);
  CORBA_ConstructionPolicy_ptr &out (void);
  CORBA_ConstructionPolicy_ptr _retn (void);
  CORBA_ConstructionPolicy_ptr ptr (void) const;

  // Hooks used by template sequence and object manager classes
  // for non-defined forward declared interfaces.
  static CORBA_ConstructionPolicy_ptr duplicate (CORBA_ConstructionPolicy_ptr);
  static void release (CORBA_ConstructionPolicy_ptr);
  static CORBA_ConstructionPolicy_ptr nil (void);
  static CORBA_ConstructionPolicy_ptr narrow (CORBA::Object *, CORBA::Environment &);
  static CORBA::Object * upcast (void *);

private:
  CORBA_ConstructionPolicy_ptr ptr_;
  // Unimplemented - prevents widening assignment.
  CORBA_ConstructionPolicy_var (const TAO_Base_var &rhs);
  CORBA_ConstructionPolicy_var &operator= (const TAO_Base_var &rhs);
};


#endif /* end #if !defined */


#if !defined (_CORBA_CONSTRUCTIONPOLICY___OUT_CH_)
#define _CORBA_CONSTRUCTIONPOLICY___OUT_CH_

class TAO_Export CORBA_ConstructionPolicy_out
{
public:
  CORBA_ConstructionPolicy_out (CORBA_ConstructionPolicy_ptr &);
  CORBA_ConstructionPolicy_out (CORBA_ConstructionPolicy_var &);
  CORBA_ConstructionPolicy_out (const CORBA_ConstructionPolicy_out &);
  CORBA_ConstructionPolicy_out &operator= (const CORBA_ConstructionPolicy_out &);
  CORBA_ConstructionPolicy_out &operator= (const CORBA_ConstructionPolicy_var &);
  CORBA_ConstructionPolicy_out &operator= (CORBA_ConstructionPolicy_ptr);
  operator CORBA_ConstructionPolicy_ptr &();
  CORBA_ConstructionPolicy_ptr &ptr (void);
  CORBA_ConstructionPolicy_ptr operator-> (void);

private:
  CORBA_ConstructionPolicy_ptr &ptr_;
};


#endif /* end #if !defined */


#if !defined (_CORBA_CONSTRUCTIONPOLICY_CH_)
#define _CORBA_CONSTRUCTIONPOLICY_CH_

// Forward Classes Declaration
class _TAO_CORBA_ConstructionPolicy_Proxy_Impl;
class _TAO_CORBA_ConstructionPolicy_Remote_Proxy_Impl;
class _TAO_CORBA_ConstructionPolicy_Proxy_Broker;
class _TAO_CORBA_ConstructionPolicy_Remote_Proxy_Broker;

class TAO_Export CORBA_ConstructionPolicy: public virtual CORBA_Policy
{
public:
#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef CORBA_ConstructionPolicy_ptr _ptr_type;
  typedef CORBA_ConstructionPolicy_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

  // the static operations
  static CORBA_ConstructionPolicy_ptr _duplicate (CORBA_ConstructionPolicy_ptr obj);
  static CORBA_ConstructionPolicy_ptr _narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_ConstructionPolicy_ptr _unchecked_narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_ConstructionPolicy_ptr _nil (void)
    {
      return (CORBA_ConstructionPolicy_ptr)0;
    }

  static void _tao_any_destructor (void*);

  virtual void make_domain_manager (
      CORBA_InterfaceDef_ptr object_type,
      CORBA::Boolean constr_policy,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual CORBA::Boolean _is_a (
      const CORBA::Char *type_id,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual void *_tao_QueryInterface (ptr_arith_t type);

  virtual const char* _interface_repository_id (void) const;

private:
  _TAO_CORBA_ConstructionPolicy_Proxy_Broker *the_TAO_CORBA_ConstructionPolicy_Proxy_Broker_;

protected:
  CORBA_ConstructionPolicy (int collocated = 0);

  protected:
    // This methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode
    virtual void CORBA_ConstructionPolicy_setup_collocation (int collocated);

    CORBA_ConstructionPolicy (
      TAO_Stub *objref,
      CORBA::Boolean _tao_collocated = 0,
      TAO_Abstract_ServantBase *servant = 0
      );

    friend class _TAO_CORBA_ConstructionPolicy_Remote_Proxy_Impl;
    friend class _TAO_CORBA_ConstructionPolicy_ThruPOA_Proxy_Impl;
    friend class _TAO_CORBA_ConstructionPolicy_Direct_Proxy_Impl;

  virtual ~CORBA_ConstructionPolicy (void);
private:
  CORBA_ConstructionPolicy (const CORBA_ConstructionPolicy &);
  void operator= (const CORBA_ConstructionPolicy &);
};


// The Proxy Implementations are used by each interface to
// perform a call. Each different implementation encapsulate
// an invocation logics.


///////////////////////////////////////////////////////////////////////
//                    Base  Impl. Declaration
//

class TAO_Export _TAO_CORBA_ConstructionPolicy_Proxy_Impl :
  public virtual CORBA_TAO_Policy_Proxy_Impl
{
public:
  virtual ~_TAO_CORBA_ConstructionPolicy_Proxy_Impl (void) { }

    virtual void make_domain_manager (
      CORBA::Object_ptr _collocated_tao_target_,
      CORBA_InterfaceDef_ptr object_type,
      CORBA::Boolean constr_policy,
      CORBA::Environment &ACE_TRY_ENV
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

protected:
  _TAO_CORBA_ConstructionPolicy_Proxy_Impl (void);

};
//
//                Base  Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                    Remote  Impl. Declaration
//

class TAO_Export _TAO_CORBA_ConstructionPolicy_Remote_Proxy_Impl :
  public virtual _TAO_CORBA_ConstructionPolicy_Proxy_Impl,
  public virtual TAO_Remote_Object_Proxy_Impl,
  public virtual CORBA_TAO_Policy_Remote_Proxy_Impl

{
public:
  _TAO_CORBA_ConstructionPolicy_Remote_Proxy_Impl (void);

  virtual ~_TAO_CORBA_ConstructionPolicy_Remote_Proxy_Impl (void) { }

  virtual void make_domain_manager (
      CORBA::Object_ptr _collocated_tao_target_,
      CORBA_InterfaceDef_ptr object_type,
      CORBA::Boolean constr_policy,
      CORBA::Environment &ACE_TRY_ENV
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

};

//
//                Base  Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////


// The Proxy Brokers are used by each interface to get
// the right proxy for performing a call. In the new
// collocation scheme, the proxy to be used can vary on
// a call by call basis.



///////////////////////////////////////////////////////////////////////
//                 Base Proxy Broker Declaration
//

class TAO_Export _TAO_CORBA_ConstructionPolicy_Proxy_Broker
{
public:
  virtual ~_TAO_CORBA_ConstructionPolicy_Proxy_Broker (void);
  virtual _TAO_CORBA_ConstructionPolicy_Proxy_Impl &select_proxy (
    CORBA_ConstructionPolicy *object,
    CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
  ) = 0;

protected:
  _TAO_CORBA_ConstructionPolicy_Proxy_Broker (void);

};

//
//              End Base Proxy Broker Declaration
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                 Remote Proxy Broker Declaration
//

class TAO_Export _TAO_CORBA_ConstructionPolicy_Remote_Proxy_Broker : public virtual _TAO_CORBA_ConstructionPolicy_Proxy_Broker
{
public:
  _TAO_CORBA_ConstructionPolicy_Remote_Proxy_Broker (void);

  virtual ~_TAO_CORBA_ConstructionPolicy_Remote_Proxy_Broker (void);

  virtual _TAO_CORBA_ConstructionPolicy_Proxy_Impl &select_proxy (
    CORBA_ConstructionPolicy *object,
    CORBA_Environment &ACE_TRY_ENV
  );

private:
  _TAO_CORBA_ConstructionPolicy_Remote_Proxy_Impl remote_proxy_impl_;
// This member function is used to get an handle to the unique instance
// of the Remote Proxy Broker that is available for a given
// interface.

public:
  static _TAO_CORBA_ConstructionPolicy_Remote_Proxy_Broker *the_TAO_CORBA_ConstructionPolicy_Remote_Proxy_Broker (void);
};


//
//              End Remote Proxy Broker Declaration
///////////////////////////////////////////////////////////////////////


#endif /* end #if !defined */

TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_CORBA_ConstructionPolicy;


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_OBJECT_SEQUENCE_CORBA_DOMAINMANAGERLIST_CH_)
#define __TAO_UNBOUNDED_OBJECT_SEQUENCE_CORBA_DOMAINMANAGERLIST_CH_

  class _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList : public TAO_Unbounded_Base_Sequence
  {
  public:
    // = Initialization and termination methods.

    _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList (void);
    _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList (CORBA::ULong maximum);
    _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList (CORBA::ULong maximum,
      CORBA::ULong length,
      CORBA_DomainManager* *value,
      CORBA::Boolean release = 0);
    _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList(const _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList &rhs);
    virtual ~_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList (void);
    _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList &operator= (const _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList &rhs);
    TAO_Object_Manager<CORBA_DomainManager,CORBA_DomainManager_var> operator[] (CORBA::ULong index) const;
    static CORBA_DomainManager **allocbuf (CORBA::ULong nelems);
    static void freebuf (CORBA_DomainManager **buffer);
    // The Base_Sequence functions, please see tao/Sequence.h
    virtual void _allocate_buffer (CORBA::ULong length);
    virtual void _deallocate_buffer (void);
    CORBA_DomainManager* *get_buffer (CORBA::Boolean orphan = 0);
    const CORBA_DomainManager* *get_buffer (void) const;
    virtual void _shrink_buffer (CORBA::ULong nl, CORBA::ULong ol);
    virtual void _downcast (
        void* target,
        CORBA_Object *src,
        CORBA_Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );
    virtual CORBA_Object* _upcast (void *src) const;

  };

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_CORBA_DOMAINMANAGERLIST_CH_)
#define _CORBA_DOMAINMANAGERLIST_CH_

class CORBA_DomainManagerList;
class CORBA_DomainManagerList_var;

// *************************************************************
// CORBA_DomainManagerList
// *************************************************************

class TAO_Export CORBA_DomainManagerList : public
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Object_Sequence<CORBA_DomainManager,CORBA_DomainManager_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
{
public:
  CORBA_DomainManagerList (void); // default ctor
  CORBA_DomainManagerList (CORBA::ULong max); // uses max size
  CORBA_DomainManagerList (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA_DomainManager_ptr *buffer,
    CORBA::Boolean release = 0
  );
  CORBA_DomainManagerList (const CORBA_DomainManagerList &); // copy ctor
  ~CORBA_DomainManagerList (void);
  static void _tao_any_destructor (void*);

#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef CORBA_DomainManagerList_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

};

#endif /* end #if !defined */


#if !defined (_CORBA_DOMAINMANAGERLIST___VAR_CH_)
#define _CORBA_DOMAINMANAGERLIST___VAR_CH_

// *************************************************************
// class CORBA_DomainManagerList_var
// *************************************************************

class TAO_Export CORBA_DomainManagerList_var
{
public:
  CORBA_DomainManagerList_var (void); // default constructor
  CORBA_DomainManagerList_var (CORBA_DomainManagerList *);
  CORBA_DomainManagerList_var (const CORBA_DomainManagerList_var &); // copy constructor
  ~CORBA_DomainManagerList_var (void); // destructor

  CORBA_DomainManagerList_var &operator= (CORBA_DomainManagerList *);
  CORBA_DomainManagerList_var &operator= (const CORBA_DomainManagerList_var &);
  CORBA_DomainManagerList *operator-> (void);
  const CORBA_DomainManagerList *operator-> (void) const;

  operator const CORBA_DomainManagerList &() const;
  operator CORBA_DomainManagerList &();
  operator CORBA_DomainManagerList &() const;
  operator CORBA_DomainManagerList *&(); // variable-size base types only

  TAO_Object_Manager<CORBA_DomainManager, CORBA_DomainManager_var> operator[] (CORBA::ULong index);

  // in, inout, out, _retn
  const CORBA_DomainManagerList &in (void) const;
  CORBA_DomainManagerList &inout (void);
  CORBA_DomainManagerList *&out (void);
  CORBA_DomainManagerList *_retn (void);
  CORBA_DomainManagerList *ptr (void) const;

private:
  CORBA_DomainManagerList *ptr_;
};


#endif /* end #if !defined */


#if !defined (_CORBA_DOMAINMANAGERLIST___OUT_CH_)
#define _CORBA_DOMAINMANAGERLIST___OUT_CH_

class TAO_Export CORBA_DomainManagerList_out
{
public:
  CORBA_DomainManagerList_out (CORBA_DomainManagerList *&);
  CORBA_DomainManagerList_out (CORBA_DomainManagerList_var &);
  CORBA_DomainManagerList_out (const CORBA_DomainManagerList_out &);
  CORBA_DomainManagerList_out &operator= (const CORBA_DomainManagerList_out &);
  CORBA_DomainManagerList_out &operator= (CORBA_DomainManagerList *);
  operator CORBA_DomainManagerList *&();
  CORBA_DomainManagerList *&ptr (void);
  CORBA_DomainManagerList *operator-> (void);
  TAO_Object_Manager<CORBA_DomainManager, CORBA_DomainManager_var> operator[] (CORBA::ULong index);

private:
  CORBA_DomainManagerList *&ptr_;
  // assignment from T_var not allowed
  void operator= (const CORBA_DomainManagerList_var &);
};


#endif /* end #if !defined */

TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_CORBA_DomainManagerList;



// Proxy Broker Factory function pointer declarations.

extern TAO_Export
_TAO_CORBA_DomainManager_Proxy_Broker *
(*CORBA__TAO_CORBA_DomainManager_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );

extern TAO_Export
_TAO_CORBA_ConstructionPolicy_Proxy_Broker *
(*CORBA__TAO_CORBA_ConstructionPolicy_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );

// Any operators for interface CORBA_DomainManager
TAO_Export void operator<<= (CORBA::Any &, CORBA_DomainManager_ptr);
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA_DomainManager *&);
// Any operators for interface CORBA_ConstructionPolicy
TAO_Export void operator<<= (CORBA::Any &, CORBA_ConstructionPolicy_ptr);
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA_ConstructionPolicy *&);
TAO_Export void operator<<= (CORBA::Any &, const CORBA_DomainManagerList &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA_DomainManagerList*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA_DomainManagerList *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA_DomainManagerList *&);

#ifndef __ACE_INLINE__

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA_DomainManager_ptr );
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA_DomainManager_ptr &);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA_ConstructionPolicy_ptr );
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA_ConstructionPolicy_ptr &);

#if !defined _TAO_CDR_OP_CORBA_DomainManagerList_H_
#define _TAO_CDR_OP_CORBA_DomainManagerList_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA_DomainManagerList &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA_DomainManagerList &
  );

#endif /* _TAO_CDR_OP_CORBA_DomainManagerList_H_ */


#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "DomainC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */
