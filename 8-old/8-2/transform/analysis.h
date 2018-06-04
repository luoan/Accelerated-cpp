#ifndef _ANALYSIS_H
#define _ANALYSIS_H


#include<iostream>
#include<string>
#include<vector>

#include"student_info.h"

void write_analysis(std::ostream&, const std::string&,
        double fun_analysis(const std::vector<student_info>&,
            double f(const student_info& )),
        double f(const student_info& ),
        const std::vector<student_info>& did,
        const std::vector<student_info>& did_not);

double grade_aux(const student_info& );

#endif
