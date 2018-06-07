#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::istream& read(std::istream& is, std::vector<std::string>& w)
{
  if (is) {
    w.clear();
    std::string s;
    while (is >> s) 
      w.push_back(s);
    is.clear();
  }
  return is;
}

int main()
{
  std::vector<std::string> words;

  read(std::cin, words);

  std::cout << "words counts: " << words.size() << std::endl;

  std::sort(words.begin(), words.end());
  int count = 0;
  std::string pre = "";

  for (std::vector<std::string>::size_type i = 0; i != words.size(); ++i) {
    std::cout << words[i] << "  ";
  }
  std::cout << std::endl;

  for (std::vector<std::string>::size_type i = 0; i != words.size(); ++i ) {
    if (words[i] != pre) {
      if (pre != "") {
        std::cout << pre << " appeared " 
          << count << " times" << std::endl;
      }
      count = 1;
      pre = words[i];    
    }
    else {
      ++count;
    }
  }
  std::cout << pre << " appeared " 
    << count << " times" << std::endl;

  return 0;
}
