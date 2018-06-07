#include <iostream>
#include <ios>
#include <string>
#include <iomanip>

int main()
{
  std::cout << "Please input your name: ";
  std::string name;
  std::cin >> name;

  std::cout << "Hello, " + name + "!";
  std::cout << "PLease input your midterm and final exam grades: ";
  double midterm, final;
  std::cin >> midterm >> final;

  std::cout << "enter all your homework grades,"
    "followed by end-of-file: ";

  int count = 0;
  double sum = 0;
  double x;
  while (std::cin >> x) {
    count++;
    sum += x;
  }
  std::streamsize prec = std::cout.precision();
  std::cout << "YOur final grades is " << std::setprecision(3)
    << 0.2*midterm + 0.4*final + 0.4*sum/count
    << "   test1.2345:  " << 1.2345  << "   "
    << std::setprecision(prec) 
    << "test1.2345:  " << 1.2345 <<std::endl;
  
  return 0;
}
