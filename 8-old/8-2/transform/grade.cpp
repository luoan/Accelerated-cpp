#include<vector>
#include<string>
#include<stdexcept>

#include"grade.h"
#include"student_info.h"


template <class T>
void swap(T& x, T& y)
{
    T tmp;
    tmp = x;
    x = y;
    y = tmp;
}

template <class Ran>
void sort(Ran beg, Ran end)
{
    for (Ran i = beg; i != end; ++i)
        for (Ran j = i; j > beg; --j)
            if (*(j-1) > *j)
                swap(*(j-1), *j);
            else 
                break;
}

using std::vector;  using std::string;
using std::domain_error;

using std::vector;  using std::string;
using std::domain_error;

double grade(const student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double median)
{
    return 0.2*midterm + 0.4*final + 0.4*median;
}

double median(vector<double> hw)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = hw.size();
    if (size == 0)
        throw domain_error("median of empty vector");
    vec_sz mid = size / 2;
    sort(hw.begin(), hw.end());
    return (size%2 == 0) ? (hw[mid] + hw[mid-1]) / 2
        : hw[mid];
}
