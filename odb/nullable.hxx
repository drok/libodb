// file      : odb/nullable.hxx
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_NULLABLE_HXX
#define ODB_NULLABLE_HXX

#ifdef _MSC_VER
  #include "pre.hxx"
#endif

#include "forward.hxx" // odb::core

namespace odb
{
  template <typename T>
  class nullable
  {
  public:
    typedef T value_type;

    nullable ();
    nullable (const T&);
    nullable (const nullable&);
    template <typename Y> explicit nullable (const nullable<Y>&);

    nullable& operator= (const T&);
    nullable& operator= (const nullable&);
    template <typename Y> nullable& operator= (const nullable<Y>&);

    void swap (nullable&);

    bool null () const;

    T&       get ();
    const T& get () const;

    T*       operator-> ();
    const T* operator-> () const;

    T&       operator* ();
    const T& operator* () const;

    typedef void (nullable::*bool_convertible) ();
    operator bool_convertible () const
    {
      return null_ ? 0 : &nullable<T>::true_value;
    }

    void reset ();

  private:
    void true_value () {};

    T value_;
    bool null_;
  };

  namespace common
  {
    using odb::nullable;
  }

  template <typename T>
  inline bool
  operator== (const nullable<T>& x, const nullable<T>& y)
  {
    return x.null () == y.null () && (x.null () || *x == *y);
  }

  template <typename T>
  inline bool
  operator!= (const nullable<T>& x, const nullable<T>& y) {return !(x == y);}

  template <typename T>
  inline bool
  operator< (const nullable<T>& x, const nullable<T>& y)
  {
    return x.null () > y.null () || (!x.null () && !y.null () && *x < *y);
  }

  template <typename T>
  inline bool
  operator> (const nullable<T>& x, const nullable<T>& y)
  {
    return x.null () < y.null () || (!x.null () && !y.null () && *x > *y);
  }

  template <typename T>
  inline bool
  operator<= (const nullable<T>& x, const nullable<T>& y) {return !(x > y);}

  template <typename T>
  inline bool
  operator>= (const nullable<T>& x, const nullable<T>& y) {return !(x < y);}

  template <typename T>
  inline nullable<T>::
  nullable ()
      : null_ (true)
  {
  }

  template <typename T>
  inline nullable<T>::
  nullable (const T& v)
      : value_ (v), null_ (false)
  {
  }

  template <typename T>
  inline nullable<T>::
  nullable (const nullable& y)
      : value_ (y.value_), null_ (y.null_)
  {
  }

  template <typename T>
  template <typename Y>
  inline nullable<T>::
  nullable (const nullable<Y>& y)
      : value_ (y.value_), null_ (y.null_)
  {
  }

  template <typename T>
  inline nullable<T>& nullable<T>::
  operator= (const T& v)
  {
    value_ = v;
    null_ = false;
    return *this;
  }

  template <typename T>
  inline nullable<T>& nullable<T>::
  operator= (const nullable& y)
  {
    if (this != &y)
    {
      value_ = y.value_;
      null_ = y.null_;
    }

    return *this;
  }

  template <typename T>
  template <typename Y>
  inline nullable<T>& nullable<T>::
  operator= (const nullable<Y>& y)
  {
    value_ = y.value_;
    null_ = y.null_;
    return *this;
  }

  template <typename T>
  inline void nullable<T>::
  swap (nullable& y)
  {
    T v (value_);
    bool n (null_);

    value_ = y.value_;
    null_ = y.null_;

    y.value_ = v;
    y.null_ = n;
  }

  template <typename T>
  inline bool nullable<T>::
  null () const
  {
    return null_;
  }

  template <typename T>
  inline T& nullable<T>::
  get ()
  {
    return value_;
  }

  template <typename T>
  inline const T& nullable<T>::
  get () const
  {
    return value_;
  }

  template <typename T>
  inline T* nullable<T>::
  operator-> ()
  {
    return null_ ? 0 : &value_;
  }

  template <typename T>
  inline const T* nullable<T>::
  operator-> () const
  {
    return null_ ? 0 : &value_;
  }

  template <typename T>
  inline T& nullable<T>::
  operator* ()
  {
    return value_;
  }

  template <typename T>
  inline const T& nullable<T>::
  operator* () const
  {
    return value_;
  }

  template <typename T>
  inline void nullable<T>::
  reset ()
  {
    value_ = T ();
    null_ = true;
  }
}

#ifdef _MSC_VER
  #include "post.hxx"
#endif

#endif // ODB_NULLABLE_HXX
