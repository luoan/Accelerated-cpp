#include<vector>
#include<iostream>

#include"extract_fails.h"
#include"grade.h"

using std::vector;
using std::cout;    using std::endl;

vector<student_info>
extract_fails(vector<student_info>& students)
{

    vector<student_info>::iterator it = 
        partition(students.begin(), students.end(), pgrade);
    vector<student_info> fails(it, students.end());
    students.erase(it, students.end());
    return fails;
}
