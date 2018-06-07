#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> u(10, 100);
  std::vector<int> v;
  std::copy(u.begin(), v.begin(), back_inserter(v));

  return 0;
}
