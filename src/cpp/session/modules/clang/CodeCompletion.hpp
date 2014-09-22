/*
 * CodeCompletion.hpp
 *
 * Copyright (C) 2009-12 by RStudio, Inc.
 *
 * Unless you have received this program directly from RStudio pursuant
 * to the terms of a commercial license agreement with RStudio, then
 * this program is licensed to you under the terms of version 3 of the
 * GNU Affero General Public License. This program is distributed WITHOUT
 * ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF NON-INFRINGEMENT,
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. Please refer to the
 * AGPL (http://www.gnu.org/licenses/agpl-3.0.txt) for more details.
 *
 */

#ifndef SESSION_MODULES_CLANG_CODE_COMPLETION_HPP
#define SESSION_MODULES_CLANG_CODE_COMPLETION_HPP

#include <boost/noncopyable.hpp>

#include "Clang.hpp"
#include "Diagnostic.hpp"

namespace session {
namespace modules {      
namespace clang {

class CodeCompleteResults : boost::noncopyable
{
public:
   explicit CodeCompleteResults(CXCodeCompleteResults* pResults)
      : pResults_(pResults)
   {
   }

   ~CodeCompleteResults();

   void sort();

   unsigned getNumDiagnostics() const;
   boost::shared_ptr<Diagnostic> getDiagnostic(unsigned index) const;

   unsigned long long getContexts() const;


private:
   CXCodeCompleteResults* pResults_;
};


boost::shared_ptr<CodeCompleteResults> codeCompleteAt(
                                                  const std::string& filename,
                                                  unsigned line,
                                                  unsigned column);



} // namespace clang
} // namepace handlers
} // namesapce session

#endif // SESSION_MODULES_CLANG_CODE_COMPLETION_HPP
