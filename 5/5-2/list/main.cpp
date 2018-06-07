#include <iostream>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <time.h>
#include <fstream>

#include "student_info.h"
#include "grade.h"

int main()
{
  clock_t start = clock();

  std::fstream infile;
  infile.open("1200k.txt");
  std::list<student_info> students;
  student_info record;
  std::string::size_type maxlen = 0;
  
  while (read(infile, record)) {
    students.push_back(record);
    maxlen = std::max(maxlen, record.name.size());
  }

  std::list<student_info> fail;
  std::list<student_info> pass;
  students.sort(compare);

  fail = extract_fail(students);
  
  clock_t end = clock();
  std::cout << "time: " << (double)(end-start)/CLOCKS_PER_SEC << std::endl;
  /*
  pass = students;
  
  std::cout << std::endl;
  std::cout << "pass: " << std::endl;
  for (std::list<student_info>::const_iterator it = pass.begin();
      it != pass.end(); ++it) {
    std::cout << (*it).name << std::string(maxlen+1 - it->name.size(), ' ');
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
  for (std::list<student_info>::const_iterator it = fail.begin();
      it != fail.end(); ++it) {
    std::cout << (*it).name << std::string(maxlen+1 - it->name.size(), ' ');
    try {
      double final_grade = grade(*it);
      std::cout << final_grade;
    } catch (std::domain_error e) {
      std::cout << e.what();
    }
    std::cout << std::endl;
  }
*/
  return 0;
}
