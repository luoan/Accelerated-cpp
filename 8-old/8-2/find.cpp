#include<iostream>
#include<string>

using std::cin;     using std::cout;
using std::endl;    using std::string;


template <class In, class X>
In find(In beg, In end, const X& x)
{
    while (beg != end)
        if (*beg == x)
            return beg;
        else 
            ++beg;
    return end;
}

int main()
{
    string s = "hw is done";
    char c = 's';
    string::const_iterator it = find(
            s.begin(), s.end(), c);

    if (it != s.end())
        cout << *it << endl;
    else 
        cout << "not find" << endl;

    return 0;
}
