#ifndef _STUDENT_INFO_H 
#define _STUDENT_INFO_H



#include <vector>
#include <string>
#include <iostream>

struct student_info {
  std::string name;
  double midterm, final;
  std::vector<double> homework;
};

std::istream& read(std::istream&, student_info& );
std::istream& read_hw(std::istream&, std::vector<double>& );
bool compare(const student_info&, const student_info& );

#endif
