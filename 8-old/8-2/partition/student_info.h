#ifndef _STUDENT_H
#define _STUDENT_H


#include<iostream>
#include<string>
#include<vector>

struct student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

std::istream& read(std::istream&, student_info& );
std::istream& read_hw(std::istream&, std::vector<double>& hw);

#endif
