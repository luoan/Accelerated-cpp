#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> u(10, 100);
  std::vector<int> v;
  //std::copy(u.begin(), u.end(), v.begin());
  std::copy(u.begin(), u.end(), back_inserter(v));

  return 0;
}
