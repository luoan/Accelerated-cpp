#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

#include"template.h"
#include"analysis.h"
#include"grade.h"
#include"student_info.h"

using std::ostream; using std::string;
using std::vector;  using std::domain_error;

void write_analysis(ostream& out, const string& s,
        double fun_analysis(const vector<student_info>&,
            double f(const student_info& )),
        double f(const student_info&),
        const vector<student_info>& did,
        const vector<student_info>& did_not)
{
    out << s << " did: " << fun_analysis(did, f)
        << " did_not: " << fun_analysis(did_not, f)
        << std::endl;
}

double grade_aux(const student_info& s)
{
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}


