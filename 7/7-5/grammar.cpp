#include <iostream>
#include <string>
#include <list>
#include <map>
#include <stdlib.h>
#include <stdexcept>

#include "grammar.h"
#include "split.h"

grammar read_grammar(std::istream& in)
{
  std::string line;
  grammar ret;

  while (getline(in, line)) {
    
    std::list<std::string> entry = split(line);
    if (!entry.empty())
      ret[*entry.begin()].push_back(
          rule(++entry.begin(), entry.end())
          );
  }
  return ret;
}

std::list<std::string> gen_sentence(const grammar& g)
{
  std::list<std::string> ret;

  gen_aux(g, "<sentence>", ret);

  return ret;
}

bool bracketed(const std::string& s)
{
  return s.size() > 1 && s[0] == '<' && s[s.size()-1] == '>';
}

void gen_aux(const grammar& g, const std::string& word, std::list<std::string>& ret)
{
  if (!bracketed(word)) {
    ret.push_back(word);
  }
  else {
    grammar::const_iterator it = g.find(word);
    //const rule_collection& c = it->second;

    int random_num = nrand(it->second.size());
    rule_collection::const_iterator it2 = it->second.begin();
    for (int i =0; i < random_num; ++i)
      it2++;

    for (rule::const_iterator it3 = it2->begin(); it3 != it2->end(); ++it3)
      gen_aux(g, *it3, ret);
  }
}

int nrand(int n)
{
  if (n <= 0 || n > RAND_MAX)
    throw std::domain_error("argument to nrand is out of rang");

  const int bucket_size = RAND_MAX / n;

  int r;

  do r = rand() / bucket_size;
  while (r >= n);

  return r;
}
