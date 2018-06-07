#include <iostream>
#include <string>

int main()
{
  std::cout << "Please input your name: ";
  std::string name;
  std::cin >> name;

  const std::string greeting = "Hello, " + name + "!" ;
  //const std::string space(greeting.size(), ' ');
  
  std::cout << "Please input pad: ";
  int pad;
  std::cin >> pad;
  const int rows = pad*2 + 3;

  const std::string::size_type cols = greeting.size() + pad*2 + 2;
  const std::string space(greeting.size()+pad*2, ' ');
  //std::cout << cols << space << greeting << std::endl;
  
  for (int r = 0; r != rows; ++r) {
    std::string::size_type c = 0;
    while (c != cols) {
      if (c==pad+1 && r == pad+1) {
        std::cout << greeting;
        c += greeting.size();
      }
      else if (r == 0 || r == rows-1) {
        std::cout << std::string(cols, '*');
        c += cols;
      }
      else if (c == 0 || c == cols-1) {
        std::cout << "*";
        c++;
      }
      else if (r != pad+1 && c == 1) {
        std::cout << space;
        c += space.size();
      }
      else {
        std::cout << " ";
        c++;
      }
    }
    std::cout << std::endl;
  }
  /* //use less and wrong
  for (int r = 0; r != rows; ++r) {
    std::string::size_type c = 0;
    while (c < cols) {
      if (c == pad+1 && r == pad+1) {
        std::cout << greeting;
        c += greeting.size();
      }
      else if (r == 0 || r == rows-1) {
        std::cout << std::string(cols, '*');
        c += cols;
      }
      else if (c == 0 || c == cols-1) {
        std::cout << "*";
        c++;
      }
      else if (r != pad+1 && c == pad) {
        std::cout << space;
        c += space.size();
      }
      else {
        std::cout << "*";
        c++;
      }
    }
    std::cout << std::endl;
  }*/
  return 0;
}
