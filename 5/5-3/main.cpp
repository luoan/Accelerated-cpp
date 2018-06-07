#include <iostream>
#include <vector>
#include <list>
#include <string>

#include "student_info.h"
#include "typedef_student_info.h"

int main()
{
  typedef_student_info students;;
  student_info record;

  while (read(std::cin, record))
    students.push_back(record);

  return 0;
}
