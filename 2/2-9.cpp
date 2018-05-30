#include <iostream>

int main()
{
  int a, b;

  std::cout << "Please input first number: ";
  std::cin >> a ;
  std::cout /*<< std::endl*/ << "Please input second number: ";
  std::cin >> b;

  if (a > b)
    std::cout << "a is bigger" << std::endl;
  else if (a < b)
    std::cout << "b is bigger" << std::endl;
  else 
    std::cout << "equal" << std::endl;

  return 0;
}
