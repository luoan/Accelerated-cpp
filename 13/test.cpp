#include <iostream>
#include <string>
#include <vector>

class base {
  public :
    base() : value(0) { }
    virtual ~base() { }
    virtual int val() const { return value; }
  private :
    int value;
};

class derive : public base {
  public :
    derive() : haha(1) { }
    virtual int val() const { return haha; }
    int haha;
  private :
  
};

int main()
{
  base* bp1;
  base* bp2;
  bp1 = new base;
  bp2 = new derive;

  std::cout << "base: " << bp1->val() << std::endl;
  std::cout << "derive: " << bp2->val() /*<< " " << bp2->haha */<< std::endl;

  return 0;
}
