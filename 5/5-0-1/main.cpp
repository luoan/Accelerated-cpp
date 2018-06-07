#include <iostream>
#include <string>
#include <algorithm>
#include <ios>//streamsize
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "student_info.h" 
#include "grade.h"// extract_fail

int main()
{
  std::vector<student_info> students;
  std::vector<student_info> fail, pass;
  student_info record;
  std::string::size_type maxlen = 0;

  while (read(std::cin, record)) {
    students.push_back(record);
    maxlen = std::max(maxlen, record.name.size());
  }
  
  std::sort(students.begin(), students.end(), compare);
  fail = extract_fail(students);
  pass = students;

  std::cout << std::endl;
  std::cout << "pass: " << std::endl;
  for (std::vector<student_info>::const_iterator it = pass.begin();
      it != pass.end(); ++it) {
    std::cout << (*it).name << std::string(maxlen+1 - (*it).name.size(), ' ');
    try {
      double final_grade = grade(*it);
      std::cout << final_grade;
    } catch (std::domain_error e) {
      std::cout << e.what();
    }
    std::cout << std::endl;
  }
  
  std::cout << std::endl;
  std::cout << "fail: " << std::endl;
  for (std::vector<student_info>::const_iterator it = fail.begin();
      it != fail.end(); ++it) {
    std::cout << (*it).name << std::string(maxlen+1 - (*it).name.size(), ' ');
    try {
      double final_grade = grade(*it);
      std::cout << final_grade;
    } catch (std::domain_error e ) {
      std::cout << e.what();
    }
    std::cout << std::endl;
  }

  return 0;
}
