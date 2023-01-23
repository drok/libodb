// file      : odb/details/condition.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_CONDITION_HXX
#define ODB_DETAILS_CONDITION_HXX

#ifdef _MSC_VER
  #include "../pre.hxx"
#endif

#include "config.hxx"

#ifdef ODB_THREADS_NONE

namespace odb
{
  namespace details
  {
    class mutex;
    class lock;

    class condition
    {
    public:
      condition (mutex&) {}

      void
      signal () {}

      void
      wait (lock&) {}

    private:
      condition (const condition&);
      condition& operator= (const condition&);
    };
  }
}

#elif defined(ODB_THREADS_CXX11)
#  include <condition_variable>
#  include "mutex.hxx"
#  include "lock.hxx"

namespace odb
{
  namespace details
  {
    class condition: public std::condition_variable
    {
    public:
      condition (mutex&) {}

      void
      signal () {notify_one ();}
    };
  }
}

#elif defined(ODB_THREADS_POSIX)
#include "posix/condition.hxx"
#elif defined(ODB_THREADS_WIN32)
#include "win32/condition.hxx"
#else
# error unknown threading model
#endif

#ifdef _MSC_VER
  #include "../post.hxx"
#endif

#endif // ODB_DETAILS_CONDITION_HXX
