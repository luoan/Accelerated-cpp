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

void write_analysis(std::ostream&, const std::string&,
                    double analysis_function(const student_info&),
                    const std::vector<student_info>& did,
                    const std::vector<student_info>& didnt);

double average(const std::vector<double>& );
double average_grade(const student_info& );
//double average_analysis(const std::vector<student_info>& );

double optimistic_median(const student_info& );
//double optimistic_median_analysis(const std::vector<student_info>& );


double analysis(const std::vector<student_info>& , 
                double function(const student_info& ));

#endif
