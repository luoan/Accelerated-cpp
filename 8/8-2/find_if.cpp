#include <iostream>
#include <string>

template <class In, class Function>
In myfind_if(In b, In e, Function f)
{
  while (b != e) {
    if (f(*b))
      return b;
    ++b;
  }

  return e;
}

bool space(char c)
{
  return c == ' ';
}
int main()
{
  std::string s;
  s = "this isagoodmoering";

  if (myfind_if(s.begin(), s.end(), space) != s.end())
    std::cout << "find it" << std::endl;

  s = "thisisagoodmorning";
  if (myfind_if(s.begin(), s.end(), space) == s.end())
    std::cout << "did not find it" << std::endl;

  return 0;
}
