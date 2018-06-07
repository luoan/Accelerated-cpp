#include <map>
#include <string>
#include <iostream>

int main()
{
  std::string s;
  std::map<std::string, int> counters;

  while (std::cin >> s) 
    ++counters[s];

  for (std::map<std::string, int>::const_iterator it = counters.begin();
      it != counters.end(); ++it) {
    std::cout << it->first << "\t" << it->second << std::endl;
  }

  return 0;
}
