#ifndef _EXTRACT_FAILS_H
#define _EXTRACT_FAILS_H


#include<vector>
#include<iostream>

#include"student_info.h"
#include"grade.h"

template <class In, class T, class X>
In partition(In beg, In end, T p(const X&))
{
    In b = beg, e = end;
    while (beg != end) {
        while (beg != end && p(*beg)) 
            ++beg;

        if (beg == end) {
            sort_test(b, beg);
            sort_test(beg, e);
            return beg;
        }

        --end;
        if (beg == end) {
            sort_test(b, beg);
            sort_test(beg, e);
            return beg;
        }
        while (!p(*end) && end != beg) 
            --end;
        if (beg == end) {
            sort_test(b, beg);
            sort_test(beg, e);
            return beg;
        }
        else 
            swap(*beg, *end);
    }
    sort_test(b, beg);
    sort_test(beg, e);
    return beg;
}

std::vector<student_info>
extract_fails(std::vector<student_info>& );

#endif
