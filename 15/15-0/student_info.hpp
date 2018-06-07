#ifndef _STUDENT_INFO_H_
#define _STUDENT_INFO_H_


#include "ptr.hpp"
#include "core.h"

#include <stdexcept>
#include <iostream>

class student_info {
public :
  student_info() { }
  student_info(std::istream& is) { read(is); }

  std::istream& read(std::istream& is) {
    char ch;
    is >> ch;
    if (ch == 'u')
      cp = new core(is);
    else 
      cp = new grad(is);
    return is;
  } 
  std::string name() const  { 
    if (cp) return cp->name();
    else throw std::runtime_error("uninitialized student");
  }

  double grade() const {
    if (cp) return cp->grade();
    else throw std::runtime_error("uninitialized student");
  }

  static bool compare(const student_info& s1,
                      const student_info& s2) {
    return s1.name() < s2.name();
  }

private :
  Ptr<core> cp;
};

#endif
