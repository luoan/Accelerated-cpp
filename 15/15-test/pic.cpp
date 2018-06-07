#include "pic.h"

#include <algorithm>

Picture::Picture(const std::vector<std::string>& v) : p(new String_Pic(v)) { std::cout << "Picture::Picture" << std::endl; }

/*Pic_base::*/String_Pic::wd_sz String_Pic::width() const 
{
  /*Pic_base::*/wd_sz n = 0;
  for (/*Pic_base::*/ht_sz i = 0; i != data.size(); ++i) {
    n = std::max(n, data[i].size());
  }
  return n;
}

std::ostream& operator<<(std::ostream& os, const Picture& picture)
{
  const Pic_base::ht_sz ht = picture.p->height();
  for (Pic_base::ht_sz i = 0; i != ht; ++i) {
    picture.p->display(os, i, false);
    os << std::endl;
  }
  return os;
}

void String_Pic::display(std::ostream& os, ht_sz row, 
    bool do_pad) const 
{
  wd_sz start = 0;

  if (row < height()) {
    os << data[row];
    start += data[row].size();
  }
  if (do_pad)
    pad(os, start, width());
}
