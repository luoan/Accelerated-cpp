#include <iostream>
#include <string>
#include <vector>
#include <cctype>

bool islower_word(const std::string& s)
{
  for (std::string::size_type i = 0; i != s.size(); ++i) {
    //std::cout << "In islower";
    if (isupper(s[i])) {
      return false;
    }
  }
  return true;
}

int main()
{
  std::string s;
  std::vector<std::string> v;

  while (std::cin >> s) {
    //std::cout << s  << " ";
    v.push_back(s);
  }

  std::vector<std::string> lower;
  std::vector<std::string>::size_type i = 0, count = 0;
  
  while (i != v.size()) {
    if (islower_word(v[i])) {
      lower.push_back(v[i]);
      std::cout << v[i] << "  ";
      ++i;
    }
    else {
      count++;
      v.insert(v.begin(), v[i]);
      i += 2;
    }
  }
  v.resize(count);

  std::cout << std::endl;
  for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
    std::cout << v[i] << "  ";

  std::cout << std::endl;

  return 0;
}
