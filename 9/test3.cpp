#include <iostream>
#include <string>

int main()
{
  char* cp1 = "hello";
  std::string s;
  s += cp1;

  std::cout << s << std::endl;

  return 0;
}
