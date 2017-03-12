#include<iostream>
#include<vector>
#include<string>

#include"student_info.h"
#include"template.h"

using std::cin; using std::istream;
using std::vector;  using std::string;

istream& read(istream& in, student_info& s)
{
    in >> s.name >> s.midterm >> s.final;
    read_hw(in, s.homework);
    return in;
}

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}

bool did_all_hw(const student_info& s)
{
    if (find(s.homework.begin(), 
                s.homework.end(), 0) == s.homework.end())
        return true;
    else 
        return false;
}
