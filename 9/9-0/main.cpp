#include <iostream>
#include <stdexcept>

#include "student_info.h"

int main()
{
  student_info record;
  std::vector<student_info> s;

  while (record.read(std::cin)) 
    s.push_back(record);

  std::cout << std::endl;
  for (std::vector<student_info>::const_iterator it = s.begin();
      it != s.end(); ++it) {
    try {
      double f = it->grade();
      std::cout << it->name() << "\t " << f << std::endl;
    } catch (std::domain_error e) {
      std::cout << it->name() << "\t ";
      std::cout << e.what() << std::endl;
    }
  }

  
  return 0;
}
