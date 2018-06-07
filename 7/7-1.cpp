#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
  std::map<std::string, int> counters;
  std::map<int, std::vector<std::string> > order_by_count;

  std::string s;
  while (std::cin >> s)
    ++counters[s];

  for (std::map<std::string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) 
    order_by_count[it->second].push_back(it->first);

  for (std::map<int, std::vector<std::string> >::const_iterator it = order_by_count.begin(); 
      it != order_by_count.end(); ++it) {
    
    std::cout << it->first << std::endl;
    for (std::vector<std::string>::const_iterator it_in_vector = it->second.begin(); 
        it_in_vector != it->second.end(); ++it_in_vector)
      std::cout << "  " << *it_in_vector;
    std::cout << std::endl << std::endl;

  }

  std::cout << std::endl;
  return 0;
}
