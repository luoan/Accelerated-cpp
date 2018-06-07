#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>

//#include "url.h"
#include "xref.h"

int main()
{
 // std::fstream infile;
 // infile.open("doc.txt");
  std::map<std::string, std::vector<int> > ret = xref(std::cin);

  for (std::map<std::string, std::vector<int> >::const_iterator it = ret.begin();
      it != ret.end(); ++it) {
    if (it->second.size() == 1)
      std::cout << it->first << " occurs on line: ";
    else 
      std::cout << it->first << " occurs on lines: ";

    std::vector<int>::const_iterator line_it = it->second.begin();
    std::cout << *line_it;

    ++line_it;
    
    while (line_it != it->second.end()) {
      std::cout << ", " << *line_it;
      ++line_it;
    }

    std::cout << std::endl;
  }

  return 0;
}
