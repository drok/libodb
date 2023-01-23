// file      : odb/exception.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_EXCEPTION_HXX
#define ODB_EXCEPTION_HXX

#ifdef _MSC_VER
  #include "pre.hxx"
#endif

#include <exception>

#include "forward.hxx"        // odb::core

#include "details/config.hxx" // ODB_NOTHROW_NOEXCEPT
#include "details/export.hxx"
#include "details/shared-ptr/base.hxx"

namespace odb
{
  struct LIBODB_EXPORT exception: std::exception, details::shared_base
  {
    virtual const char*
    what () const ODB_NOTHROW_NOEXCEPT = 0;

    virtual exception*
    clone () const = 0;
  };

  namespace common
  {
    using odb::exception;
  }
}

#ifdef _MSC_VER
  #include "post.hxx"
#endif

#endif // ODB_EXCEPTION_HXX
