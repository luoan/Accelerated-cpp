#include <iostream>
#include <iomanip>

int main()
{
  for (int i = 1; i <=100; ++i) {
    std::cout << std::setw(3) << i 
      << std::setw(6) << i*i << std::endl;
  }

  return 0;
}
