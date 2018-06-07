#include <iostream>
#include <iomanip>

std::streamsize getsize(int number)
{
  std::streamsize i = 1;
  while (number / 10 > 0) {
    i++;
    number /= 10;
  }
  return i;
}

int main()
{
  for (int i = 1; i <= 999; ++i) {
    std::streamsize num = getsize(i);
    std::streamsize squar = getsize(i*i);

    std::cout << std::setw(num) << i
      << std::setw(squar+1) << i*i
      << std::endl;
  }

  return 0;
}
