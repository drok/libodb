// file      : odb/details/meta/remove-const.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_META_REMOVE_CONST_HXX
#define ODB_DETAILS_META_REMOVE_CONST_HXX

#ifdef _MSC_VER
  #include "../../pre.hxx"
#endif

namespace odb
{
  namespace details
  {
    namespace meta
    {
      template <typename X>
      struct remove_const
      {
        typedef X result;
      };

      template <typename X>
      struct remove_const<const X>
      {
        typedef X result;
      };
    }
  }
}

#ifdef _MSC_VER
  #include "../../post.hxx"
#endif

#endif // ODB_DETAILS_META_REMOVE_CONST_HXX
