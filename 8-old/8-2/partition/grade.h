#ifndef _GRADE_H
#define _GRADE_H


#include<vector>

#include"student_info.h"

template <class T>
void swap(T& x, T& y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

template <class Ran>
void sort_test(Ran beg, Ran end)
{
    for (Ran i = beg+1; i < end; ++i)
        for (Ran j = i; j > beg; --j)
            if ( (*(j-1)).name > (*j).name)
                swap(*(j-1), *j);
            else
                break;
}

double grade(const student_info& );
double grade(double, double, const std::vector<double>& );
double grade(double, double, double);
double median(std::vector<double> );
bool pgrade(const student_info& );

#endif
