// file      : CCF/IDL3/SemanticAction/Consumes.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $id$

#ifndef CCF_IDL3_SEMANTIC_ACTION_CONSUMES_HPP
#define CCF_IDL3_SEMANTIC_ACTION_CONSUMES_HPP

#include "CCF/IDL3/SemanticAction/Elements.hpp"

namespace CCF
{
  namespace IDL3
  {
    namespace SemanticAction
    {
      //
      //
      //
      class Consumes
      {
      public:
        virtual
        ~Consumes () throw () {}
        
        virtual void
        type (IdentifierPtr const& id) = 0;
        
        virtual void
        name (SimpleIdentifierPtr const& id) = 0;
      };
    }
  }
}

#endif  // CCF_IDL3_SEMANTIC_ACTION_CONSUMES_HPP
