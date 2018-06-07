#include <vector>
#include <string>
#include <algorithm>

#include "str.h"

std::vector<std::string> frame(const std::vector<std::string>& v)
{
  std::vector<std::string> ret;
  std::string::size_type maxlen = width(v);
  std::string border(maxlen+4, '*');

  for (std::vector<std::string>::const_iterator it = v.begin();
      it != v.end(); ++it) {
    ret.push_back()
  }
}
