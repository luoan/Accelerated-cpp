#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "str.h"

int main()
{
  std::vector<std::string> str;
  std::string s;

  getline(std::cin, s);
  str = split(s);

  std::cout << std::endl;
  for (std::vector<std::string>::const_iterator it = str.begin();
      it != str.end(); ++it) {
    std::cout << (*it) << std::endl;
  }

  std::cout << std::endl;
  std::vector<std::string> frame_str = frame(str);
  for (std::vector<std::string>::const_iterator it = frame_str.begin();
      it != frame_str.end(); ++it) 
    std::cout << (*it) << std::endl;

  std::cout << std::endl;
  std::vector<std::string> vcat_str = vcat(str, frame_str);
  for (std::vector<std::string>::const_iterator it = vcat_str.begin();
      it != vcat_str.end(); ++it)
    std::cout << (*it) << std::endl;

  std::cout << std::endl;
  std::vector<std::string> hcat_str = hcat(frame_str, vcat_str);
  for (std::vector<std::string>::const_iterator it = hcat_str.begin();
      it != hcat_str.end(); ++it)
    std::cout << (*it) << std::endl;

  std::cout << std::endl;
  std::vector<std::string> hcat2_str = hcat(vcat(hcat_str, str), vcat(hcat_str, vcat_str));
  for (std::vector<std::string>::const_iterator it = hcat2_str.begin();
      it != hcat2_str.end(); ++it) 
    std::cout << (*it) << std::endl;
  
  std::cout << std::endl;
  return 0;
}
