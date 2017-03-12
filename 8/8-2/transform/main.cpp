#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include<fstream>

#include"student_info.h"
#include"analysis.h"
#include"template.h"

using std::cin;     using std::ios;
using std::cout;    using std::endl;
using std::string;  using std::vector;
using std::domain_error;
using std::fstream;

int main()
{
    fstream infile;
    infile.open("/home/ananl/c++/8-2/transform/in.txt", ios::in);
    if (!infile.good())
        throw domain_error("file open error");

    vector<student_info> did, did_not;
    student_info record;
    while (read(infile, record))
        if (did_all_hw(record))
            did.push_back(record);
        else
            did_not.push_back(record);

    write_analysis(cout, "median", fun_analysis, grade_aux, did, did_not);

    return 0;
}
