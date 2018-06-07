#ifndef _XREF_H_
#define _XREF_H_


#include <map>
#include <string>
#include <vector>
#include <cctype>

#include "split.h"
/*
bool space(char );
bool not_space(char );
std::vector<std::string> split(const std::string& );
*/
std::map<std::string, std::vector<int> >
    xref(std::istream& in, 
         std::vector<std::string> find_words(const std::string& ) = split);


#endif
