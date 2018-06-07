#include <iostream>
#include <vector>

int main()
{
  std::vector<int> u(10, 100);
  std::vector<int> v;
  v.insert(v.end(), u.begin(), u.end());

  return 0;
}
