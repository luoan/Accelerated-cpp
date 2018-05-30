#include <iostream>
#include <string>

int main()
{
  {
    std::string s = "a string";
    {
      std::string x = s + ", really";
      std::cout << s << std::endl;// if std::cout x is // then
                                  // will print a string
    }
    //std::cout << x << std::endl;// x not declared
  }
  return 0;
}
