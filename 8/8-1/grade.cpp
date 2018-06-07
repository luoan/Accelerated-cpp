#include <vector>
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include "student_info.h"
#include "grade.h"

bool fgrade(const student_info& s)
{
  return grade(s) < 60;
}

double median(/*const*/std::vector<double>/*&*/ hw)
{
  if (hw.size() == 0)
    throw std::domain_error("median of empty vector");
  typedef std::vector<double>::size_type vec_sz;

  vec_sz size = hw.size();
  std::sort(hw.begin(), hw.end());
  vec_sz mid = hw.size() / 2;

  return hw.size()%2==0 ? (hw[mid] + hw[mid-1]) / 2
    : hw[mid];
}

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

bool did_all_hw(const student_info& s)
{
  return ((std::find(s.homework.begin(), s.homework.end(), 0)) 
      == s.homework.end());
}

double grade_aux(const student_info& s)
{
  try {
    return grade(s);
  } catch (std::domain_error ) {
    return grade(s.midterm, s.final, 0);
  }
}

/*
double median_analysis(const std::vector<student_info>& s)
{
  std::vector<double> grades;

  std::transform(s.begin(), s.end(), back_inserter(grades), grade_aux);
  return median(grades);
}
*/

/*
void write_analysis(std::ostream& out, const std::string& name,
          double analysis(const std::vector<student_info>&),
          const std::vector<student_info>& did,
          const std::vector<student_info>& didnt)
{
  out << name << ": median(did) = " << analysis(did) <<
    ", median(didnt) = " << analysis(didnt) << std::endl;
}
*/
double average(const std::vector<double>& v)
{
  return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const student_info& s)
{
  return grade(s.midterm, s.final, average(s.homework));
}

/*
double average_analysis(const std::vector<student_info>& s)
{
  std::vector<double> grades;
  std::transform(s.begin(), s.end(), 
      back_inserter(grades), average_grade);
  return median(grades);
}
*/

double optimistic_median(const student_info& s)
{
  std::vector<double> nonzero;
  std::remove_copy(s.homework.begin(), 
      s.homework.end(), back_inserter(nonzero), 0);

  if (nonzero.empty())
    return grade(s.midterm, s.final, 0);
  else 
    return grade(s.midterm, s.final, median(nonzero));
}

/*
double optimistic_median_analysis(const std::vector<student_info>& s)
{
  std::vector<double> grades;
  std::transform(s.begin(), s.end(),
      back_inserter(grades), optimistic_median);
  return median(grades);
}*/



