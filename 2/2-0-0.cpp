#include <iostream>
#include <string>

using std::cin; using std::cout;
using std::endl;  using std::string;

int main()
{
  cout << "Please input your name: ";
  string name;
  cin >> name;

  const string greeting = "Hello, " + name + "!";
  const int pad = 2;
  const int rows = pad*2 + 3;
  const string::size_type cols = greeting.size() + pad*2 + 2;

  cout << endl;

  for (int r = 0; r < rows; ++r) {
    string::size_type c = 0;
    while (c != cols) {
      if (r==0 || r==rows-1 || c==0 ||c==cols-1) {
        std::cout << "*";
        ++c;
      }
      else if (r == pad+1 && c == pad+1) {
        std::cout << greeting;
        c += greeting.size();
      }
      else {
        std::cout << " ";
        c++;
      }
    }
    std::cout << std::endl;
  }

  return 0;
}
