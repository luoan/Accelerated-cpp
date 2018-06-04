#include<iostream>
#include<string>

using std::cout;    using std::cin;
using std::string;
using std::endl;

template <class In>
bool equal(In begin, In end, In begin2)
{
    while (begin != end) {
        if (*begin != *begin2)
            return false;
        ++begin;
        ++begin2;
    }
    return true;
}

int main()
{
    string s = "helleh";
    if (equal(s.begin(), s.end(), s.rbegin()))
        cout << "equal" << endl;
    else 
        cout << "not equal" << endl;

    return 0;
}
