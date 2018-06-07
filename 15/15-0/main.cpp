#include "pic.h"
#include "student_info.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

int main()
{
  std::fstream infile;
  infile.open("grades.txt");
  std::vector<student_info> students;
  student_info record;
  
  std::vector<std::string> names;
  std::vector<std::string> grades;

  while (record.read(infile)) {
    students.push_back(record);
  }
  std::sort(students.begin(), students.end(), student_info::compare);
  
  for (std::vector<student_info>::size_type i = 0;
      i != students.size(); ++i) {
    names.push_back(students[i].name()); // what if operator string???
    grades.push_back(" " + std::string( (int)(students[i].grade()/5), '='));
    //grades.push_back(students[i].grade());// what if operator bool in student_info???
  }

  Picture pname(names);
  Picture pgrade(grades);
  Picture p = frame(hcat(pname, pgrade));
  std::cout << p;
  return 0;
  /*
  std::vector<std::string> v;
  std::string s;
  while (getline(std::cin, s)) {
    v.push_back(s);
  }
  
  Picture p1(v);
  Picture p2 = frame(p1);
  Picture p3 = vcat(p1, p2);
  Picture p4 = hcat(p2, p3);
  std::cout << p4 ;
  return 0;*/
}
