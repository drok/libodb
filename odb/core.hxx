// file      : odb/core.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_CORE_HXX
#define ODB_CORE_HXX

#include "pre.hxx"

#ifdef ODB_COMPILER
#  define PRAGMA_DB_IMPL(x) _Pragma (#x)
#  define PRAGMA_DB(x) PRAGMA_DB_IMPL (db x)
#else
#  define PRAGMA_DB(x)
#endif

#include "forward.hxx"

#include "post.hxx"

#endif // ODB_CORE_HXX
