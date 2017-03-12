#include<iostream>
#include<string>
#include<vector>

#include"student_info.h"

using std::istream; using std::string;
using std::vector;

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
