#include <iostream>

int main()
{
  int product = 1;

  long pro = 1;

  for (int i = 1; i < 10; ++i) {
    product *= i;
    pro *= i;
  }
  std::cout << product << std::endl;
  std::cout << pro << std::endl;

  return 0;
}
