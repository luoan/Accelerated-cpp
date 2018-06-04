#include<iostream>
#include<vector>

using std::cin;     using std::cout;
using std::endl;    using std::vector;


template <class In, class X>
X accumulate(In beg, In end, X x)
{
    while (beg != end) {
        x += *beg++;
    }
    return x;
}

int main()
{
    double x;
    vector<double> ret;
    while (cin >> x)
        ret.push_back(x);

    double f;
    f = accumulate(ret.begin(), ret.end(), 0.0);
    cout << f << endl;
    return 0;
}
