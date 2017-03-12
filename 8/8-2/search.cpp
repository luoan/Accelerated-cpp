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

            tmp++;  
            sbeg++;
            while (sbeg != send) {
                if (*sbeg == *tmp) {
                    tmp++;  
                    sbeg++;
                }
                else 
                    break;
            }
            if (sbeg == send)
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
