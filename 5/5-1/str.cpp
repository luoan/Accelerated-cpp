#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

#include "str.h"
/*
std::string::size_type width(const std::vector<std::string>& v)
{
  std::string::size_type maxlen = 0;

  for (std::vector<std::string>::const_iterator it = v.begin();
        it != v.end(); ++it)
    maxlen = std::max(maxlen, (*it).size());

  return maxlen;
}*/

std::vector<std::string> split(const std::string& s)
{
    typedef std::string::size_type str_sz;
    std::vector<std::string> ret;
    str_sz i = 0;

    while (i != s.size()) {
        while (i != s.size() && isspace(s[i]))
            i++;
        str_sz j = i;
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
  std::vector<std::string> ret;
  std::string::size_type maxlen = width(v);

  std::string border(maxlen+4, '*');
  ret.push_back(border);
  for (std::vector<std::string>::const_iterator it = v.begin();
      it != v.end(); ++it) 
    ret.push_back("* " + (*it) + std::string(maxlen-(*it).size(), ' ') + " *");
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

std::vector<std::string> hcat(const std::vector<std::string>& l,
                              const std::vector<std::string>& r)
{
  std::string::size_type leftlen = width(l);
  std::vector<std::string>::size_type i=0, j=0;
  std::vector<std::string> ret;

  while (i != l.size() || j != r.size()) {
    std::string s;
    if (i != l.size()) {
      //s += l[i++];
      s += std::string(leftlen-l[i].size(), ' ');
      s += l[i++];
    }
    if (j != r.size())
      s += r[j++];
    ret.push_back(s);
  }
  return ret;
}

std::string::size_type width(const std::vector<std::string>& v)
{
  std::string::size_type maxlen = 0;

  for (std::vector<std::string>::const_iterator it = v.begin();
        it != v.end(); ++it)
    maxlen = std::max(maxlen, (*it).size());

  return maxlen;
}

