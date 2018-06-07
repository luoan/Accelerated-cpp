#ifndef _STR_HANDLE_H 
#define _STR_HANDLE_H


#include <string>
#include <vector>
#include <cctype>

std::vector<std::string> split(const std::string& );

std::vector<std::string> frame(const std::vector<std::string>& );

std::vector<std::string> vcat(const std::vector<std::string>&,
                        const std::vector<std::string>& );

std::vector<std::string> hcat(const std::vector<std::string>&,
                        const std::vector<std::string>& );

std::string::size_type width(const std::vector<std::string>& );

#endif
