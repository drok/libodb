// file      : odb/details/meta/remove-const-volatile.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_META_REMOVE_CONST_VOLATILE_HXX
#define ODB_DETAILS_META_REMOVE_CONST_VOLATILE_HXX

#include "../../pre.hxx"

#include "remove-const.hxx"
#include "remove-volatile.hxx"

namespace odb
{
  namespace details
  {
    namespace meta
    {
      template <typename X>
      struct remove_const_volatile
      {
        typedef
        typename remove_volatile<typename remove_const<X>::result>::result
        result;
      };
    }
  }
}

#include "../../post.hxx"

#endif // ODB_DETAILS_META_REMOVE_CONST_VOLATILE_HXX
