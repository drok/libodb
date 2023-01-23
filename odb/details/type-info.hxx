// file      : odb/details/type-info.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_TYPE_INFO_HXX
#define ODB_DETAILS_TYPE_INFO_HXX

#ifdef _MSC_VER
  #include "../pre.hxx"
#endif

#include <typeinfo>

namespace odb
{
  namespace details
  {
    struct type_info_comparator
    {
      bool
      operator() (const std::type_info* x, const std::type_info* y) const
      {
        // XL C++ on AIX has buggy type_info::before() in that
        // it returns true for two different type_info objects
        // that happened to be for the same type.
        //
#if defined(__xlC__) && defined(_AIX)
        return *x != *y && x->before (*y);
#else
        return x->before (*y);
#endif
      }
    };
  }
}

#ifdef _MSC_VER
  #include "../post.hxx"
#endif

#endif // ODB_DETAILS_TYPE_INFO_HXX
