

std::vector<student_info> extract(std::vector<student_info>& s,
                                  bool fnc(const student_info& ))
{
  std::vector<student_info>::iterator = 
    std::stable_partition(s.begin(), s.end(), fnc);
  std::vector<student_info> ret(iter, s.end());
  s.erase(iter, s.end());

  return ret;
}
