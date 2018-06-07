#ifndef _GRADE_H_
#define _GRADE_H_


#include <algorithm>
#include <vector>
#include <string>

#include "student_info.h"

bool fgrade(const student_info& );
double median(/*const*/ std::vector<double>/*&*/ );
double grade(const student_info& );
double grade(double, double, const std::vector<double>& );
double grade(double, double, double );
bool did_all_hw(const student_info& );

double grade_aux(const student_info& );
//double median_analysis(const std::vector<student_info>& );

/*void write_analysis(std::ostream&, const std::string&, 
          double analysis(const std::vector<student_info>&),
          const std::vector<student_info>& did,
          const std::vector<student_info>& did_not);
*/
double average(const std::vector<double>& );
double average_grade(const student_info& );
//double average_analysis(const std::vector<student_info>& );

double optimistic_median(const student_info& );
//double optimistic_median_analysis(const std::vector<student_info>& );

template <class Function>
double analysis(const std::vector<student_info>& s,
                Function analysis_function )
{
  std::vector<double> grades;
  std::transform(s.begin(), s.end(),
      back_inserter(grades), analysis_function);
  return median(grades);
}

template <class Function>
void write_analysis(std::ostream& out, const std::string& name,
    Function analysis_function,
    const std::vector<student_info>& did,
    const std::vector<student_info>& didnt) 
{
  out << name << ": median(did) = " << analysis(did, analysis_function)
    << ", median(didnt) = " << analysis(didnt, analysis_function) << std::endl;
}

#endif
