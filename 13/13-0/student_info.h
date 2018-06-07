#ifndef _STUDENT_INFO_H_
#define _STUDENT_INFO_H_


#include "core.h"
#include <iostream>
#include <string>
#include <stdexcept>

class student_info {
  public :
    student_info() : cp(0) { }
    student_info(std::istream& );
    
    student_info(const student_info& );
    student_info& operator=(const student_info& );
    ~student_info() { delete cp; }

    std::istream& read(std::istream& );
    std::string name() const { 
      if (cp)  return cp->name(); 
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
    core* cp;
};

#endif
