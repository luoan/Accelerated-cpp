#ifndef _GRADE_H  
#define _GRADE_H  


#include <vector>
#include <list>

#include "student_info.h"

double grade(const student_info& );
double grade(double, double, const std::vector<double>& );
double grade(double, double, double );
double median(std::vector<double> );
bool fgrade(const student_info& );
std::list<student_info> extract_fail(std::list<student_info>& );

#endif
