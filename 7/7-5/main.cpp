#include <iostream>
#include <string>
#include <list>
#include <map>
#include <fstream>

#include "split.h"
#include "grammar.h"

int main()
{
  std::fstream infile;
  infile.open("grammar.txt");
  grammar g;
  g = read_grammar(infile);
  for (grammar::const_iterator it = g.begin(); it != g.end(); ++it) {
    std::cout << it->first << std::endl;

    for (rule_collection::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
      
      for (rule::const_iterator it3 = it2->begin(); it3 != it2->end(); ++it3)

        std::cout << *it3 << "   ";

      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;

  std::list<std::string> ret = gen_sentence(g);
  for (std::list<std::string>::const_iterator it = ret.begin(); it != ret.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
  return 0;
  /*
  std::list<std::string> ret;
  std::string s;

  getline(std::cin, s);
  ret = split(s);

  for ( std::list<std::string>::const_iterator it = ret.begin();
      it != ret.end(); ++it)
    std::cout << *it << std::endl;


  return 0;
  */
}
