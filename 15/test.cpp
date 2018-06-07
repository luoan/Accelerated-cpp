#include <iostream>
#include <vector>
#include <string>

class a {
friend void dost(a& );
//friend void dosomething(std::vector<std::string>& );
public :
  void push_back(const std::string& s) {
    v.push_back(s);
  }
private :
  std::vector<std::string> v;
};

//void doanother(const std::vector<std::string>& );
void doanother(a& test) {
  //std::cout << *test.v.begin() << std::endl;
  //std::cout << test.v.size() << std::endl;
  //test.push_back("doanother insert");
}

void dost(a& test) {
  std::cout << test.v.size() << std::endl;
  //doanother(test);
}
/*
void dosomething(std::vector<std::string>& v)
{
  doanother(v);
}*/
/*
void doanother(std::vector<std::string>& v)
{
  std::cout << v.size() << std::endl;
}
*/
int main()
{
  a test;
  dost(test);
  /*
  a test;
  dosomething(test.v);//报错，是私有的
  test.push_back("hallo");
  dosomething(test.v);
*/
  return 0;
}


