#ifndef _PTR_H_
#define _PTR_H_


#include <cstddef>
#include <stdexcept>
#include <iostream>
/*
template <class T>
T* clone(const T* tp) {
  return tp->clone();
}*/

/*#include "core.h"

core* clone(const core* tp)
{
  return tp->clone();
}*/
#include "core.h"

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
 /*     if (p) 
        p = clone( (&core::clone()) );
      else 
        p = 0;
      refptr = new std::size_t(1);
   */ }
  }

  operator bool() const { return p; }
  T* operator->() const {
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
/*
template <class T>
T* clone(T* (*fp)( ))
{
  return (*fp)();
}*/

template <class T>
T* clone(const T* tp)
{
  std::cout << "In ptr clone() " << std::endl;
  return tp->clone();
}

#endif
