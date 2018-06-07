#ifndef _URL_H_
#define _URL_H_


#include <string>
#include <vector>

std::string::const_iterator url_beg(std::string::const_iterator b, 
                                    std::string::const_iterator e);

std::string::const_iterator url_end(std::string::const_iterator b,
                                    std::string::const_iterator e);

std::vector<std::string> find_urls(const std::string& );

bool not_url_char(char c);

#endif
