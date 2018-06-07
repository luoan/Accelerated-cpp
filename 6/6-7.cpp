

std::vector<student_info> extract_didnt(std::vector<student_info>& s)
{
  std::vector<student_info>::iterator iter = 
    std::stable_partition(s.begin(), s.end(), did_all_hw);
  std::vector<student_info> didnt(iter, s.end());
  s.erase(iter, s.end());

  return didnt;
}
