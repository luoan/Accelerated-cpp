#include<iostream>
#include<string>

using std::cin;     using std::cout;
using std::endl;    using std::string;


template <class In, class X>
In find_if(In beg, In end, bool f(const X&))
{
    while (beg != end) {
        if (f(*beg))
            return beg;
        ++beg;
    }
    return end;
}

bool isnumber(const char& c)
{
    if (c >= '0' && c <= '9')
        return true;
    else 
        return false;
}

int main()
{
    string s = "ajdi8d fdf9";
    string::const_iterator it = find_if(
            s.begin(), s.end(), isnumber);

    if (it != s.end())
        cout << *it << endl;
    else 
        cout << "no number";

    return 0;
}
