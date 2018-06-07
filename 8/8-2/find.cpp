#include <iostream>

template <class In, class X>
In myfind(In b, In e, const X& x)
{
  while (b != e) {
    if (*b == x)
      return b;
    ++b;
  }

  return e;
}

int main()
{
  std::string s;
  s = "hallo";

  char c = 'o';
  if (myfind(s.begin(), s.end(), c) != s.end())
    std::cout << "find it" << std::endl;
  c = 'k';
  if (myfind(s.begin(), s.end(), c) == s.end())
    std::cout << "did not find it" << std::endl;
  return 0;
}
