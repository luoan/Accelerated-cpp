#include <vector>
#include <algorithm>
#include <stdexcept>

#include "grade.h"

double grade(double midterm, double final, const std::vector<double>& hw)
{
  if (hw.size() == 0)
    throw std::domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double median)
{
  return 0.2*midterm + 0.4*final + 0.4*median;
}

double median(std::vector<double> hw)
{

}

