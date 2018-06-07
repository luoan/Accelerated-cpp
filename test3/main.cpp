#include "student_info.h"

#include <iostream>

int main()
{
  student_info s1(std::cin);
  //std::cout << s1.name() << " " << s1.grade() << std::endl;
  student_info s2;
  s2 = s1;
  
  s2.make_unique_test();
  
  return 0;
}
