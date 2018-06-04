#include<iostream>
#include<string>
#include<list>
#include<vector>
//#include<algorithm>

template <class X>
void swap(X& x, X& y)
{
    X tmp;
    tmp = x;
    x = y;
    y = tmp;
}

template <class In, class X>
In remove(In beg, In end, const X& x)
{
    while (beg != end) {
        if (*beg == x) {
            --end;
            if (beg == end)
                return beg;
            else {
                while (*end == x && 
                            end != beg)
                    --end;
                
                if (beg == end)
                    return beg;
                else
                    swap(*beg, *end);
            }
        }
        ++beg;
    }
    return beg;
}

template <class Ran>
void sort(Ran beg, Ran end)
{
    for (Ran i = beg+1; i != end; ++i) {
        for (Ran j = i; j > beg; --j)
            if (*(j-1) > *j)
                swap(*(j-1), *j);
            else 
                break;

    }
}

using std::cin;     using std::cout;
using std::endl;    using std::string;
using std::list;    
using std::vector;

int main()
{/*
    vector<string> ret;
    string s;
    while (cin >> s)
        ret.push_back(s);

    string f = "good";
    vector<string>::const_iterator it = remove(ret.begin(),
            ret.end(), f);
*/
    string s;
    char c;
    while (cin >> c)
        s.push_back(c);
    char f = 'a';
    string::iterator it = remove(s.begin(),
            s.end(), f);//not const::iterator
    sort(s.begin(), it);
    for (string::const_iterator i = s.begin();
            i != s.end(); ++i)
        cout << *i;
    cout << endl;
    /*
    while (it != s.end()) {
        cout << *it << endl;
        ++it;
    }
*/
    return 0;
}
