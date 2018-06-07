#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <cctype>

template <class Out>
void split(const std::string&, Out os);

template <class In>
void print(In b, In e);

int main()
{
  std::list<std::string> ret;

  std::string line;
  getline(std::cin, line);
  split(line, back_inserter(ret));
  print(ret.begin(), ret.end());

  return 0;
}

bool space(char c)
{
  return isspace(c);
}

bool not_space(char c)
{
  return !isspace(c);
}

template<class Out> 
void split(const std::string& str, Out os)
{
  typedef std::string::const_iterator iter;

  iter i = str.begin();
  while (i != str.end()) {
    
    i = std::find_if(i, str.end(), not_space);

    iter j = std::find_if(i, str.end(), space);
    
    if ( i != str.end())
      *os++ = std::string(i, j);

    i = j;
  }
}

template <class In>
void print(In b, In e)
{
  while (b != e) {
    std::cout << *b << std::endl;
    b++;
  }
}
