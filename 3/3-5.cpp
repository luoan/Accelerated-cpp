#include <iostream>
#include <string>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <vector>

int main()
{
  std::vector<std::string> names;
  std::vector<double> grades;

  //std::string s;
  bool finish = false;

  while (finish != true) {
    std::string s;
    std::cout << "Please input students name: ";
    std::cin >> s;
    names.push_back(s);
    std::cout << "Please input " << s << " midterm and final grades: ";
    double midterm, final;
    std::cin >> midterm >> final;

    std::cout << "Please input all " << s << " 3 times homework grades: ";
    double x, sum=0;
    for (int i = 0; i < 3; ++i) {
      std::cin >> x;
      sum += x;
    }
    double average = sum / 3;
    grades.push_back(midterm*0.2 + final*0.4 + average*0.4);

    std::cout << "More? y or n: ";
    char c;
    std::cin >> c;
    if (c == 'y')
      finish = false;
    else 
      finish = true;
  }

  for (std::vector<std::string>::size_type i = 0; i < names.size(); ++i)
    std::cout << names[i] << "\t" << grades[i] << std::endl;
  
  return 0;
}

