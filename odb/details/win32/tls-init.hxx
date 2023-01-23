// file      : odb/details/win32/tls-init.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_WIN32_TLS_INIT_HXX
#define ODB_DETAILS_WIN32_TLS_INIT_HXX

#ifdef _MSC_VER
  #include "../../pre.hxx"
#endif

namespace odb
{
  namespace details
  {
    void
    tls_process_start ();

    void
    tls_process_end (bool safe);

    void
    tls_thread_end ();
  }
}

#ifdef _MSC_VER
  #include "../../post.hxx"
#endif

#endif // ODB_DETAILS_WIN32_TLS_INIT_HXX
