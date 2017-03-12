#include<iostream>
#include<string>
#include<vector>

using std::cin;     using std::cout;
using std::endl;    using std::string;
using std::vector;

template <class In, class Out, class X>
Out remove_copy(In beg, In end, Out dest, const X& x)
{
    while (beg != end) {
        if (*beg != x)
            *dest++ = *beg;
        ++beg;
    }
    return dest;
}

int main()
{
    vector<double> ret; 
    double x;
    while (cin >> x)
        ret.push_back(x);

    vector<double> nonzero;
    remove_copy(ret.begin(), ret.end(),
            back_inserter(nonzero), 0);

    for (vector<double>::const_iterator it = nonzero.begin();
            it != nonzero.end(); ++it)
        cout << *it << endl;

    return 0;
}
