// file      : odb/std-forward-list-traits.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_STD_FORWARD_LIST_TRAITS_HXX
#define ODB_STD_FORWARD_LIST_TRAITS_HXX

#ifdef _MSC_VER
  #include "pre.hxx"
#endif

#include <forward_list>

#include "container-traits.hxx"

namespace odb
{
  template <typename V, typename A>
  class access::container_traits<std::forward_list<V, A>>
  {
  public:
    static const container_kind kind = ck_ordered;
    static const bool smart = false;

    typedef std::forward_list<V, A> container_type;

    typedef V value_type;
    typedef typename container_type::size_type index_type;

    typedef ordered_functions<index_type, value_type> functions;

  public:
    static void
    persist (const container_type& c, const functions& f)
    {
      index_type i (0);
      for (typename container_type::const_iterator j (c.begin ()),
             e (c.end ()); j != e; ++j)
        f.insert (i++, *j);
    }

    static void
    load (container_type& c, bool more, const functions& f)
    {
      c.clear ();

      for (typename container_type::iterator i (c.before_begin ()); more; )
      {
        index_type dummy;
        i = c.insert_after (i, value_type ());
        more = f.select (dummy, *i);
      }
    }

    static void
    update (const container_type& c, const functions& f)
    {
      f.delete_ ();

      index_type i (0);
      for (typename container_type::const_iterator j (c.begin ()),
             e (c.end ()); j != e; ++j)
        f.insert (i++, *j);
    }

    static void
    erase (const functions& f)
    {
      f.delete_ ();
    }
  };
}

#ifdef _MSC_VER
  #include "post.hxx"
#endif

#endif // ODB_STD_FORWARD_LIST_TRAITS_HXX
