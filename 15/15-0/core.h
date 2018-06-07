#ifndef _CORE_H_
#define _CORE_H_


#include <string>
#include <vector>
#include <iostream>

class core {
  friend class student_info;
  template <class T> friend T* clone(const T* );

  public :
    core() : midterm(0), final(0) { }
    core(std::istream& is) { read(is); }
    virtual ~core() { }   
    
    std::string name() const;
    virtual std::istream& read(std::istream& );
    virtual double grade() const;
    //virtual core* clone() { return new core(*this); }
  protected :
    double midterm, final;
    std::vector<double> homework;
    std::istream& read_common(std::istream& );
    //virtual core* clone() { return new core(*this); }
  
  private :
    std::string n;
    virtual core* clone() { return new core(*this); }
    //double midterm, final;
    //std::vector<double> homework;
};


class grad : public core {
  
  public :
    grad() : thesis(0) { }
    grad(std::istream& is) { read(is); }

    virtual std::istream& read(std::istream& );
    virtual double grade() const;
    //virtual grad* clone() { return new grad(*this); }
  //protected :
  //  virtual grad* clone() { return new grad(*this); }
  private :
    virtual grad* clone() { return new grad(*this); }
    double thesis;
};

std::istream& read_hw(std::istream&, std::vector<double>& );
//bool compare(const core&, const core& );
//bool compare_ptr(const core*, const core* );

#endif
