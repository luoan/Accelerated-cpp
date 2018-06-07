#include <iostream>
#include <string>
#include <vector>

class A;

void doanother(A* a) ;

class dosth {
public :
  void haha() {
    doanother(p);
  }
private :
  A* p;
};

class A {
  friend class dosth;
private :
  std::vector<std::string> data;
};

void doanother(A* a)
{
  std::cout << a->data.size() << std::endl;
}

int main()
{
  A a;
  
  return 0;
}
