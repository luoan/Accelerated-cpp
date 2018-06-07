#include <iostream>
#include <string>

/*
template <class T>
void myswap(T& a, T& b)
{
  T* pc = new T;
  *pc = a;
  a = b;
  b = *pc;
  delete pc;
}*/

template<class T>
void myswap(T& a, T& b)
{
  T tmp;
  tmp = a;
  a = b;
  b = tmp;
}

int main()
{
  std::string s = "ha";

  myswap(*s.begin(), *(s.end()-1));

  std::cout << s << std::endl;

  return 0;
}

