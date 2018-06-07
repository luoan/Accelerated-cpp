#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "url.h"

int main()
{
  std::string s;
  std::vector<std::string> v;

  while (getline(std::cin, s)) {
    v = find_urls(s);
  }

  for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
    std::cout << v[i] << std::endl;


  return 0;
}
