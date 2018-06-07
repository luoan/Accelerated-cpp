#include <iostream>
#include <vector>

/*
std::vector<student_info> extract_fails(std::vector<student_info>& s)
{
  std::vector<student_info>::size_type i = 0;
  std::vector<student_info> fail;
  std::vector<student_info>::size_type pass_count = 0;

  while(i != s.size()) {
    if (fgrade(s[i])) {
      fail.push_back(s[i]);
      ++i;
    }
    else {
      pass_count++;
      s.insert(0, s[i]);
      i += 2;
    }
  }
  s.resize(pass_count);
  return fail;
}
*/

// for test
std::vector<double> extract_fail(std::vector<double>& s)
{
  std::vector<double>::size_type i = 0;
  std::vector<double>::size_type pass_count = 0;
  std::vector<double> fail;

  while (i != s.size()) {
    if (s[i] < 60) {
      fail.push_back(s[i]);
      ++i;
    }
    else {
      pass_count++;
      s.insert(s.begin(), s[i]);
      i += 2;
    }
  }
  s.resize(pass_count);
  return fail;
}

int main()
{
  std::vector<double> s;
  double f;
  while (std::cin >> f)
    s.push_back(f);

  std::vector<double> fail;

  fail = extract_fail(s);

  std::cout << std::endl;
  for (std::vector<double>::size_type i = 0; i != s.size(); ++i)
    std::cout << s[i] << "  ";

  std::cout << std::endl;
  for (std::vector<double>::size_type i = 0; i != fail.size(); ++i)
    std::cout << fail[i] <<  "  ";
  std::cout << std::endl;

  return 0;
}
