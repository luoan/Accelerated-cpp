#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "grammar.h"
#include "split.h"

grammar read_grammar(std::istream& in)
{
  grammar ret;
  std::string line;

  while (getline(in, line)) {
    std::vector<std::string> entry = split(line);

    if (!entry.empty())
      ret[entry[0]].push_back(
          rule(entry.begin() + 1, entry.end())
          );
  }

  return ret;
}

std::vector<std::string> gen_sentence(const grammar& g)
{
  std::vector<std::string> ret;
  gen_aux(g, "<sentence>", ret);
  return ret;
}

bool bracketed(const std::string& s)
{
  return s.size() > 1 && s[0] == '<' && s[s.size()-1] == '>';
}

void gen_aux(const grammar& g, const std::string& word, std::vector<std::string>& ret)
{
  if (!bracketed(word)) {
    ret.push_back(word);
  } else {
    
    grammar::const_iterator it = g.find(word);
    if (it == g.end())
      throw std::logic_error("empty rule");

    const rule_collection& c = it->second;
    
    std::cout << "in " << it->first << "  ";
    const rule& r = c[nrand(c.size())];

    for (rule::const_iterator i = r.begin(); i != r.end(); ++i)
      gen_aux(g, *i, ret);
  }
}

int nrand(int n)
{
  if (n <= 0 || n > RAND_MAX)
    throw std::domain_error("argument to nrand is out of range");

  const int bucket_size = RAND_MAX / n;
  int r;

  do r = rand() / bucket_size;
  while (r >= n);
  
  std::cout << "r= " << r << std::endl;
  return r;
}
