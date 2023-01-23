// file      : odb/details/lock.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_LOCK_HXX
#define ODB_DETAILS_LOCK_HXX

#ifdef _MSC_VER
  #include "../pre.hxx"
#endif

#include "mutex.hxx"

#ifdef ODB_THREADS_CXX11
#  include <mutex>
namespace odb
{
  namespace details
  {
    using lock = std::unique_lock<mutex>;
  }
}
#else
namespace odb
{
  namespace details
  {
    class lock
    {
    public:
      lock (mutex& m)
          : mutex_ (&m)
      {
        mutex_->lock ();
      }

      ~lock ()
      {
        if (mutex_ != 0)
          mutex_->unlock ();
      }

      void
      unlock ()
      {
        if (mutex_ != 0)
        {
          mutex_->unlock ();
          mutex_ = 0;
        }
      }

    private:
      mutex* mutex_;
    };
  }
}
#endif

#ifdef _MSC_VER
  #include "../post.hxx"
#endif

#endif // ODB_DETAILS_LOCK_HXX
