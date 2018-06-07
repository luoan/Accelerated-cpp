#ifndef _STUDENT_INFO_H_
#define _STUDENT_INFO_H


#include <string>
#include <vector>
#include <iostream>

#include "grade.h"

//std::istream& read_hw(std::istream&, std::vector<double>& );

class student_info {

  public :
    student_info() : midterm(0), final(0) { }
    student_info(std::istream& is) { read(is); }

    std::string name() const  { return n; }
    double grade() const { return ::grade(midterm, final, homework); }
    std::istream& read(std::istream& );
    bool valid() const { return !homework.empty(); }
  
  private :
    std::string n;
    double midterm, final;
    std::vector<double> homework;
};

std::istream& read_hw(std::istream&, std::vector<double>& );
bool comapre(const student_info& s1, const student_info& s2);

/*
{
  return s1.name() < s2.name()
}

std::istream& student_info::read(std::istream& is) 
{
  is >> n >> midterm >> final;
  read_hw(is, homework);
  return in;
}
*/

#endif
