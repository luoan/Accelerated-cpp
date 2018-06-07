#include <iostream>
#include <string>
#include <vector>

bool isreverse(const std::string& );

int main()
{
  std::string s;
  std::vector<std::string> v;
  std::string::size_type maxlen = 0;
  std::string maxs;

  while (std::cin >> s) {
    if (isreverse(s)) {
      maxlen = s.size();
      maxs = s;
      v.push_back(s);
    }
  }

  for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
    std::cout << v[i] << "  ";

  std::cout << std::endl;
  std::cout << maxs << std::endl;

  return 0;
}

bool isreverse(const std::string& s)
{
  for (std::string::size_type i = 0; i != s.size()/2; ++i) {
    if (s[i] == s[s.size()-i-1])
      continue;
    else 
      return false;
  }
  return true;
}
