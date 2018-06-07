#include <iostream>
#include <string>
#include <vector>

#include "student_info.h"

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
  return s1.name() < s2.name();
}

std::istream& student_info::read(std::istream& is)
{
  is >> n >> midterm >> final;
  read_hw(is, homework);

  return is;
}


