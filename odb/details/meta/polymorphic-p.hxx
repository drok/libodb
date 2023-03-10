// file      : odb/details/meta/polymorphic-p.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_META_POLYMORPHIC_HXX
#define ODB_DETAILS_META_POLYMORPHIC_HXX

#ifdef _MSC_VER
  #include "../../pre.hxx"
#endif

#include "../config.hxx" // ODB_NOTHROW_NOEXCEPT
#include "class-p.hxx"
#include "remove-const-volatile.hxx"

namespace odb
{
  namespace details
  {
    namespace meta
    {
      template <typename CVX>
      struct polymorphic_p
      {
        typedef typename remove_const_volatile<CVX>::result X;

        template <typename Y, bool C>
        struct impl
        {
          static const bool result = false;
        };

        template <typename Y>
        struct impl<Y, true>
        {
          struct t1: Y
          {
            t1 ();
          };

          struct t2: Y
          {
            t2 ();

            virtual
            ~t2 () ODB_NOTHROW_NOEXCEPT;
          };

          static const bool result = sizeof (t1) == sizeof (t2);
        };

        static const bool result = impl<X, class_p<X>::result>::result;
      };
    }
  }
}

#ifdef _MSC_VER
  #include "../../post.hxx"
#endif

#endif // ODB_DETAILS_META_POLYMORPHIC_HXX
