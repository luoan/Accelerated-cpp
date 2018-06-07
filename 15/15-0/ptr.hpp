#ifndef _PTR_HPP_
#define _PTR_HPP_


//#include <cstddef>
#include <stddef.h>
#include <stdexcept>

template <class T>
class Ptr {
public :
  Ptr() : p(0), refptr(new std::size_t(1)) { }
  Ptr(T* t) : p(t), refptr(new std::size_t(1)) { }

  Ptr(const Ptr& rhs) : p(rhs.p), refptr(rhs.refptr) { ++*refptr; }
  Ptr& operator=(const Ptr& rhs) {
    ++*rhs.refptr;
    if (--*refptr == 0) {
      delete p;
      delete refptr;
    }
    p = rhs.p;
    refptr = rhs.refptr;
    return *this;
  }
  ~Ptr() { 
    if (--*refptr == 0) {
      delete p;
      delete refptr;
    }
  }

  void make_unique() {
    if (*refptr != 1) {
      --*refptr;
      p = p ? clone(p) : 0;
      refptr = new std::size_t(1);
    }
  }

  operator bool() const { return p; }
  /*const*/ T* operator->() const { // it is ok to has const
    if (p) return p;
    else throw std::runtime_error("unbound Ptr");
  }
  T& operator*() const {
    if (p) return *p;
    else throw std::runtime_error("unbound Ptr");
  }

private :
  T* p;
  std::size_t* refptr;
};

template <class T>
T* clone(const T* tp)
{
  return tp->clone();
}

#endif
