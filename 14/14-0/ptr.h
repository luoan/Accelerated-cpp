#ifndef _PTR_H_
#define _PTR_H_


//#include <cstddef>

template <class T>
class ptr {
public :
  ptr() : p(0), refptr(new std::size_t(1)) { }
  ptr(T* t) : p(t), refptr(new std::size_t(1)) { }
  
  ptr(const ptr& h) : p(h.p), refptr(h.refptr) { ++*refptr; }
  ptr& operator=(const ptr& );
  ~ptr();

  void make_unique() {
    if (*refptr != 1) {
      --*refptr;
      refptr = new std::size_t(1);
      p = p ? clone(p) : 0;
    }
  }
  
  operator bool() const { return p; }
  T& operator*() const { return *p; }
  T* operator->() const { return p; }

private :
  T* p;
  std::size_t* refptr;
};

template <class T>
T* clone(const T* tp) 
{
  return tp->clone();
}

template <class T>
ptr<T>& ptr<T>::operator=(const ptr& h)
{
  ++*h.refptr;
  if (--*refptr == 0) {
    delete refptr;
    delete p;
  }
  p = h.p;
  refptr = h.refptr;
  return *this;
}

template <class T>
ptr<T>::~ptr()
{
  if (--*refptr == 0) {
    delete refptr;
    delete p;
  }
}

#endif
