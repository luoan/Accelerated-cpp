#include <stdio.h>

int main()
{
  int a = 3;
  {
    printf("a = %d\n", a);
  }
  {
    int a;
    a = 5;
    printf("a = %d\n", a);
  }

  return 0;
}

// if there is a function to print a and not define a 
// then it is wrong
