#include <iostream>
#include <vector>

template <class In, class T>
T myaccumulate(In b, In e, T t)
{
  while (b != e)
    t +=  *b++;

  return t;
}

int main()
{
  // iterator not array!!!!!!!
  // double a[] = {1, 35, 8, 9, 13};
  //std::cout <<  (double) myaccumulate(a[0], sizeof(a)/a[0], 0.0) << std::endl;
  
  int a[] = {3, 13, 5, 9, 19};
  std::vector<int> va;
  for (int i = 0; i != sizeof(a)/a[0]; ++i)
    va.push_back(a[i]);

  std::cout << va.size() << std::endl;
  std::cout << myaccumulate(va.begin(), va.end(), 0.1) << std::endl;
  return 0;
}
