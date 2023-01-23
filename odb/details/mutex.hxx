// file      : odb/details/mutex.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_MUTEX_HXX
#define ODB_DETAILS_MUTEX_HXX

#ifdef _MSC_VER
  #include "../pre.hxx"
#endif

#include "config.hxx"

#ifdef ODB_THREADS_NONE

namespace odb
{
  namespace details
  {
    class mutex
    {
    public:
      mutex () {}

      void
      lock () {}

      void
      unlock () {}

    private:
      mutex (const mutex&);
      mutex& operator= (const mutex&);
    };
  }
}
#elif defined(ODB_THREADS_CXX11)
#  include <mutex>
namespace odb
{
  namespace details
  {
    using std::mutex;
  }
}
#elif defined(ODB_THREADS_POSIX)
#include "posix/mutex.hxx"
#elif defined(ODB_THREADS_WIN32)
#include "win32/mutex.hxx"
#else
# error unknown threading model
#endif

#ifdef _MSC_VER
  #include "../post.hxx"
#endif

#endif // ODB_DETAILS_MUTEX_HXX
