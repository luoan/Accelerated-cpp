#ifndef _PIC_H_
#define _PIC_H_


#include "ptr.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Picture;

class Pic_base {
  friend std::ostream& operator<<(std::ostream&, const Picture& );
  friend class String_Pic;
  friend class Frame_Pic;
  friend class VCat_Pic;
  friend class HCat_Pic;

public :
  virtual ~Pic_base() { }

private :
  typedef std::vector<std::string>::size_type ht_sz;
  typedef std::string::size_type wd_sz;
  
  virtual ht_sz height() const = 0;
  virtual wd_sz width()  const = 0;
  virtual void display(std::ostream&, ht_sz, bool) const = 0;
//protected :
  static void pad(std::ostream& os, wd_sz beg, wd_sz end) {
    while (beg != end) { 
      os << " "; ++beg; 
    }
  }
};


class Picture {
  friend std::ostream& operator<<(std::ostream&, const Picture& );
  friend Picture frame(const Picture& );
  friend Picture hcat(const Picture&, const Picture& );
  friend Picture vcat(const Picture&, const Picture& );

public :
  Picture(const std::vector<std::string>& = std::vector<std::string>());
private :
  Picture(Pic_base* rhs) : p(rhs) { }
  Ptr<Pic_base> p;
};


std::ostream& operator<<(std::ostream& os, const Picture& picture);
Picture frame(const Picture& );
Picture vcat(const Picture&, const Picture& );
Picture hcat(const Picture& , const Picture& );

class String_Pic : public Pic_base {
friend class Picture;
private :
  String_Pic(const std::vector<std::string>& v) : data(v) { }
  std::vector<std::string> data;

  virtual ht_sz height() const { return data.size(); }
  virtual wd_sz width() const;
  virtual void display(std::ostream&, ht_sz, bool) const ;
};


class Frame_Pic : public Pic_base {//String_Pic {
  friend Picture frame(const Picture& );
private:
  Frame_Pic(const Ptr<Pic_base>& pic) : p(pic) { }

  wd_sz width() const { return p->width() + 4; }
  ht_sz height() const { return p->height() + 4; }
  void display(std::ostream&, ht_sz, bool) const;
  
  Ptr<Pic_base> p;
};


class VCat_Pic : public Pic_base {
  friend Picture vcat(const Picture&, const Picture& );
private :
  Ptr<Pic_base> top, bottom;
  VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b) :
    top(t), bottom(b) { }

  wd_sz width() const {
    return std::max(top->height(), bottom->height());
  }
  ht_sz height() const {
    return top->height() + bottom->height();
  }
  void display(std::ostream&, ht_sz, bool) const;
};


class HCat_Pic : public Pic_base {
  friend Picture hcat(const Picture& l, const Picture& r);
private :
  Ptr<Pic_base> left, right;
  HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r) :
    left(l), right(r) { }

  wd_sz width() const { return left->width() + right->width(); }
  ht_sz height() const { return std::max(left->height(), right->height()); }

  void display(std::ostream&, ht_sz, bool) const ;
};

#endif
