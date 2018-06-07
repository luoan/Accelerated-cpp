#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>

#include "grammar.h"
#include "split.h"

grammar read_grammar(std::istream& is)
{
  grammar ret;

  std::string line;
  while (getline(is, line)) {
    std::vector<std::string> entry = split(line);

    if (!entry.empty()) {
      ret[entry[0]].push_back(rule(entry.begin()+1,
            entry.end()));
    }
  }

  return ret;
}

bool bracketed(const std::string& s)
{
  return s.size() > 1 && s[0] == '<' && s[s.size()-1] == '>';
}

int nrand(int n)
{
  if (n <= 0 || n > RAND_MAX)
    throw std::domain_error("Argument to nrand is out of range");

  const int bucket_size = RAND_MAX / n;

  int r;
  do r = rand() / bucket_size;
  while (r >= n);

  return r;
}

std::vector<std::string> gen_sentence(const grammar& g)
{
  std::vector<std::string> sentence, tokens;
  
  tokens.push_back("<sentence>");
  while (!tokens.empty()) {
    std::string token = tokens.back();
    tokens.pop_back();
    gen_aux(g, token, tokens, sentence);
  }

  return sentence;
}

void gen_aux(const grammar& g, const std::string& token, 
    std::vector<std::string>& tokens, 
    std::vector<std::string>& sentence)
{
  if (!bracketed(token))
    sentence.push_back(token);
  else {
    
    grammar::const_iterator it = g.find(token);
    if (it == g.end())
      throw std::logic_error("empty rule");

    const rule_collection& rc = it->second;
    const rule& c = rc[nrand(rc.size())];

    for (rule::const_reverse_iterator i = c.rbegin();
        i != c.rend(); ++i)
      tokens.push_back(*i);
  }
}
