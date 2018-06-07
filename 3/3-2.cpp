#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::cout << "Please input numbers followed by end-of-file: ";
  std::vector<double> numbers;
  double x;

  while (std::cin >> x) 
    numbers.push_back(x);

  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = numbers.size();
  if (size == 0) {
    std::cout << "you must input numbers, "
      "please try again!" << std::endl;
    return 1;
  }

  std::sort(numbers.begin(), numbers.end());

  for (vec_sz i = 0; i < size; ++i)
    std::cout << numbers[i] << "  ";
  std::cout << std::endl;

  for (vec_sz i = 0; i < size/4; ++i)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;

  for (vec_sz i = size/4; i < size/2; ++i)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;

  for (vec_sz i = size/2; i < size*3/4; ++i)//i < size/4*3; ++i)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;

  for (vec_sz i = size*3/4; i < size; ++i)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;

  return 0;
}
