#include <iostream>
#include <vector>
#include <string>

class A {
//friend void dosth(A& );
friend void dosth(A);
public :

private :
  void show() { std::cout << "in A " << std::endl; }
  std::vector<std::string> data;
};

/*
void doanother(std::vector<std::string>* a)
{
  // (*a).size() maybe is also ok
  a->push_back("haha");
  std::cout << "a.size() " << a->size() << std::endl;
}

void dosth(A& a)
{
  doanother(&a.data);
}
*/

/*
void doanother(std::vector<std::string>& a) 
{
  a.push_back("haha");
  std::cout << "a.szie() " << a.size() << std::endl;
}

void dosth(A& a)
{
  doanother(a.data);  
}
*/

void doanother(std::vector<std::string>& a)
{
  a.push_back("haha");
  std::cout << "a.size() " << a.size() << std::endl;
}

void dosth(A a)
{
  doanother(a.data);
}
int main()
{
  A a;
  dosth(a);

  return 0;
}
