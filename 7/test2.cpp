#include <vector>
#include <map>
#include <string>

#include <iostream>

using namespace std;

int main()
{
  map<int, string> m;

  int a = 3;
  string s = "aha";
  m[a]=s;
  s  = "enhe";
  m[3]="ehe";
  for (map<int, string>::const_iterator it = m.begin(); it != m.end(); ++it)
    std::cout << it->first << "  " << it->second << std::endl;
  return 0;
}
