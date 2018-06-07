#include <iostream>
#include <string>

template <class In, class Out, class X>
Out myremove_copy(In b, In e, Out d, const X& x)
{
  while (b != e) {
    if (*b != x)
      *d++ = *b;
    ++b;
  }
  return d;
}

int main()
{
  std::string s1, s2;

  s1 = "hallo apple how are you";
  myremove_copy(s1.begin(), s1.end(), back_inserter(s2), ' ');

  std::cout << s2 << std::endl;

  return 0;
}
