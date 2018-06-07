#include <iostream>
#include <vector>
#include <string>

#include "student_info.h"

std::istream& read(std::istream& is, student_info& s) 
{
  is >> s.name;
  //is.clear();感觉没什么用
  is >> s.midterm;
  //is.clear();
  is >> s.final;
  //is.clear();
  read_hw(is, s.homework);

  return is;
}

std::istream& read_hw(std::istream& is, std::vector<double>& hw)
{
  if (is) {
    hw.clear();

    double x;
    while (is >> x)
      hw.push_back(x);
    
    is.clear();
  }

  return is;
}

bool compare(const student_info& s1, const student_info& s2)
{
  return s1.name < s2.name;
}
