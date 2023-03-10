// file      : odb/details/buffer.cxx
// license   : GNU GPL v2; see accompanying LICENSE file

#include <cstring> // std::memcpy

#include "buffer.hxx"

using namespace std;

namespace odb
{
  namespace details
  {
    void basic_buffer_base::
    capacity (size_t c, size_t data_size)
    {
      if (c > capacity_)
      {
        size_t n (capacity_ * 2 > c ? capacity_ * 2 : c);
        void* d (operator new (n));

        if (data_ != 0)
        {
          if (data_size != 0)
            memcpy (d, data_, data_size);

          operator delete (data_);
        }

        data_ = d;
        capacity_ = n;
      }
    }
  }
}
