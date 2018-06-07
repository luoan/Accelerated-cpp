#include <iostream>
#include <string>

template <class In, class  In2>
bool myequal(In begin, In end, In2 begin2)
{
  while (begin != end) {
    if (*begin != *begin2)
      return false;
    begin++;
    begin2++;
  }
  return true;
}

int main()
{
  std::string s;

  s = "rehher";
  //std::cout << equal(s.begin(), s.end(), s.rbegin()) << std::endl;
  if (myequal(s.begin(), s.end(), s.rbegin()))
    std::cout << "equal" << std::endl;
  return 0;
}
