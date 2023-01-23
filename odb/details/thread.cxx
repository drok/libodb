// file      : odb/details/thread.cxx
// license   : GNU GPL v2; see accompanying LICENSE file

#include "thread.hxx"

// We might be compiled with ODB_THREADS_NONE.
//
#ifdef ODB_THREADS_CXX11

namespace odb
{
  namespace details
  {
    void thread::
    thunk (void* (*f) (void*), void* a, std::promise<void*> p)
    {
      p.set_value (f (a));
    }
  }
}

#endif
