#include <iostream>
#include <string>
#include <map>

int main()
{
  std::map<std::string, int> ret;

  ret["nihao"];

  std::map<std::string, int>::const_iterator it = ret.begin();

  std::cout << it->first << std::endl;
  std::cout << "second: " << it->second << std::endl;
  return 0;
}
