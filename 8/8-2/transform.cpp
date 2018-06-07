#include <iostream>
#include <string>
#include <cctype>

template <class In, class Out, class Function>
Out mytransform(In b, In e, Out dest, Function f)
{
  while (b != e) {
    *dest++ = f(*b);
    b++;
  }
  return dest;
}

char mytoupper(char c)
{
  return toupper(c);
}

int main()
{
  std::cout << toupper('a') << std::endl;
  std::cout << mytoupper('a') << std::endl;

  std::string s1, s2;

  s1 = "haLLO, hEI";
  mytransform(s1.begin(), s1.end(), back_inserter(s2), mytoupper);
  std::cout << s2 << std::endl;

  return 0;
}
