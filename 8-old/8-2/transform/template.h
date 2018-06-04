#ifndef _TEMPLATE_H
#define _TEMPLATE_H


#include<vector>

#include"grade.h"

template <class In, class X>
In find(In beg, In end, const X& x)
{
    while (beg != end) {
        if (*beg == x)
            return beg;
        ++beg;
    }
    return end;
}

template <class In, class Out, class T, class X>
void transform(In begin, In end, Out dest, T f(const X&))
{
    while (begin != end) {
        *dest++ = f(*begin);
        ++begin;
    }
}


template <class T, class X>
T fun_analysis(const std::vector<X>& students,
        T f(const X&))
{
    std::vector<double> grades;
    transform(students.begin(), students.end(),
            back_inserter(grades), f);
    return median(grades);
}


#endif
/*
find
fun_analysis
transform
accumulate
*/
