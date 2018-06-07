#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <algorithm>

#include "xref.h"
/*
bool space(char c)
{
  return isspace(c);
}

bool not_space(char c)
{
  return !isspace(c);
}

std::vector<std::string> split(const std::string& str)
{
  typedef std::string::const_iterator iter;
  std::vector<std::string> ret;

  iter i = str.begin();
  while (i != str.end()) {
    i = std::find_if(i, str.end(), not_space);

    iter j = std::find_if(i, str.end(), space);
    if (i != str.end())
      ret.push_back(std::string(i, j));

    i = j;
  }
  return ret;
}
*/
std::map<std::string, std::vector<int> >
    xref(std::istream& in,
         std::vector<std::string> find_words(const std::string& )/* = split*/)
{
  std::string line;
  int line_number = 0;
  std::map<std::string, std::vector<int> > ret;

  while (getline(in, line)) {
    ++line_number;
    
    std::vector<std::string> words = find_words(line);
    
    for (std::vector<std::string>::const_iterator it = words.begin();
        it != words.end(); ++it)
      if (std::find(ret[*it].begin(), ret[*it].end(), line_number) == ret[*it].end())
        ret[*it].push_back(line_number);
  }
  return ret;
}


