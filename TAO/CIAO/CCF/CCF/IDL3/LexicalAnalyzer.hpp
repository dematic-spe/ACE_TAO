// file      : CCF/IDL3/LexicalAnalyzer.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $id$

#ifndef CCF_IDL3_LEXICAL_ANALYZER_HPP
#define CCF_IDL3_LEXICAL_ANALYZER_HPP

#include "CCF/IDL2/LexicalAnalyzer.hpp"

namespace CCF
{
  namespace IDL3
  {
    class LexicalAnalyzer : public virtual IDL2::LexicalAnalyzer
    {
    public:
      LexicalAnalyzer (TokenStream<char>& is);
    };
  }
}

#endif  // CCF_IDL3_LEXICAL_ANALYZER_HPP
