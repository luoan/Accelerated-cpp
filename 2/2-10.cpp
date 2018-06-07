#include <iostream>

int main()
{
  int k = 0;
  while (k != 10) {
    using std::cout;//only useful in the while block
    cout << "*";
    k++;
  }
  //cout << "haha";//error cout not declared
  std::cout << std::endl;
  return 0;
}
