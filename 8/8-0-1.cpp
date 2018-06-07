#include <iostream>
#include <string>
#include <vector>

template <class T>
T mymax(const T& left, const T& right) 
{
  return left > right ? left : right;
}

template <class In, class X>
In fine(In begin, In end, const X& x)
{
  while (begin != end && *begin != x)
    ++begin;
  return begin;
}

template<class In, class Out>
Out copy(In begin, In end, Out dest)
{
  while (begin != end)
    *dest++ = *begin++;

  return dest;
}

template <class For, class X>
void myreplace(For beg, For end, X& x, X& y)//const X& x, const X& y)
{
  while (beg != end) {
    if (*beg == x)
      *beg = y;
    ++beg;
  }
}

int main()
{
  std::string s1, s2;
  std::vector<std::string> ret;

  ret.push_back("hallo");
  ret.push_back("good");
  ret.push_back("bad");
  
  s1 = "bad";
  s2 = "good";

  //myreplace(ret.begin(), ret.end(), s1, s2);
  myreplace(ret.begin(), ret.end(), "bad", "good");
  for (std::vector<std::string>::const_iterator it = ret.begin();
      it != ret.end(); ++it)
    std::cout <<  *it << std::endl;

  return 0;
}
