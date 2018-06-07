#include <iostream>
#include <string>

template <class In>
In mysearch(In beg1, In end1, In beg2, In end2)
{
  while (beg1 != end1) {
    
    In tmp1 = beg1;
    In tmp2 = beg2;
    while (*tmp1 == *tmp2 && tmp1 != end1 && tmp2 != end2) {
      tmp1++;
      tmp2++;
    }
    if (tmp2 == end2)
      return beg1;
    else {
      beg1++;
      //beg2++;
    }
  }

  return end1;
}

int main()
{
  std::string s1, s2;

  s1 = "ahayouaregood";
  s2 = "goo";

  std::string::const_iterator it, it2;
  if ((it = 
        (
         mysearch(s1.begin(), s1.end(), s2.begin(), s2.end())
        )
      ) 
      != s1.end())

  std::cout << "find it" << std::endl;

  return 0;
}
