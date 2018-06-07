#ifndef _ROTATE_H_
#define _ROTATE_H_


#include <string>
#include <vector>

std::vector<std::string> rotate(const std::vector<std::string>& v);

void rerotate(const std::vector<std::string>& vstore, 
              const std::vector<std::string>& vkey,
              std::vector<std::string>& vleft,
              std::vector<std::string>& vright);

#endif
