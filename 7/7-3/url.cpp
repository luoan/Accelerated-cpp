#include "url.h"

#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

std::vector<std::string> find_urls(const std::string& s)
{
  std::vector<std::string> ret;
  typedef std::string::const_iterator iter;
  iter b = s.begin(), e = s.end();

  while (b != e) {
    b = url_beg(b, e);

    if (b != e) {
      iter after = url_end(b, e);

      ret.push_back(std::string(b, after));

      b = after;
    }
  }
  return ret;
}

std::string::const_iterator url_beg(std::string::const_iterator b,
                                    std::string::const_iterator e)
{
  static const std::string sep = "://";

  typedef std::string::const_iterator iter;

  iter i = b;

  while ((i = std::search(i, e, sep.begin(), sep.end())) != e) {
    
    if (i != b && i + sep.size() != e) {
      
      iter beg = i;
      while (beg != b && isalpha(beg[-1]))
        --beg;

      if (beg != i && !not_url_char(i[sep.size()]))
        return beg;
    }

    i += sep.size();
  }

  return e;
}

bool not_url_char(char c)
{
  static const std::string url_ch = "-;/:@=&$~_.+!*(),'";

  return !(isalnum(c) || 
      std::find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}


std::string::const_iterator url_end(std::string::const_iterator b, std::string::const_iterator e)
{
  return std::find_if(b, e, not_url_char);
}

