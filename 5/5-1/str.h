#ifndef _STR_H_
#define _STR_H_


#include <string>
#include <vector>

std::string::size_type width(const std::vector<std::string>& );

std::vector<std::string> split(const std::string& );
//std::vector<std::string> frame(const std::vector<std::string>& );


std::vector<std::string> hcat(const std::vector<std::string>& top, 
                                const std::vector<std::string>& bottum );

//std::vector<std::string> vcat(const std::vector<std::string>& left,
//                                const std::vector<std::string>& right );




#endif
