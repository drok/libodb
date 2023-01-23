// file      : odb/details/win32/mutex.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_WIN32_MUTEX_HXX
#define ODB_DETAILS_WIN32_MUTEX_HXX

#include "../../pre.hxx"

#include "windows.hxx"
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
      CRITICAL_SECTION cs_;
    };
  }
}

#include "mutex.ixx"

#include "../../post.hxx"

#endif // ODB_DETAILS_WIN32_MUTEX_HXX
