#ifndef _ANALYSIS_H
#define _ANALYSIS_H


#include<vector>
#include<algorithm>
#include<iostream>
#include<string>

#include"student_info.h"
#include"grade.h"

template <class T, class X, class Ve>
T analysis(const Ve& students, T f(const X& ))
{
    std::vector<double> grades;
    std::transform(students.begin(), students.end(),
            back_inserter(grades), f);
    /*
    for (std::vector<double>::const_iterator 
            it = grades.begin();
            it != grades.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
*/
    return median(grades);
}

void write_analysis(std::ostream&, const std::string&,
        double analysis(const std::vector<student_info>& ,
            double f(const student_info& )),
        double f(const student_info& ),
        const std::vector<student_info>& did,
        const std::vector<student_info>& did_not);

double grade_aux(const student_info& );

double average_grade(const student_info& );
double average(const std::vector<double>& );

double optimistic_median(const student_info& );

#endif
