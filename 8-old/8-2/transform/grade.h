#ifndef _GRADE_H
#define _GRADE_H


#include<string>
#include<vector>
#include<stdexcept>

#include"student_info.h"

double grade(const student_info& );
double grade(double, double, const std::vector<double>& );
double grade(double, double, double );
double median(std::vector<double> );

/*
template <class T>
void swap(T& x, T& y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

template <class Ran>
void sort(Ran beg, Ran end)
{
    for (Ran i = beg; i != end; ++i)
        for (Ran j = i; j > beg; --j)
            if (*(j-1) > *j)
                swap(*(j-1), *)
}*/

#endif
