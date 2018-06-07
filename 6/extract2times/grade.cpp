#include <vector>
#include <algorithm>
#include <stdexcept>

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

bool pgrade(const student_info& s)
{
  return !fgrade(s);
}

/*
std::vector<student_info> extract_fail(std::vector<student_info>& s)
{
  std::vector<student_info> fail;
  std::vector<student_info>::iterator it = s.begin();

  while (it != s.end()) {
    if (fgrade(*it)) {
      fail.push_back(*it);
      it = s.erase(it);
    }
    else 
      ++it;
  }

  return fail;
}*/

std::vector<student_info> extract_fail(std::vector<student_info>& students)
{
  std::vector<student_info> fail;
  std::remove_copy_if(students.begin(), students.end(),
      back_inserter(fail), pgrade);
  students.erase(remove_if(students.begin(), students.end(),
        fgrade), students.end());
  return fail;
}
