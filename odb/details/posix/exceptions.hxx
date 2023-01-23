// file      : odb/details/posix/exceptions.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_POSIX_EXCEPTIONS_HXX
#define ODB_DETAILS_POSIX_EXCEPTIONS_HXX

#include "../../pre.hxx"

#include "../config.hxx" // ODB_NOTHROW_NOEXCEPT
#include "../export.hxx"
#include "../exception.hxx"

namespace odb
{
  namespace details
  {
    struct LIBODB_EXPORT posix_exception: details::exception
    {
      posix_exception (int code) : code_ (code) {}

      int
      code () const {return code_;}

      virtual const char*
      what () const ODB_NOTHROW_NOEXCEPT;

      virtual posix_exception*
      clone () const;

    private:
      int code_;
    };
  }
}

#include "../../post.hxx"

#endif // ODB_DETAILS_POSIX_EXCEPTIONS_HXX
