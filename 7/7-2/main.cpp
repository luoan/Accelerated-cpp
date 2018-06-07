#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ios>
#include <iomanip>
#include <stdexcept>
#include <map>

#include "grade.h"
#include "student_info.h"

struct node {
  int count;// = 0;
  std::vector<std::string> names;
};

int main()
{
  char get_level(double );

  std::vector<student_info> students;
  student_info record;
  std::string::size_type maxlen = 0;

  while (read(std::cin, record)) {
    /* if (record.name.size() > maxlen)
      maxlen = record.name.size();
    */
    maxlen = std::max(maxlen, record.name.size());
    students.push_back(record);
  }

  std::sort(students.begin(), students.end(), compare);
  
  std::cout << std::endl;

  
  std::map<char, node> s_level;
  
  for (std::vector<student_info>::size_type i = 0; 
      i != students.size(); ++i) {
    double f_grade = grade(students[i]);
    char l = get_level(f_grade);
    //s_level[l][0]++;
    s_level[l].count++;
    s_level[l].names.push_back(students[i].name);
  }

  // 此处it->second得到了一个node，我们可以直接进行.引用成员，
  // 你要是觉得没有事情做(&(it->second))->count也是可以的
  //                   ->就是直接能够得到元素了，.与->取元素这些都是得到的是
  //                   元素，->前面要是地址
  for (std::map<char, node>::const_iterator it = s_level.begin();
      it != s_level.end(); ++it) {
    std::cout << it->first << "\t ";
    std::cout << "has : " << (&(it->second))->count << " ";
    //std::cout << "has : " << it->second.count << "  ";
    for (std::vector<std::string>::const_iterator it2 = (it->second.names).begin(); 
        it2 != (it->second.names).end(); ++it2)
      std::cout << *it2 << "  ";

    std::cout << std::endl;
  }
  /*
  std::map<char, std::vector<std::string> > s_level;
  
  for (std::vector<student_info>::size_type i = 0;
        i != students.size(); ++i) {
    double f_grade = grade(students[i]);
    char l = get_level(f_grade);
    s_level[l].push_back(students[i].name);
  }
  
  for (std::map<char, std::vector<std::string> >::const_iterator it = s_level.begin(); it != s_level.end(); ++it) {
    std::cout << it->first << "\t ";
    // 这里it->second是一个vector，it->second.begin()是一个迭代器，需要解引用来使用
    for (std::vector<std::string>::const_iterator it2 =it->second.begin(); it2 != it->second.end(); ++it2)
      std::cout << *it2 << " ";
    std::cout << std::endl;
  }*/
  return 0;
}

char get_level(double f)
{
  if (f >=90 && f <= 100)
    return 'A';
  else if (f >=80)
    return 'B';
  else if (f >= 70)
    return 'C';
  else if (f >= 60)
    return 'D';
  else 
    return 'F';
}
