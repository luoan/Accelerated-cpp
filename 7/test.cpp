#include <list>
#include <string>
#include <iostream>

using namespace std;

int main()
{
  list<string> ret;
  string s;

  while (cin >> s)
    ret.push_back(s);

  for (list<string>::iterator it = ret.begin(); 
      (it+1) != ret.end(); ++it ) {
    
    cout << *(it) << " ";
  }
  cout << endl;
  return 0;
}
