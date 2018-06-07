#include <iostream>

void dosth(const int* pc) {
  std::cout << *pc << std::endl;
}

int main()
{
  //const char* cp = new char('a');
  //char* cp2 = cp;
  int const* pc1 = new int('k');
  //int* pc2 = pc1;
  const int* pc2 = pc1;
  dosth(pc1);
  return 0;
}


