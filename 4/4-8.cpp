// f is a function that need no parameter
// and returns an array of double 
// and d get it's nth item

#include <iostream>
#include <vector>

std::vector<double> f()
{
  std::vector<double> ve;

  for (double i = 0; i < 10; ++i)
    ve.push_back(i);
  return ve;
}

int main()
{
  double d = f()[3];

  std::cout << d << std::endl;

  return 0;
}
