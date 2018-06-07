#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "url.h"
#include "xref.h"

int main()
{
  std::map<std::string, std::vector<int> > ret = xref(std::cin, find_urls);

  for (std::map<std::string, std::vector<int> >::const_iterator it = ret.begin();
      it != ret.end(); ++it) {
    std::cout << it->first << " occurs on line(s): ";

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
