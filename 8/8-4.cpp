#include <iostream>
#include <string>

template<class T>
void myswap(T& a, T& b)
{
  T* cp = new T;
  *cp = a;
  a = b;
  b = *cp;
  delete cp;
}

int main()
{
  std::string s1 = "halo";
  std::string s2 = "nihao";

  std::cout << "s1: " << s1 << std::endl;
  std::cout << "s2: " << s2 << std::endl;

  std::cout << std::endl;
  myswap(s1, s2);
  std::cout << "s1: " << s1 << std::endl;
  std::cout << "s2: " << s2 << std::endl;

  return 0;
}
