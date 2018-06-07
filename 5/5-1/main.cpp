#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "str.h"
#include "rotate.h"

int main()
{
  std::string s;
  //std::vector<std::string> v;
  std::vector<std::string> vstore, vfinal, vleft, vright;
  std::vector<std::string> vkey;

  /*getline(std::cin, s);
  std::vector<std::string> v = split(s);
  std::vector<std::string> vrotate = rotate(v);
  vkey.push_back(std::string("fox"));
  rerotate(vrotate, vkey, vleft, vright);

  for (std::vector<std::string>::const_iterator it = vrotate.begin();
      it != vrotate.end(); ++it)
    std::cout << (*it) << std::endl;
*/
  while (getline(std::cin, s)) {
    std::vector<std::string> v = split(s);
    vkey.push_back(v[v.size()-1]);
    std::vector<std::string> vrotate = rotate(v);
    vstore.insert(vstore.end(), vrotate.begin(), vrotate.end());
  }
  std::sort(vstore.begin(), vstore.end()) ; 
  rerotate(vstore, vkey, vleft, vright);

  vfinal = hcat(vleft, vright);
  
  std::cout << std::endl;
  for (std::vector<std::string>::const_iterator it = vfinal.begin();
      it != vfinal.end(); ++it)
    std::cout << (*it) << std::endl;
 
  return 0;
}
