#include<iostream>
#include<string>
#include<vector>

using std::cin;     using std::cout;
using std::endl;    using std::string;
using std::vector;

template <class In, class Out, class X, class T>
Out remove_copy_if(In beg, In end, Out dest, T f(const X&))
{
    while (beg != end) {
        if ( !f(*beg) ) 
            *dest++ = *beg;
        ++beg;
    }
    return dest;
}

bool fun(const double& x)
{
    return (x >= 60 && x <= 100);
}

int main()
{
    vector<double> str, ret;
    double x;
    while (cin >> x)
        str.push_back(x);

    remove_copy_if(str.begin(), str.end(),
            back_inserter(ret), fun);

    cout << endl;
    for (vector<double>::const_iterator it = ret.begin();
            it != ret.end(); ++it)
        cout << *it << endl;
    return 0;
}
