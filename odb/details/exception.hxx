// file      : odb/details/exception.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_EXCEPTION_HXX
#define ODB_DETAILS_EXCEPTION_HXX

#include "../pre.hxx"

#include "../exception.hxx"

namespace odb
{
  namespace details
  {
    struct exception: odb::exception {};
  }
}

#include "../post.hxx"

#endif // ODB_DETAILS_EXCEPTION_HXX
