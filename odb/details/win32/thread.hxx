// file      : odb/details/win32/thread.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_WIN32_THREAD_HXX
#define ODB_DETAILS_WIN32_THREAD_HXX

#ifdef _MSC_VER
  #include "../../pre.hxx"
#endif

#include "windows.hxx"
#include "../export.hxx"
#include "mutex.hxx"

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
      typedef void* (*thread_func) (void*);

      struct data
      {
        thread_func func;
        void* arg;
        void* ret;

        // Thread-safe reference counter.
        //
        details::mutex mutex;
        unsigned char count;
      };


    public:
      static void
      thread_thunk (void*);

    private:
      HANDLE handle_;
      data* data_;
    };
  }
}

#ifdef _MSC_VER
  #include "../../post.hxx"
#endif

#endif // ODB_DETAILS_WIN32_THREAD_HXX
