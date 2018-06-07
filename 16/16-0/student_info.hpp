#ifndef _STUDENT_INFO_HPP_
#define _STUDENT_INFO_HPP_


#include "ptr.hpp"
#include "core.h"

#include <stdexcept>
#include <iostream>

class Student_info {
public :
  Student_info() { }
  Student_info(std::istream& is) { read(is); }

  std::istream& read(std::istream& is) {
    char ch;
    //std::cout << "in student_info read" << std::endl;
    is >> ch;
    if (ch == 'u')
      cp = new core(is);
    else 
      cp = new grad(is);
    //std::cout << "out student_info read" << std::endl;

    return is;
  }

  std::string name() const { 
    if (cp) return cp->name(); 
    else throw std::runtime_error("unbound Ptr");
  }
  double grade() const { 
    //std::cout << "in student_info grade()" << std::endl;
    if (cp) return cp->grade();
    else throw std::runtime_error("unbound Ptr");
  }
  void regrade(double final_grade, double thesis=double()) {
    cp->regrade(final_grade, thesis);
  }
  static bool compare(const Student_info& s1, const Student_info& s2) {
    return s1.name() < s2.name();
  }

private :
  Ptr<core> cp;
};

#endif
