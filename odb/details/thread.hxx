// file      : odb/details/thread.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_THREAD_HXX
#define ODB_DETAILS_THREAD_HXX

#ifdef _MSC_VER
  #include "../pre.hxx"
#endif

#include "config.hxx"
#include "export.hxx"

#ifdef ODB_THREADS_NONE
# error no thread support available
#elif defined(ODB_THREADS_CXX11)
#  include <thread>
#  include <future>
#  include <utility> // move()

namespace odb
{
  namespace details
  {
    class LIBODB_EXPORT thread
    {
    public:
      thread (void* (*thread_func) (void*), void* arg = 0)
      {
        std::promise<void*> p;
        f_ = p.get_future ();
        t_ = std::thread (thunk, thread_func, arg, std::move (p));
      }

      void*
      join ()
      {
        f_.wait ();
        t_.join ();
        return f_.get ();
      }

      thread (const thread&) = delete;
      thread& operator= (const thread&) = delete;

    private:
      static void
      thunk (void* (*) (void*), void*, std::promise<void*>);

    private:
      std::thread t_;
      std::future<void*> f_;
    };
  }
}

#elif defined(ODB_THREADS_POSIX)
#include "posix/thread.hxx"
#elif defined(ODB_THREADS_WIN32)
#include "win32/thread.hxx"
#else
# error unknown threading model
#endif

#ifdef _MSC_VER
  #include "../post.hxx"
#endif

#endif // ODB_DETAILS_THREAD_HXX
