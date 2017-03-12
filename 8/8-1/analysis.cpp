#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<stdexcept>
#include<numeric>
#include<iostream>

#include"grade.h"
#include"student_info.h"
#include"analysis.h"

using std::vector;  using std::ostream;
using std::string;
using std::domain_error;
using std::cout;    using std::endl;

void write_analysis(ostream& out, const string& s,
        double analysis(const vector<student_info>& students,
            double f(const student_info& s)),
        double f(const student_info& s),
        const vector<student_info>& did,
        const vector<student_info>& did_not)
{
    std::cout << s << " did: " << analysis(did, f)
        << " did_not: " << analysis(did_not, f)
        << std::endl;
    /*
     *
     * when diaoyong this function
     * first endl then analysis did_not
     * then did 
     * finally write them to ostream
     * above is the function list 
     * but write to ostream the list is
     * did  did_not
     * */
}

double grade_aux(const student_info& s)
{   
    /*
    cout << "grade_aux " << s.name
        << " " << s.midterm << " "
        << s.final << " "  << endla;
        */
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double average_grade(const student_info& s)
{
    //cout << "average_grade " << s.name << endl;
    return grade(s.midterm, s.final, average(s.homework));
}

double average(const vector<double>& hw)
{
    return std::accumulate(hw.begin(), hw.end(), 0.0) / hw.size();
}

double optimistic_median(const student_info& s)
{
    vector<double> nonzero;
    std::remove_copy(s.homework.begin(), s.homework.end(),
            back_inserter(nonzero), 0);
    if (nonzero.empty()) 
        return grade(s.midterm, s.final, 0);
    else 
        return grade(s.midterm, s.final, median(nonzero));
}
