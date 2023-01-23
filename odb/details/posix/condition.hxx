// file      : odb/details/posix/condition.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_POSIX_CONDITION_HXX
#define ODB_DETAILS_POSIX_CONDITION_HXX

#include "../../pre.hxx"

#include <pthread.h>

#include "../export.hxx"
#include "mutex.hxx"

namespace odb
{
  namespace details
  {
    class lock;

    class LIBODB_EXPORT condition
    {
    public:
      ~condition ();
      condition (mutex&);

      void
      signal ();

      void
      wait (lock&);

    private:
      condition (const condition&);
      condition& operator= (const condition&);

    private:
      mutex& mutex_;
      pthread_cond_t cond_;
    };
  }
}

#include "condition.ixx"

#include "../../post.hxx"

#endif // ODB_DETAILS_POSIX_CONDITION_HXX
