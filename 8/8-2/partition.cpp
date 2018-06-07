#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

template <class T>
void myswap(T& a, T& b);


template <class Bi, class Function>
Bi mypartition(Bi b, Bi e, Function f)
{
  while (b != e) {
//    std::cout << "loop *b, *e: "
      //<< *b << std::endl;//" " << *e << std::endl;

    while (f(*b)) {
      ++b;
      //std::cout << "*b: " << *b << std::endl;
      if (b == e)
        return b;
    }
    
    do {
      --e;
      //std::cout <<"*e: " << *e << std::endl;
      if (b == e)
        return b;
    } while (!f(*e));//(!f(*b));

    myswap(*b, *e);

    ++b;
  }

  return b;
}

template <class T>
void myswap(T& a, T& b)
{
  T* pc = new T;
  *pc = a;
  a = b;
  b = *pc;
}

int main()
{
  std::string s;

  //s = "tiK iE odD E";
  s = "sTkIOpd";
  std::cout << s << std::endl;
  mypartition(s.begin(), s.end(), islower);
  //std::partition(s.begin(), s.end(), islower) ; 
  std::cout << s << std::endl;

  return 0;
}


