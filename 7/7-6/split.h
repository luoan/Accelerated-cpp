#ifndef _SPLIT_H_ 
#define _SPLIT_H_


#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

bool space(char );
bool not_space(char );

std::vector<std::string> split(const std::string& );
/*
bool space(char c)
{
  return isspace(c);
}

bool not_space(char c)
{
  return !isspace(c);
}

std::vector<std::string> split(const std::string& s)
{
  typedef std::string::const_iterator iter;
  iter b = s.begin(), e = s.end();
  std::vector<std::string> ret;

  iter i = b;
  while (i != e) {
    i = std::find_if(i, e, not_space);
    iter j = std::find_if(i, e, space);

    if (i != e) {
      ret.push_back(std::string(i, j));
      i = j;
    }
  }
  return ret;
}
*/
#endif
