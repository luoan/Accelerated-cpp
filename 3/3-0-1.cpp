#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>
#include <algorithm>

int main()
{
  std::cout << "PLease input your name: ";
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " + name + "!" << std::endl;

  std::cout << "Please input your midterm and final grades: ";
  double midterm, final;
  std::cin >> midterm >> final;

  std::cout << "Please input all your grades follewed by end-of-file: ";
  std::vector<double> homework;
  double x;
  while (std::cin >> x) {
    homework.push_back(x);
  }
  
  
  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = homework.size();
  if (size == 0) {
    std::cout << "you must enter your grades,"
      "please try again!" << std::endl;
    return 1;
  }
  std::sort(homework.begin(), homework.end());
  vec_sz mid = size/2;
  double median = size%2 == 0 ? (homework[mid] + homework[mid-1])/2
     : homework[mid];

  std::streamsize prec = std::cout.precision();
  std::cout << "Your final grade is " << std::setprecision(3)
    << 0.2*midterm + 0.4*final + 0.4*median 
    << std::setprecision(prec) << std::endl;

  return 0;
}
