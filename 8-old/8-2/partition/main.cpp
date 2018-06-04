#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<stdexcept>
#include<algorithm>

#include"student_info.h"
#include"extract_fails.h"

using std::cin;     using std::ios;
using std::vector;  using std::endl;
using std::cout;    using std::string;
using std::fstream;
using std::domain_error;
using std::max;

int main()
{
    fstream infile;
    infile.open("/home/ananl/c++/8-2/partition/in.txt", ios::in);
    if (!infile.good())
        throw domain_error("file open error");

    student_info record;
    vector<student_info> students;
    vector<student_info> fails;
    
    while (read(infile, record))
        students.push_back(record);
    
    string::size_type maxlen = 0;
    for (vector<student_info>::const_iterator it = students.begin();
            it != students.end(); ++it) 
        maxlen = max(maxlen, (*it).name.size());

    fails = extract_fails(students);
    
    cout << "pass" << endl;
    for (vector<student_info>::const_iterator it = students.begin();
            it != students.end(); ++it)
        cout << (*it).name << string(maxlen+1 - (*it).name.size(), ' ')
            << grade(*it) << endl;

    cout << endl;
    cout << "fail" << endl;
    for (vector<student_info>::const_iterator it = fails.begin();
            it != fails.end(); ++it)
        cout << (*it).name << string(maxlen+1 - (*it).name.size(), ' ')
            << grade(*it) << endl;

    return 0;
}