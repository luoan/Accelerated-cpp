#include <iostream>
#include <string>

template <class In, class Out, class Function>
Out myremove_copy_if(In b, In e, Out d, Function f)
{
  while (b != e) {
    //std::cout << f(*b) << std::endl;
    if (!f(*b))
      *d++ = *b;
    ++b;
  }
  return d;
}

bool upper(char c)
{
  return c >= 'A' && c <= 'Z';
}

int main()
{
  std::string s1, s2;

  s1 = "hah Apple DoG CAT bOY";
  myremove_copy_if(s1.begin(), s1.end(), back_inserter(s2), upper);

  std::cout << s1 << std::endl << s2  << std::endl;

  return 0;
}
