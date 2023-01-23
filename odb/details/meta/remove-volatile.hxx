// file      : odb/details/meta/remove-volatile.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_META_REMOVE_VOLATILE_HXX
#define ODB_DETAILS_META_REMOVE_VOLATILE_HXX

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
      struct remove_volatile
      {
        typedef X result;
      };

      template <typename X>
      struct remove_volatile<volatile X>
      {
        typedef X result;
      };
    }
  }
}

#ifdef _MSC_VER
  #include "../../post.hxx"
#endif

#endif // ODB_DETAILS_META_REMOVE_VOLATILE_HXX
