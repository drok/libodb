// file      : odb/details/posix/mutex.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_POSIX_MUTEX_HXX
#define ODB_DETAILS_POSIX_MUTEX_HXX

#ifdef _MSC_VER
  #include "../../pre.hxx"
#endif

#include <pthread.h>

#include "../export.hxx"

namespace odb
{
  namespace details
  {
    class LIBODB_EXPORT mutex
    {
    public:
      ~mutex ();
      mutex ();

      void
      lock ();

      void
      unlock ();

    private:
      mutex (const mutex&);
      mutex& operator= (const mutex&);

    private:
      friend class condition;
      pthread_mutex_t mutex_;
    };
  }
}

#include "mutex.ixx"

#ifdef _MSC_VER
  #include "../../post.hxx"
#endif

#endif // ODB_DETAILS_POSIX_MUTEX_HXX
