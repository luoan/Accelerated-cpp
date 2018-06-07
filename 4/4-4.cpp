#include <iostream>
#include <iomanip>

int main()
{
  std::cout << "enter the lagest number: ";
  double max;
  std::cin >> max;
  std::streamsize fir = 1, sec=1;

  double tmp = max;
  while (tmp / 10 > 0.5) {
    fir++;
    tmp /= 10;
  }

  double squ = max*max;
  while (squ / 10 > 0.5) {
    sec++;
    squ /= 10;
  }

  
  for (double i = 1; i <= max; ++i) {
    std::cout << std::setw(fir) << i
      << std::setw(sec) << i*i << std::endl;
  }
  std::setw(0);

  return 0;
}
