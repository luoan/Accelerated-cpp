#ifndef _XREF_H
#define _XREF_H


#include<map>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cctype>
/*
bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

template <class Out, class Ve>
Ve split(const std::string& s)
{
    typedef std::string::const_iterator iter;
    
    Ve ret;
    iter i = s.begin();
    while (i != s.end()) {
        iter i = std::find_if(i, s.end(), not_space);
        iter j = std::find_if(i, s.end(), space);
        if (i != s.end())
             ret.push_back(std::string(i, j));
        i = j;
    }
}


std::vector<std::string>
split(const std::string& s)
{
    std::vector<std::string> ret;
    typedef std::string::const_iterator iter;
    iter i = s.begin();
    while (i != s.end()) {
        i = std::find_if(i, s.end(), not_space);
        iter j = std::find_if(i, s.end(), space);
        if (i != s.end())
            ret.push_back(std::string(i, j));
        i = j;
    }
    return ret;
}  in .h split do not use space & not_space, put 
them in the .cpp
*/

std::vector<std::string>
split(const std::string& );

std::map<std::string, std::vector<int> >
xref(std::istream&,
        std::vector<std::string> find_word(const std::string& ) = split);//the return type of 
                                                 //split must be clarified so it can not be used as template??????????????
#endif
