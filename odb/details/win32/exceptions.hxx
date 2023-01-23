// file      : odb/details/win32/exceptions.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_WIN32_EXCEPTIONS_HXX
#define ODB_DETAILS_WIN32_EXCEPTIONS_HXX

#ifdef _MSC_VER
  #include "../../pre.hxx"
#endif

#include "../config.hxx" // ODB_NOTHROW_NOEXCEPT
#include "../export.hxx"
#include "../exception.hxx"
#include "windows.hxx"

namespace odb
{
  namespace details
  {
    struct LIBODB_EXPORT win32_exception: details::exception
    {
      win32_exception () : code_ (GetLastError ()) {}
      win32_exception (DWORD code) : code_ (code) {}

      DWORD
      code () const {return code_;}

      virtual const char*
      what () const ODB_NOTHROW_NOEXCEPT;

      virtual win32_exception*
      clone () const;

    private:
      DWORD code_;
    };
  }
}

#ifdef _MSC_VER
  #include "../../post.hxx"
#endif

#endif // ODB_DETAILS_WIN32_EXCEPTIONS_HXX
