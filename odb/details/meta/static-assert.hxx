// file      : odb/details/meta/static-assert.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_META_STATIC_ASSERT_HXX
#define ODB_DETAILS_META_STATIC_ASSERT_HXX

#ifdef _MSC_VER
  #include "../../pre.hxx"
#endif

#include "../config.hxx" // ODB_CXX11

#ifndef ODB_CXX11

namespace odb
{
  namespace details
  {
    namespace meta
    {
      template <bool>
      struct static_assert_test;

      template <>
      struct static_assert_test<true> {};
    }
  }
}

#endif

#ifdef _MSC_VER
  #include "../../post.hxx"
#endif

#endif // ODB_DETAILS_META_STATIC_ASSERT_HXX
