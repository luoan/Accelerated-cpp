#include <iostream>

#include "student_info.h"
#include "core.h"

student_info::student_info(std::istream& is) : cp(0)
{
  read(is);
}

student_info::student_info(const student_info& s) :cp(0)
{
  if (s.cp) 
    cp = s.cp->clone();
}

student_info& student_info::operator=(const student_info& s)
{
  if (&s != this) {
    delete cp;
    if (s.cp)
      cp = s.cp->clone();
    else 
      cp = 0;
  }
  return *this;
}

std::istream& student_info::read(std::istream& is)
{
  delete cp;

  char ch;
  is >> ch;
  if (ch == 'u')
    cp = new core(is);
  else 
    cp = new grad(is);

  return is;
}
