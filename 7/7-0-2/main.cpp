#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>

#include "grammar.h"

int main()
{
  std::fstream infile;
  infile.open("grammar.txt");

  grammar g = read_grammar(infile);
  for (grammar::const_iterator it = g.begin(); it != g.end(); ++it) {
    std::cout << it->first << std::endl;

    // 这里it->second 是得到了一个vector，it->second.begin()及it2是一个迭代器,然后it3及(*it2).begin()也是一个迭代器
    // 这里用it2->begin()也可以,it2是一个迭代器，指向具体，所以也可以调用他指向的具体的东西的成员函数
    for (rule_collection::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
      /*for (rule::const_iterator it3 = (*it2).begin(); it3 != (*it2).end(); ++it3)*/
      for (rule::const_iterator it3 = it2->begin(); it3 != it2->end(); ++it3)
        std::cout << "\t" << *it3 << " ";
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl << std::endl;
  std::vector<std::string> sentence = gen_sentence(/*read_grammar(infile)*/ g);

  std::cout << std::endl << std::endl;
  std::vector<std::string>::const_iterator it = sentence.begin();
  if (!sentence.empty()) {
    std::cout << *it;
    ++it;
  }

  while (it != sentence.end()) {
    std::cout << " " << *it;
    ++it;
  }

  std::cout << std::endl;
  return 0;
}
