// file      : odb/statement.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_STATEMENT_HXX
#define ODB_STATEMENT_HXX

#ifdef _MSC_VER
  #include "pre.hxx"
#endif

#include <string>
#include <cstddef> // std::size_t

#include "forward.hxx" // connection

#include "details/export.hxx"
#include "details/shared-ptr.hxx"

namespace odb
{
  class LIBODB_EXPORT statement: public details::shared_base
  {
  private:
    statement (const statement&);
    statement& operator= (const statement&);

  public:
    typedef odb::connection connection_type;

    virtual const char*
    text () const = 0;

    virtual connection_type&
    connection ()  = 0;

    virtual
    ~statement () = 0;

  protected:
    statement () {}

    // Statement processing. Kept public only for testing.
    //
  public:
    // Expected statement structure:
    //
    //  INSERT INTO table\n
    // [(a,\n
    //  b)\n]
    // [OUTPUT ...\n]
    // [VALUES\n
    //  ($1,\n
    //  $2)[\n]]
    // [DEFAULT VALUES[\n]]
    // [RETURNING ...]
    // [; SELECT ...]
    //
    static void
    process_insert (std::string& result,
                    const char* statement,
                    const void* const* bind,  // Array of bind buffer pointers.
                    std::size_t bind_size,    // Number of bind elements.
                    std::size_t bind_skip,    // Offset to the next bind.
                    char param_symbol,        // $, ?, :, etc.
                    char param_symbol2 = '\0');

    // Expected statement structure:
    //
    //  UPDATE table\n
    //  SET\n
    //  a=$1,\n
    //  b=$2[\n]
    // [OUTPUT ...]
    // [WHERE ...]
    //
    static void
    process_update (std::string& result,
                    const char* statement,
                    const void* const* bind,  // Array of bind buffer pointers.
                    std::size_t bind_size,    // Number of bind elements.
                    std::size_t bind_skip,    // Offset to the next bind.
                    char param_symbol,        // $, ?, :, etc.
                    char param_symbol2 = '\0');


    // Expected statement structure:
    //
    //  SELECT\n
    //  [schema.]table.a [AS b],\n
    //  alias.b\n
    //  FROM [schema.]table[\n]
    // [{A-Z }* JOIN [schema.]table [AS alias][ ON ...][\n]]*
    // [WHERE ...]
    //
    static void
    process_select (std::string& result,
                    const char* statement,
                    const void* const* bind, // Array of bind buffer pointers.
                    std::size_t bind_size,   // Number of bind elements.
                    std::size_t bind_skip,   // Offset to the next bind.
                    char quote_open,         // Identifier opening quote.
                    char quote_close,        // Identifier closing quote.
                    bool optimize,           // Remove unused JOINs.
                    bool as = true);         // JOINs use AS keyword.
  };
}

#ifdef _MSC_VER
  #include "post.hxx"
#endif

#endif // ODB_STATEMENT_HXX
