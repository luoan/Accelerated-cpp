#include <iostream>
#include <vector>

int main()
{
  std::vector<int>* vp = new std::vector<int>;
  vp->push_back(3);
  vp->push_back(6);
  vp->push_back(9);
    
  return 0;
}
