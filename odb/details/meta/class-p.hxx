// file      : odb/details/meta/class-p.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_META_CLASS_HXX
#define ODB_DETAILS_META_CLASS_HXX

#ifdef _MSC_VER
  #include "../../pre.hxx"
#endif

#include "answer.hxx"

namespace odb
{
  namespace details
  {
    namespace meta
    {
      // g++ cannot have these inside class_p.
      //
      template <typename X> no class_p_test (...);
      template <typename X> yes class_p_test (void (X::*) ());

      template <typename X>
      struct class_p
      {
        static const bool result =
          sizeof (class_p_test<X> (0)) == sizeof (yes);
      };
    }
  }
}

#ifdef _MSC_VER
  #include "../../post.hxx"
#endif

#endif // ODB_DETAILS_META_CLASS_HXX
