#include <iostream>
#include <string>

template <class For, class X>
For myremove(For b, For e, const X& x)
{
  For r = b;
  while (b != e) {
    if (*b != x) {
      //swap(b, r);no swap swap maybe hard to implement
      // just cover the dont needs
      *r = *b;//c++11 is not this way
      r++;
    }
    b++;
  }
  return r;
}

int main()
{
  std::string s1, s2;

  std::string::iterator it;// not const_iterator

  s1 = "aHaAaAaAyou";
 // char c = 'A';
  it = myremove(s1.begin(), s1.end(), 'A');
  std::cout << std::string(s1.begin(), it) << std::endl;

  return 0;
}
