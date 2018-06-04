#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<algorithm>
#include<cctype>

#include"xref.h"

using std::istream; using std::string;
using std::vector;  using std::map;
using std::find_if;
using std::cout;    using std::endl;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

vector<string> 
split(const string& s)
{
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = s.begin();
    while (i != s.end()) {
        i = find_if(i, s.end(), not_space);
        iter j = find_if(i, s.end(), space);
        ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}

map<string, vector<int> >
xref(istream& in, 
        vector<string> find_word(const string& ))
{
    string s;
    int line_number = 0;
    map<string, vector<int> > ret;
    //cout << " xref.cpp " << endl;   
    while ( getline(in, s)/*in >> s*/) {
    //    cout << s << endl;
        ++line_number;
        vector<string> tmp = find_word(s);
        for (vector<string>::const_iterator it = tmp.begin();
                it != tmp.end(); ++it) {
      //      cout << *it << " " << line_number;
            ret[*it].push_back(line_number);
        }
    }

    return ret;
}
