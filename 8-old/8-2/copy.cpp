#include<iostream>
#include<string>
#include<vector>

using std::cin;     using std::cout;
using std::endl;    using std::string;
using std::vector;

template <class In, class Out>
Out copy_test(In beg, In end, Out dest)
{
    while (beg != end) {
        *dest++ = *beg++;
    }
    return dest;
}

int main()
{
    vector<string> str;
    string s;
    while (cin >> s)
        str.push_back(s);

    vector<string> ret;
    copy_test(str.begin(), str.end(), back_inserter(ret));

    for (vector<string>::const_iterator it = ret.begin();
            it != ret.end(); ++it)
        cout << *it << endl;

    return 0;
}

