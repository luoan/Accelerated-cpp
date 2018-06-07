#ifndef _PIC_H_
#define _PIC_H_


#include "ptr.h"

#include <vector>
#include <string>
#include <iostream>

class Picture;

class Pic_base {
friend class String_Pic;
//friend class Frame_Pic;
friend std::ostream& operator<<(std::ostream&, const Picture& );
public :
  virtual ~Pic_base() { }
private :
  typedef std::vector<std::string>::size_type ht_sz;
  typedef std::string::size_type wd_sz;
//private :
  virtual ht_sz height() const = 0;
  virtual wd_sz width() const = 0;
  virtual void display(std::ostream&, ht_sz, bool) const = 0;
protected :
  static void pad(std::ostream& os, wd_sz beg, wd_sz end) {
    while (beg != end) {
      os << " ";
      ++beg;
    }
  }
};

class Picture {
friend std::ostream& operator<<(std::ostream&, const Picture& );
public :
  Picture(const std::vector<std::string>& = std::vector<std::string>() );
private :
  Picture(const Pic_base* h) : p(h) { std::cout << "in Picture Pic_base*" << std::endl; }
//private :
  //Picture(const Picture& rhs) : p(rhs.p) { }
  Ptr<Pic_base> p;
};

std::ostream& operator<<(std::ostream&, const Picture& );

class String_Pic : public Pic_base {
friend class Picture;
private :
//public :
  String_Pic(const std::vector<std::string>& v) : data(v) { }
//private :
  std::vector<std::string> data;

  ht_sz height() const { return data.size(); }
  wd_sz width() const;
  void display(std::ostream&, ht_sz, bool) const;
};
/*
class Frame_Pic : public Pic_base {
friend 
}
*/
#endif
