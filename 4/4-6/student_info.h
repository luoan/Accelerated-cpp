#ifndef _STUDENT_INFO_H 
#define _STUDENT_INFO_H 


#include <iostream>
#include <vector>
#include <string>

struct student_info {
  std::string name;
  double final_grade;
  //double midterm, final;
  //std::vector<double> homework;
};

std::istream& read(std::istream& is, student_info& );
std::istream& read_hw(std::istream& is, std::vector<double>& hw );
bool compare(const student_info&, const student_info& );

#endif
