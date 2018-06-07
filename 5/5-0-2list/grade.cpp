#include <vector>
#include <algorithm>
#include <stdexcept>
#include <list>

#include "grade.h"
#include "student_info.h"

double grade(const student_info& s)
{
  return grade(s.midterm, s.final, s.homework);
}

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
  typedef std::vector<double>::size_type vec_sz;

  if (hw.size() == 0)
    throw std::domain_error("median of empty vector");
  std::sort(hw.begin(), hw.end());
  vec_sz mid = hw.size() / 2;

  return hw.size()%2==0 ? (hw[mid-1] + hw[mid]) / 2
    : hw[mid];
}

bool fgrade(const student_info& s)
{
  return grade(s) < 60;
}

std::list<student_info> extract_fail( std::list<student_info>& s)
{
  std::list<student_info> fail;
  std::list<student_info>::iterator it = s.begin();

  while (it != s.end()) {
    if (fgrade(*it)) {
      fail.push_back(*it);
      it = s.erase(it);
    }
    else 
      ++it;
  }

  return fail;
}
