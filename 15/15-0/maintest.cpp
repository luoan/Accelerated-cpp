#include "student_info.hpp"
#include <iostream>

int main()
{
  student_info s1;
  s1.read(std::cin);
  std::cout << s1.grade() << std::endl;
  return 0;
}
