#include<iostream>
#include<vector>
#include<fstream>
#include<stdexcept>

#include"student_info.h"
#include"analysis.h"

using std::cout;    using std::endl;
using std::vector;  using std::fstream;
using std::domain_error;

int main()
{
    fstream infile;
    infile.open("/home/ananl/c++/8-1/in.txt", std::ios::in);
    if (!infile.good()) {
        throw domain_error("file open eror");
        return -1;
    }

    vector<student_info> did, did_not;
    student_info record;
    while (read(infile, record))
        if (did_all_hw(record))
            did.push_back(record);
        else 
            did_not.push_back(record);
     /*
    cout << "did:" << endl;
    for (vector<student_info>::const_iterator it = did.begin();
            it != did.end(); ++it) {
        cout << it->name << "  " << it->midterm 
            << "  " << it->final <<  "  hw: ";
        for (vector<double>::const_iterator iter = it->homework.begin();
                iter != it->homework.end(); ++iter)
            cout <<  " " << *iter;

        cout << endl;
    }
    cout << endl;

    cout << "did_not:" << endl;   
    for (vector<student_info>::const_iterator it = did_not.begin();
            it != did_not.end(); ++it) {
        cout << it->name << "  " << it->midterm 
            << "  " << it->final <<  "  hw: ";
        for (vector<double>::const_iterator iter = it->homework.begin();
                iter != it->homework.end(); ++iter)
            cout <<  " " << *iter;

        cout << endl;
    }
    cout << endl << endl;
    */

    write_analysis(cout, "median", analysis, grade_aux, did, did_not);
    
    write_analysis(cout, "average", analysis, average_grade, did, did_not);

    write_analysis(cout, "optimistic", analysis, optimistic_median,
            did, did_not);

    return 0;
}
