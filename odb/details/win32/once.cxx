// file      : odb/details/win32/once.cxx
// license   : GNU GPL v2; see accompanying LICENSE file

#include "windows.hxx"
#include "once.hxx"
#include "once-init.hxx"

namespace odb
{
  namespace details
  {
    CRITICAL_SECTION win32_once_cs_;

    void
    once_process_start ()
    {
      InitializeCriticalSection (&win32_once_cs_);
    }

    void
    once_process_end (bool)
    {
      DeleteCriticalSection (&win32_once_cs_);
    }
  }
}
