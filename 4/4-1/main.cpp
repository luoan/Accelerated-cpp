#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ios>
#include <iomanip>
#include <stdexcept>

#include "grade.h"
#include "student_info.h"

int main()
{
  std::vector<student_info> students;
  student_info record;
  std::string::size_type maxlen = 0;

  //int maxlen = 0;

  while (read(std::cin, record)) {
    /* if (record.name.size() > maxlen)
      maxlen = record.name.size();
    */
    maxlen = std::max(maxlen, record.name.size());
    students.push_back(record);
  }

  std::sort(students.begin(), students.end(), compare);

  std::cout << std::endl;
  std::cout << record.name;
  /*
  for (std::vector<student_info>::size_type i = 0;
        i != students.size(); ++i) {

    std::cout << students[i].name
      << std::string(maxlen+1 - students[i].name.size(), ' ');
    try {
      double f_grade = grade(students[i]);
      std::streamsize prec = std::cout.precision();
      std::cout << std::setprecision(3)
        << f_grade << std::setprecision(prec);
    } catch (std::domain_error e) {
      std::cout << e.what();
    }
    std::cout << std::endl;
  }
  */
  return 0;
}
