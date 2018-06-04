#include<iostream>
#include<string>
#include<vector>


template <class T>
void swap(T& x, T& y)
{
    T tmp;
    tmp = x;
    x = y;
    y = tmp;
}

template <class In, class X, class T>
In remove_if(In beg, In end, T p(const X&)) 
{
    while (beg != end) {
        if (p(*beg)) {
         //   std::cout << *beg << "re" << std::endl;
            --end;
            if (beg == end)
                return beg;
            else {
                while (p(*end) && end != beg)
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

bool isnum(const char& c)
{
    if (c >= '0' && c <= '9')
        return true;
    else 
        return false;/*
    if (c == 'a')
        return true;
    else 
        return false;*/
}

template <class Ran>
void sort(Ran beg, Ran end)
{
    for (Ran i = beg+1; i != end; ++i)
        for (Ran j = i; j > beg; --j)
            if (*(j-1) > *j)
                swap(*(j-1), *j);
            else 
                break;

}
using std::cin;     using std::cout;
using std::endl;    using std::string;
using std::vector;

int main()
{
    string s;
    char c;
    while (cin >> c)
        s.push_back(c);
    
    string::iterator it = remove_if(
            s.begin(), s.end(), isnum);
    sort(s.begin(), it);
    sort(it, s.end());
    
    for (string::const_iterator it = s.begin();
            it != s.end(); ++it)
        cout << *it;
    cout << endl;
    
    return 0;   
}
