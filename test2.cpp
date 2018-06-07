#include <iostream>
#include <vector>


class A {
  friend void dosth(A& );
public :
  A() : num(1) { }
  void show() const { std::cout << num << std::endl; }
private :
  int num;
};

void doanother(A& a)
{
  std::cout << "++a.num= " << ++a.num << std::endl;
}

void dosth(A& a)
{
  doanother(a);
}

int main()
{
  A a;
  dosth(a);

  return 0;
}

/*
//这里可以通过类的友元传递类的私有变量的引用来使得非友元也能够访问类的私有成员
class A {
friend void dosth(A& );
public :
  A() : num(1) { }
  void show() const { std::cout << num << std::endl; }
private :
  int num;
};

void doanother(int& n) { n++; }

void dosth(A& a)
{
  doanother(a.num);
}

int main()
{
  A a;
  a.show();
  dosth(a);
  
  a.show();
  return 0;
}

*/
