#include<iostream>
#include<string>

using std::cin; using std::cout;
using std::endl;    using std::string;


template <class In>
In search(In beg, In end, In sbeg, In send)
{
    while (beg != end) {
        if (*beg == *sbeg) {
            In tmp = beg;
            In stmp = sbeg;
            tmp++;  
            stmp++;//do not use sbeg for ++ since you may use it next time if this time not fully matching
            //sbeg++;
            while (/*sbeg*/stmp != send) {
                if (/**sbeg*/*stmp == *tmp) {
                    tmp++;  
                    stmp++;//sbeg++;
                }
                else 
                    break;
            }
            if (/*sbeg*/stmp == send)
                return beg;
        
        }
        ++beg;
    }

    return end;
}

int main()
{
    string s = "hettp://dfdf";
    string sep = "://";
    string::const_iterator i = search(
            s.begin(), s.end(), sep.begin(), sep.end());

    if (i != s.end())
        cout << *i << endl;

    return 0;
}
