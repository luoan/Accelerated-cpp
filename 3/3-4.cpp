#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::string max, min;

  std::cin >> s;
  max = min = s;
  while (std::cin >> s) {
    if (s.size() > max.size())
      max = s;
    if (s.size() < min.size())
      min = s;
  }

  std::cout << "longest:\t" << max << std::endl;
  std::cout << "shortest\t" << min << std::endl;

  return 0;
}
