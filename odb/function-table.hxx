// file      : odb/function-table.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_FUNCTION_TABLE_HXX
#define ODB_FUNCTION_TABLE_HXX

#ifdef _MSC_VER
  #include "pre.hxx"
#endif

#include "forward.hxx"

namespace odb
{
  template <typename T, database_id DB>
  struct object_function_table_entry
  {
    typedef access::object_traits_impl<T, id_common> common_traits;

    object_function_table_entry (
      const typename common_traits::function_table_type* t)
    {
      common_traits::function_table[DB] = t;
    }

    ~object_function_table_entry ()
    {
      common_traits::function_table[DB] = 0;
    }
  };

  template <typename T, database_id DB>
  struct view_function_table_entry
  {
    typedef access::view_traits_impl<T, id_common> common_traits;

    view_function_table_entry (
      const typename common_traits::function_table_type* t)
    {
      common_traits::function_table[DB] = t;
    }

    ~view_function_table_entry ()
    {
      common_traits::function_table[DB] = 0;
    }
  };
}

#ifdef _MSC_VER
  #include "post.hxx"
#endif

#endif // ODB_FUNCTION_TABLE_HXX
