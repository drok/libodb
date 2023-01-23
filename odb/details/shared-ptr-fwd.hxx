// file      : odb/details/shared-ptr-fwd.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_SHARED_PTR_FWD_HXX
#define ODB_DETAILS_SHARED_PTR_FWD_HXX

#ifdef _MSC_VER
  #include "../pre.hxx"
#endif

#include "shared-ptr/counter-type.hxx"

namespace odb
{
  namespace details
  {
    template <typename X>
    class shared_ptr;

    class shared_base;
  }
}

#ifdef _MSC_VER
  #include "../post.hxx"
#endif

#endif // ODB_DETAILS_SHARED_PTR_FWD_HXX
