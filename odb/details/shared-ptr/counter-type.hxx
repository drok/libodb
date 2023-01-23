// file      : odb/details/shared-ptr/counter-type.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_SHARED_PTR_COUNTER_TYPE_HXX
#define ODB_DETAILS_SHARED_PTR_COUNTER_TYPE_HXX

#ifdef _MSC_VER
  #include "../../pre.hxx"
#endif

namespace odb
{
  namespace details
  {
    template <typename X>
    struct counter_type
    {
      typedef X counter;
    };
  }
}

#ifdef _MSC_VER
  #include "../../post.hxx"
#endif

#endif // ODB_DETAILS_SHARED_PTR_COUNTER_TYPE_HXX
