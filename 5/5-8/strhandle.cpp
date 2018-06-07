#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

#include "strhandle.h"

std::vector<std::string> split(const std::string& s)
{
  std::vector<std::string> ret;
  typedef std::string::size_type str_size;
  
  str_size i = 0;
  while (i != s.size()) {
    while (i != s.size() && isspace(s[i]))
      i++;
    str_size j = i;
    while (j != s.size() && !isspace(s[j]))
      j++;
    if (i != j) {
      ret.push_back(s.substr(i, j-i));
      i = j;
    }
  }
  return ret;
}

std::vector<std::string> frame(const std::vector<std::string>& v)
{
  //typedef std::vector<std::string>::size_type vec_sz;
  const std::string::size_type maxlen = width(v);
  const std::string border(maxlen + 4, '*');
  std::vector<std::string> ret;
  
  ret.push_back(border);
  for (std::vector<std::string>::const_iterator it = v.begin();
      it != v.end(); ++it) {
    ret.push_back("* " + (*it) + std::string(maxlen-(*it).size(), ' ') + " *");
  }
  ret.push_back(border);

  return ret;
}

std::vector<std::string> vcat(const std::vector<std::string>& t,
                              const std::vector<std::string>& b) 
{
  std::vector<std::string> ret = t;
  ret.insert(ret.end(), b.begin(), b.end());
  return ret;
}

std::string::size_type width(const std::vector<std::string>& v)
{
  std::string::size_type maxlen = 0;

  for (std::vector<std::string>::const_iterator iter = v.begin();
      iter != v.end(); ++iter) {
    maxlen = std::max(maxlen, (*iter).size());     
  }
  return maxlen;
}


std::vector<std::string> hcat(const std::vector<std::string>& left,
                              const std::vector<std::string>& right)
{
  std::vector<std::string> ret;

  std::string::size_type width1 = width(left) + 1;
  std::vector<std::string>::size_type i = 0, j = 0;

  std::string s;
  while (i != left.size() || j != right.size()) {
    //std::string s;
    if (i != left.size())
      s = left[i++];
    
    s += std::string(width1-s.size(), ' ');
    if (j != right.size())
      s += right[j++];
    ret.push_back(s);
  }
  return ret;
}
