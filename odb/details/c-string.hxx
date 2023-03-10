// file      : odb/details/c-string.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_C_STRING_HXX
#define ODB_DETAILS_C_STRING_HXX

#ifdef _MSC_VER
  #include "../pre.hxx"
#endif

#include <cstring>

namespace odb
{
  namespace details
  {
    struct c_string_comparator
    {
      bool
      operator() (const char* x, const char* y) const
      {
        return std::strcmp (x, y) < 0;
      }
    };
  }
}

#ifdef _MSC_VER
  #include "../post.hxx"
#endif

#endif // ODB_DETAILS_C_STRING_HXX
