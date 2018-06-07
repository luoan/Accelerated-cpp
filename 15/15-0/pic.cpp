#include "pic.h"

#include <algorithm>
#include <string>

Picture::Picture(const std::vector<std::string>& v) : p(new String_Pic(v)) { }

// functions
std::ostream& operator<<(std::ostream& os, const Picture& picture)
{
  const Pic_base::ht_sz ht = picture.p->height();
  for (Pic_base::ht_sz i = 0; i != ht; ++i) {
    picture.p->display(os, i, false);
    os << std::endl;
  }
  return os;
}

Picture frame(const Picture& picture)
{
  return new Frame_Pic(picture.p);
}

Picture vcat(const Picture& t, const Picture& b) 
{
  return new VCat_Pic(t.p, b.p);
}

Picture hcat(const Picture& l, const Picture& r)
{
  return new HCat_Pic(l.p, r.p);
}
Pic_base::wd_sz String_Pic::width() const 
{
  wd_sz n = 0;
  for (wd_sz i = 0; i != data.size(); ++i)
    n = std::max(n, data[i].size());
  return n;
}

void String_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const
{
  wd_sz start = 0;

  if (row < height()) {
    os << data[row];
    start = data[row].size();
  }
  if (do_pad)
    pad(os, start, width());
}

void Frame_Pic::display(std::ostream& os, 
    ht_sz row, bool do_pad) const 
{
  if (row >= height()) {
    pad(os, 0, width());
  }
  else {
    if (row == 0 || row == height() - 1) {
      os << std::string(width(), '*');
    }
    else if (row == 1 || row == height() - 2) {
      os << "*";
      pad(os, 1, width() - 1);
      os << "*";
    }
    else {
      os << "* ";
      p->display(os, row-2, true);
      os << " *";
    }
  }
}

void VCat_Pic::display(std::ostream& os, 
    ht_sz row, bool do_pad) const
{
  wd_sz w = 0;
  if (row < top->height()) {
    top->display(os, row, do_pad);
    w = top->width();
  }
  else if (row < height()) {
    bottom->display(os, row - top->height(), do_pad);
    w = bottom->width();
  }
  if (do_pad) 
    pad(os, w, width());
}

void HCat_Pic::display(std::ostream& os, 
    ht_sz row, bool do_pad) const 
{
  left->display(os, row, do_pad || row < right->height());
  right->display(os, row, do_pad);
}
