#include <iostream>
#include <vector>

int main()
{
  std::vector<double> numbers;
  double x;

  while (std::cin >> x)
    numbers.push_back(x);

  double sum = 0;
  for (std::vector<double>::size_type i = 0; i != numbers.size(); ++i) {
    sum += numbers[i];
  }

  std::cout << "average is : "
    << sum / numbers.size() << std::endl;

  return 0;
}
