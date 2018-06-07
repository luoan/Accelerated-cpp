#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "grammar.h"

int main()
{
  std::fstream infile;
  infile.open("grammar.txt");

  grammar g = read_grammar(infile);

  std::vector<std::string> ret = gen_sentence(g);

  for (std::vector<std::string>::const_iterator it = ret.begin();
      it != ret.end(); ++it)
    std::cout << *it << "  ";

  std::cout << std::endl;
  return 0;
}
