//
// $Id$
//
// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_exception.cpp
//
// = DESCRIPTION
//    Extension of class AST_Exception that provides additional means for C++
//    mapping of an interface.
//
// = AUTHOR
//    Copyright 1994-1995 by Sun Microsystems, Inc.
//    and
//    Aniruddha Gokhale
//
// ============================================================================


#include	"idl.h"
#include	"idl_extern.h"
#include	"be.h"

/*
 * BE_Exception
 */
be_exception::be_exception (void)
{
  this->size_type (be_decl::VARIABLE); // always the case
}

be_exception::be_exception (UTL_ScopedName *n, UTL_StrList *p)
	    : AST_Decl (AST_Decl::NT_except, n, p),
              AST_Structure (AST_Decl::NT_except, n, p),
	      UTL_Scope (AST_Decl::NT_except),
              member_count_ (-1)
{
  this->size_type (be_decl::VARIABLE); // always the case
}

// compute total number of members
int
be_exception::compute_member_count (void)
{
  UTL_ScopeActiveIterator *si;  // iterator

  this->member_count_ = 0;

  // if there are elements in this scope
  if (this->nmembers () > 0)
    {
      // instantiate a scope iterator.
      si = new UTL_ScopeActiveIterator (this, UTL_Scope::IK_decls);

      while (!(si->is_done ()))
        {
          // get the next AST decl node
          this->member_count_++;
          si->next ();
        } // end of while
      delete si; // free the iterator object
    }
  return 0;
}

// return the member count
int
be_exception::member_count (void)
{
  if (this->member_count_ == -1)
    this->compute_member_count ();

  return this->member_count_;
}

int
be_exception::gen_client_header (void)
{
  if (!this->cli_hdr_gen_) // not already generated
    {
      TAO_CodeGen *cg = TAO_CODEGEN::instance ();

      TAO_OutStream *ch = cg->client_header (); // output stream
      TAO_NL  nl;        // end line


      ch->indent (); // start from whatever indentation level we were at

      ch->gen_ifdef_macro (this->flatname (), "_ptr");

      ch->indent ();
      *ch << "class " << this->local_name () << ";" << nl;
      // generate the _ptr declaration
      *ch << "typedef " << this->local_name () << " *"
	  << this->local_name () << "_ptr;" << nl;
      ch->gen_endif ();

      ch->gen_ifdef_macro (this->flatname ());

      ch->indent ();
      *ch << "class " << this->local_name ()
	  << " : public virtual CORBA::UserException" << nl;
      *ch << "{" << nl
	  << "public:" << nl;
      ch->incr_indent ();
      *ch << this->local_name () << " (void);\n";
      ch->decr_indent ();
      *ch << "};" << nl << nl;
      ch->gen_endif ();

      *ch << "static CORBA::TypeCode_ptr " << this->tc_name
	()->last_component () << ";\n\n";

      this->cli_hdr_gen_ = I_TRUE;
    }

  return 0;
}

int
be_exception::gen_client_inline (void)
{
  if (!this->cli_inline_gen_)
    {
      TAO_NL  nl;        // end line

      TAO_CodeGen *cg = TAO_CODEGEN::instance ();
      TAO_OutStream *ci = cg->client_inline ();

      *ci << "// *************************************************************"
          << nl;
      *ci << "// Inline operations for exception " << this->name () << nl;
      *ci << "// *************************************************************\n\n";

      ci->indent ();
      *ci << "// default constructor" << nl;
      *ci << "ACE_INLINE" << nl;
      *ci << this->name () << "::" << this->local_name () << " (void)" << nl;
      ci->incr_indent ();
      *ci << ": CORBA_UserException (_tc_"
	  << this->local_name ()
	  << ")\n";
      ci->decr_indent ();
      *ci << "{" << nl;
      *ci << "}" << nl << nl;

      this->cli_inline_gen_ = I_TRUE;
    }
  return 0;
}

int
be_exception::gen_client_stubs (void)
{
  TAO_OutStream *cs; // output stream
  TAO_NL  nl;        // end line


  if (!this->cli_stub_gen_)
    {
      // retrieve a singleton instance of the code generator
      TAO_CodeGen *cg = TAO_CODEGEN::instance ();
      cg->push (TAO_CodeGen::TAO_STRUCT_CS); // set current code gen state

      cs = cg->client_stubs ();

      // generate the typecode information here
      cs->indent (); // start from current indentation level
      *cs << "static const CORBA::Long _oc_" << this->flatname () << "[] =" <<
        nl;
      *cs << "{\n";
      cs->incr_indent (0);
      // note that we just need the parameters here and hence we generate the
      // encapsulation for the parameters
      if (this->gen_encapsulation () == -1)
        {
          ACE_ERROR ((LM_ERROR, "Error generating encapsulation\n\n"));
          return -1;
        }
      cs->decr_indent ();
      *cs << "};" << nl;

      *cs << "static CORBA::TypeCode _tc__tc_" << this->flatname () <<
        " (CORBA::tk_struct, sizeof (_oc_" <<  this->flatname () <<
        "), (unsigned char *) &_oc_" << this->flatname () <<
        ", CORBA::B_FALSE);" << nl;
      *cs << "CORBA::TypeCode_ptr " << this->tc_name () << " = &_tc__tc_" <<
        this->flatname () << ";\n\n";
      this->cli_stub_gen_ = I_TRUE;
      cg->pop ();
    }

  return 0;
}

int
be_exception::gen_server_header (void)
{
  return 0;
}

int
be_exception::gen_server_inline (void)
{
  return 0;
}

int
be_exception::gen_server_skeletons (void)
{
  return 0;
}

// generate typecode.
// Typecode for exceptions comprises the enumerated value followed by the
// encapsulation of the parameters

int
be_exception::gen_typecode (void)
{
  TAO_OutStream *cs; // output stream
  TAO_NL  nl;        // end line
  TAO_CodeGen *cg = TAO_CODEGEN::instance ();

  cs = cg->client_stubs ();
  cs->indent (); // start from whatever indentation level we were at

  *cs << "CORBA::tk_except, // typecode kind" << nl;
  *cs << this->tc_size () << ", // encapsulation length\n";
  // now emit the encapsulation
  return this->gen_encapsulation ();
}

// generate encapsulation
// An encapsulation for ourselves will be necessary when we are part of some
// other IDL type and a typecode for that other type is being generated. This
// will comprise our typecode kind. IDL types with parameters will additionally
// have the encapsulation length and the entire typecode description
int
be_exception::gen_encapsulation (void)
{
  TAO_OutStream *cs; // output stream
  TAO_NL  nl;        // end line
  TAO_CodeGen *cg = TAO_CODEGEN::instance ();
  long i, arrlen;
  long *arr;  // an array holding string names converted to array of longs

  cs = cg->client_stubs ();
  cs->indent (); // start from whatever indentation level we were at

  // XXXASG - byte order must be based on what m/c we are generating code -
  // TODO
  *cs << "0, // byte order" << nl;
  // generate repoID
  *cs << (ACE_OS::strlen (this->repoID ())+1) << ", ";
  (void)this->tc_name2long (this->repoID (), arr, arrlen);
  for (i=0; i < arrlen; i++)
    {
      cs->print ("0x%x, ", arr[i]);
    }
  *cs << " // repository ID = " << this->repoID () << nl;
  // generate name
  *cs << (ACE_OS::strlen (this->local_name ()->get_string ())+1) << ", ";
  (void)this->tc_name2long(this->local_name ()->get_string (), arr, arrlen);
  for (i=0; i < arrlen; i++)
    {
      cs->print ("0x%x, ", arr[i]);
    }
  *cs << " // name = " << this->local_name () << nl;
  // generate the member count
  *cs << this->member_count () << ", // member count\n";
  cs->incr_indent (0);
  // hand over to the scope to generate the typecode for elements
  if (be_scope::gen_encapsulation () == -1)
    {
      ACE_ERROR ((LM_ERROR, "be_exception: cannot generate typecode for members\n"));
      return -1;
    }
  cs->decr_indent (0);
  return 0;
}

// compute typecode size
long
be_exception::tc_size (void)
{
  // 4 bytes for enumeration, 4 bytes for storing encap length val, followed by the
  // actual encapsulation length
  return 4 + 4 + this->tc_encap_len ();
}

// compute encapsulation length
long
be_exception::tc_encap_len (void)
{
  if (this->encap_len_ == -1) // not computed yet
    {
      this->encap_len_ = 4;  // holds the byte order flag

      this->encap_len_ += this->repoID_encap_len (); // repoID

      // do the same thing for the local name
      this->encap_len_ += this->name_encap_len ();

      this->encap_len_ += 4; // to hold the member count

      // compute encap length for members
      this->encap_len_ += be_scope::tc_encap_len ();
    }
  return this->encap_len_;
}

// Narrowing
IMPL_NARROW_METHODS3 (be_exception, AST_Exception, be_scope, be_type)
IMPL_NARROW_FROM_DECL (be_exception)
IMPL_NARROW_FROM_SCOPE (be_exception)
