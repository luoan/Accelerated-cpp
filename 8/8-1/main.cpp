#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "grade.h"
#include "student_info.h"

int main()
{
  //student_info student;
  std::vector<student_info> did, didnt;
  std::fstream infile;
  infile.open("grade.txt");
  student_info student;
  while (read(infile, student)) {
    if (did_all_hw(student))
      did.push_back(student);
    else 
      didnt.push_back(student);
  }

  if (did.empty()) {
    std::cout << "No student did all the homework!" << std::endl;
    return 1;
  }
  if (didnt.empty()) {
    std::cout << "Every student did all the homework" << std::endl;
    return 1;
  }

  write_analysis(std::cout, "median", grade_aux, did, didnt);
  write_analysis(std::cout, "average", average_grade, did, didnt);
  write_analysis(std::cout, "median of homework turned in", optimistic_median, did, didnt);
  return 0;
}
