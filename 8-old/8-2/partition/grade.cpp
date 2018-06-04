#include<vector>
#include<stdexcept>
#include<iostream>

#include"student_info.h"
#include"grade.h"

using std::vector;  
using std::domain_error;

double grade(const student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

double grade(double midterm, double final, const vector<double>& hw)
{   
    if (hw.size() == 0) {
   //     std::cout << midterm << " " << final << std::endl;
        throw domain_error("student has done no homework");
    }
    return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double median)
{
    return 0.2*midterm + 0.4*final + 0.4*median;
}

template <class Ran>
void sort_median(Ran beg, Ran end)
{
    for (Ran i = beg+1; i != end; ++i)
        for (Ran j = i; j > beg; --j)
            if (*(j-1) > *j) {
                double tmp = *j;
                *j = *(j-1);
                *(j-1) = tmp;
            }
            else
                break;

            /*
            if (*(j-1) > *j)
                swap((*j-1), *j);
            else
                break;
            only with iterator it is right
                */
}

double median(vector<double> hw)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = hw.size();
    if (size == 0)
        throw domain_error("median of emtpy vector");
    sort_median(hw.begin(), hw.end());
    vec_sz mid = size / 2;
    return (size%2 == 0) ? (hw[mid] + hw[mid-1]) / 2
        : hw[mid];
}

bool pgrade(const student_info& s)
{
    if (grade(s) > 60)
        return true;
    else 
        return false;
}
