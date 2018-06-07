#include <string>
#include <list>
#include <algorithm>
#include <cctype>

#include "split.h"

bool space(char c)
{
  return isspace(c);
}

bool not_space(char c)
{
  return !isspace(c);
}

std::list<std::string> split(const std::string& s)
{
  typedef std::string::const_iterator iter;
  std::list<std::string> ret;

  iter i = s.begin();
  while (i != s.end()) {

    i = std::find_if(i, s.end(), not_space);
    iter j = std::find_if(i, s.end(), space);
    if (i != s.end()) {
      ret.push_back(std::string(i, j));
      i = j;
    }
  }
  return ret;
}
