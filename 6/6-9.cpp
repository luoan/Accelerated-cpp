#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
  std::string s;
  std::vector<std::string> v;

  while (std::cin >> s) 
    v.push_back(s);

  std::string str;
  for (std::vector<std::string>::const_iterator iter = v.begin();
      iter != v.end(); ++iter)
    std::copy((*iter).begin(), (*iter).end(), back_inserter(str))  ;

  std::cout << str << std::endl;

  return 0;
}
