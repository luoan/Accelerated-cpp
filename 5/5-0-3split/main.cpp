#include <iostream>
#include <vector>
#include <cctype>
#include <string>

#include "strhandle.h"

int main()
{
  std::string s;
  std::vector<std::string> vec;

  /*while (getline(std::cin, s)) {
    */
  getline(std::cin, s);
  vec = split(s);
  for (std::vector<std::string>::size_type i = 0;
    i != vec.size(); ++i) {
      std::cout << vec[i] << "  ";// << std::endl;
    }
  std::cout << std::endl; 
/*
  std::vector<std::string> frame_vec = frame(vec);
  for (std::vector<std::string>::size_type i = 0;
      i != frame_vec.size(); ++i) {
    std::cout << frame_vec[i] << std::endl;
  }
*/  
  std::vector<std::string> hcat_vec = hcat(vec, vec);

  std::cout << std::endl;
  for (std::vector<std::string>::size_type i = 0;
      i != hcat_vec.size(); ++i) {
    std::cout << hcat_vec[i] << std::endl;
  }
  return 0;
}
