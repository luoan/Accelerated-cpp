#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "core.h"
#include "grade.h"

std::string core::name() const { return n; }

double core::grade() const 
{
  return ::grade(midterm, final, homework);
}

std::istream& core::read_common(std::istream& is)
{
  is >> n >> midterm >> final;
  return is;
}

std::istream& core::read(std::istream& is)
{
  //std::cout << "in core::read" << std::endl;
  read_common(is);
  read_hw(is, homework);
  //std::cout << "name : " << name << std::endl;
  return is;
}

std::istream& grad::read(std::istream& is)
{
  core::read_common(is);
  is >> grad::thesis;
  read_hw(is, homework);
  return is;
}

double grad::grade() const 
{
  return std::min(grad::thesis, core::grade());
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
/*
bool compare(const core&c1, const core& c2)
{
  return c1.name() < c2.name();
}

bool compare_ptr(const core* c1, const core* c2)
{
  return compare(*c1, *c2);
}*/
