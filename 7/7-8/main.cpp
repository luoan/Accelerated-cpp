#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>

#include "url.h"
#include "xref.h"

int main()
{
  std::fstream infile;
  infile.open("doc.txt");
  std::map<std::string, std::vector<int> > ret = xref(infile, find_urls);

  std::cout << std::endl;
  std::string::size_type maxlen = 0;
  for (std::map<std::string, std::vector<int> >::const_iterator it = ret.begin();
      it != ret.end(); ++it) {
    maxlen = std::max(maxlen, it->first.size());
  }

  for (std::map<std::string, std::vector<int> >::const_iterator it = ret.begin();
      it != ret.end(); ++it) {
    std::cout << it->first << std::string(maxlen - it->first.size(), ' ')
      << " occurs on line(s): ";

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
