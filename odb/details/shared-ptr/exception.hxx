// file      : odb/details/shared-ptr/exception.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_SHARED_PTR_EXCEPTION_HXX
#define ODB_DETAILS_SHARED_PTR_EXCEPTION_HXX

#ifdef _MSC_VER
  #include "../../pre.hxx"
#endif

#include "../../exception.hxx"

#include "../config.hxx" // ODB_NOTHROW_NOEXCEPT
#include "../export.hxx"

namespace odb
{
  namespace details
  {
    struct LIBODB_EXPORT not_shared: exception
    {
      virtual const char*
      what () const ODB_NOTHROW_NOEXCEPT;

      virtual not_shared*
      clone () const;
    };
  }
}

#ifdef _MSC_VER
  #include "../../post.hxx"
#endif

#endif // ODB_DETAILS_SHARED_PTR_EXCEPTION_HXX
