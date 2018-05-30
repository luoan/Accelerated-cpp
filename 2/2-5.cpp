#include <iostream>

int main()
{
  std::cout << "Please input lines: ";
  int lines;
  std::cin >> lines;

  const int colums = lines*2-1;

  for (int i = 0; i < lines; ++i) {
    for (int j = 0; j < colums; ++j) {
      if (j >= colums/2-i && j <= colums/2+i)
        std::cout << "*";
      else 
        std::cout << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
