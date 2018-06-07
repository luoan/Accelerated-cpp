#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>

#include "student_info.h"
int main()
{
  std::vector<student_info> students;
  student_info record;
  /*
  std::vector<core*> students;
  core* record;
  char ch;
  std::string::size_type maxlen = 0;

  while (std::cin >> ch) {
    if (ch == 'u')
      record = new core;
    else 
      record = new grad;

    record->read(std::cin);
    maxlen = std::max(maxlen, record->name().size());
    students.push_back(record);
  }

  std::sort(students.begin(), students.end(), compare_ptr);
  *//*
  core c1(std::cin);
  grad g1(std::cin);

  try {
    std::cout << "c1:\t " << c1.grade() << std::endl;
  } catch (std::domain_error e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "g1:\t " << g1.grade() << std::endl;
  } catch (std::domain_error e) {
    std::cout << e.what() << std::endl;
  }
*/
  return 0;
}
