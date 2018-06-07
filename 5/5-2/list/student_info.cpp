#include <iostream>
#include <vector>
#include <string>

#include "student_info.h"

std::istream& read(std::istream& is, student_info& s) 
{
  is >> s.name >> s.midterm >> s.final;
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
