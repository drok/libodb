// file      : odb/details/posix/thread.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_POSIX_THREAD_HXX
#define ODB_DETAILS_POSIX_THREAD_HXX

#ifdef _MSC_VER
  #include "../../pre.hxx"
#endif

#include <pthread.h>

#include "../export.hxx"

namespace odb
{
  namespace details
  {
    class LIBODB_EXPORT thread
    {
    public:
      ~thread ();
      thread (void* (*thread_func) (void*), void* arg = 0);

      void*
      join ();

    private:
      thread (const thread&);
      thread& operator= (const thread&);

    private:
      bool detached_;
      pthread_t id_;
    };
  }
}

#include "thread.ixx"

#ifdef _MSC_VER
  #include "../../post.hxx"
#endif

#endif // ODB_DETAILS_POSIX_THREAD_HXX
