// file      : odb/details/exception.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_EXCEPTION_HXX
#define ODB_DETAILS_EXCEPTION_HXX

#ifdef _MSC_VER
  #include "../pre.hxx"
#endif

#include "../exception.hxx"

namespace odb
{
  namespace details
  {
    struct exception: odb::exception {};
  }
}

#ifdef _MSC_VER
  #include "../post.hxx"
#endif

#endif // ODB_DETAILS_EXCEPTION_HXX
