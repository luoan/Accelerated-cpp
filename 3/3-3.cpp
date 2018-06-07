#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
  std::string s;
  std::vector<std::string> words;
  std::vector<int> count;

  while (std::cin >> s) {
    bool state = false;

    for (std::vector<std::string>::size_type i = 0; 
        i < words.size(); ++i) {
      if (s == words[i]) {
        count[i]++;
        state = true;
        break;
      }
    }  
    if (state == false) {
      words.push_back(s);
      count.push_back(1);
    }
  }

  for (std::vector<std::string>::size_type i = 0; i < words.size(); ++i) {
    std::cout << words[i] << "\t" << count[i] << std::endl;
  }

  return 0;
}
