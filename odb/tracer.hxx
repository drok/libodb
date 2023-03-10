// file      : odb/tracer.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_HXX
#define ODB_TRACER_HXX

#ifdef _MSC_VER
  #include "pre.hxx"
#endif

#include "forward.hxx"
#include "details/export.hxx"

namespace odb
{
  class LIBODB_EXPORT tracer
  {
  public:
    virtual
    ~tracer ();

    virtual void
    prepare (connection&, const statement&);

    virtual void
    execute (connection&, const statement&);

    virtual void
    execute (connection&, const char* statement) = 0;

    virtual void
    deallocate (connection&, const statement&);
  };
}

#ifdef _MSC_VER
  #include "post.hxx"
#endif

#endif // ODB_TRACER_HXX
