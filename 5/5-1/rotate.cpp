#include <string>
#include <vector>
#include <cctype>
#include <iostream>

#include "rotate.h"
#include "str.h"

std::vector<std::string> rotate(const std::vector<std::string>& v)
{
  std::vector<std::string> ret;
  
  for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i) {
    std::string s;
    
    for (std::vector<std::string>::size_type j = i; j != v.size(); ++j) {
      s += v[j] + " ";
    }
    for (std::vector<std::string>::size_type j = 0; j != i; ++j) {
      s += v[j] + " ";
    }

    ret.push_back(s);
  }
  return ret;
}


std::vector<std::string>::size_type find_key(const std::vector<std::string>& v,
                                              const std::vector<std::string>& key)
{
  for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i) 
    for (std::vector<std::string>::size_type j = 0; j != key.size(); ++j)
      if (v[i] == key[j])
        return i;
}

void rerotate(const std::vector<std::string>& vstore,
              const std::vector<std::string>& vkey,
              std::vector<std::string>& vleft,
              std::vector<std::string>& vright)
{
  for (std::vector<std::string>::size_type i = 0; i != vstore.size(); ++i) {
   // std::cout << vstore.size() << std::endl;
    //std::cout << "in ro" << std::endl;
    //std::cout << "in re " << vstore[i];
    std::vector<std::string> tmp = split(vstore[i]);
   // std::cout << "d" << vkey[0] << std::endl;
    std::string sright, sleft;
    
    std::vector<std::string>::size_type key_place;
    key_place = find_key(tmp, vkey);
   // std::cout << "keyf" << key_place << std::endl;
    std::vector<std::string>::size_type j;
    for (/*std::vector<std::string>::size_type*/ j = 0; j != key_place; ++j)
      sright += tmp[j] + " ";
    sright += tmp[j];
    //std::cout << "sright " << sright <<  std::endl;
    
    for (j = key_place+1; j < tmp.size()-1; ++j)
      sleft += tmp[j] + " ";
    if (j == tmp.size()-1)
      sleft += tmp[j] + "  ";

    // here wrong !!!!! not != but < !!!!!!!!! 
    // * for (/*std::vector<std::string>::size_type*/ j = key_place + 1; j != tmp.size()-1; ++j) 
    /*  sleft += tmp[j] + " ";
    sleft += tmp[j] + "\t";
    */
    //std::cout << "left" << sleft << "left" << std::endl;
    vleft.push_back(sleft);
    vright.push_back(sright);
    /*  // to find the place cost less time, donot need to find everytime nono
     *   // no no may be the same time cause when we find it we leave the first for loop
    for (std::vector<std::string>::size_type j = 0; j != tmp.size(); ++j) {
      
      bool find_key = false;
      
      for (std::vector<std::string>::size_type k = 0; k != vkey.size(); ++k) 
        if (tmp[j] == vkey[k])
          find_key = true;

      if (find_key == false)
        sright += tmp[j] + " ";
      else {
        sright += tmp[j];
        break;
      }
    }

    for (std::vector<std::string>::size_type k = j; k != tmp.size(); ++j) 
  */
  }
}
