#include "student_info.hpp"

#include <iostream>

int main()
{
  Student_info s1;
  s1.read(std::cin);

  std::cout << s1.grade() << std::endl;
  s1.regrade(100, 98);
  std::cout << s1.grade() << std::endl;

  Student_info s2;
  s2.read(std::cin);
  std::cout << s2.grade() << std::endl;
  s2.regrade(100, 69);
  std::cout << s2.grade() << std::endl;
  
  double d = double();
  std::cout << d << std::endl;

  return 0;
}
