// Copyright (c) 2005-2022 Jay Berkenbilt
//
// This file is part of qpdf.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Versions of qpdf prior to version 7 were released under the terms
// of version 2.0 of the Artistic License. At your option, you may
// continue to consider qpdf to be licensed under those terms. Please
// see the manual for additional information.

// End-of-line pipeline that simply writes its data to a stdio FILE* object.

#ifndef PL_STRING_HH
#define PL_STRING_HH

#include <qpdf/Pipeline.hh>

#include <string>

class QPDF_DLL_CLASS Pl_String: public Pipeline
{
  public:
    QPDF_DLL
    Pl_String(char const* identifier, std::string& s);
    QPDF_DLL
    virtual ~Pl_String();

    QPDF_DLL
    virtual void write(unsigned char const* buf, size_t len);
    QPDF_DLL
    virtual void finish();

  private:
    class QPDF_DLL_PRIVATE Members
    {
        friend class Pl_String;

      public:
        QPDF_DLL
        ~Members() = default;

      private:
        Members(std::string&);
        Members(Members const&) = delete;

        std::string& s;
    };

    std::shared_ptr<Members> m;
};

#endif // PL_STRING_HH