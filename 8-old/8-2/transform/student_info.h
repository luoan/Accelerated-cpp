#ifndef _STUDENT_INFO_H
#define _STUDENT_INFO_H


#include<string>
#include<vector>
#include<iostream>

struct student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

std::istream& read(std::istream&, student_info& );
std::istream& read_hw(std::istream&, std::vector<double>& );
bool did_all_hw(const student_info& );

#endif
