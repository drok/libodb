// file      : odb/details/meta/answer.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_META_ANSWER_HXX
#define ODB_DETAILS_META_ANSWER_HXX

#ifdef _MSC_VER
  #include "../../pre.hxx"
#endif

namespace odb
{
  namespace details
  {
    namespace meta
    {
      struct yes
      {
        char filling;
      };

      struct no
      {
        char filling[2];
      };
    }
  }
}

#ifdef _MSC_VER
  #include "../../post.hxx"
#endif

#endif // ODB_DETAILS_META_ANSWER_HXX
