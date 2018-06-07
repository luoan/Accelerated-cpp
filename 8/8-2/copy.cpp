#include <iostream>
#include <string>

template <class In, class Out>
Out mycopy(In b, In e, Out o)
{
  while (b != e) {
    *o++ = *b++;
  }
  return o;
}

int main()
{
  std::string s1, s2;

  s1 = "hallo";
  mycopy(s1.begin(), s1.end(), back_inserter(s2));

  std::cout << s2 << std::endl;

  return 0;
}
