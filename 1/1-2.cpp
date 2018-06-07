#include <iostream>
#include <string>

int main()
{
  const std::string exclam = "!";//right

  const std::string message = "Hello" + ", world" + exclam;
  // wrong

  return 0;
}
