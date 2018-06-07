#include <iostream>
#include <string>

int main()
{
  std::string s = "hello";
  std::string t(s);
  std::string r("hallo");

  std::cout << t << std::endl;
  std::cout << r << std::endl;

  return 0;
}
