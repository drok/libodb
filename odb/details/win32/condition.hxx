// file      : odb/details/win32/condition.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_WIN32_CONDITION_HXX
#define ODB_DETAILS_WIN32_CONDITION_HXX

#include "../../pre.hxx"

#include "windows.hxx"

#include <cstddef> // std::size_t

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
      HANDLE event_;

      std::size_t waiters_;
      std::size_t signals_;
    };
  }
}

#include "condition.ixx"

#include "../../post.hxx"

#endif // ODB_DETAILS_WIN32_CONDITION_HXX
