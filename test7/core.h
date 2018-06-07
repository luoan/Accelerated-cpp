#ifndef _CORE_H_
#define _CORE_H_


#include <vector>
#include <string>
#include <iostream>

std::istream& read_hw
class Core {
public :
  Core() : midterm(0) , final(0) { }
  Core(std::istream& is) { read(is); }
  
  std::istream& read(std::istream& is) {
    read_common(is);
    read_hw(is, homework);
    return is;
  }


};



#endif
