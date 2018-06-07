#ifndef _STUDENT_INFO_H_
#define _STUDENT_INFO_H_


#include <iostream>
#include <string>
#include <vector>

class student_info {
  public :
    student_info() : midterm(0), final(0) { }
    student_info(std::istream& is) { read(is); }
    
    double grade() const { return f_grade; }
    std::string name() const { return n; }
    std::istream& read(std::istream& is);
  
  private :
    std::string n;
    double midterm, final;
    std::vector<double> hw;
    double f_grade;
}

std::istream& read_hw(std::istream&, std::vector<double>& hw);

bool compare(const student_info&, const student_info& );
             
