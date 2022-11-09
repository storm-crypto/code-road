#include "sub.h"
#include "add.h"

int main()
{
  int x = 10;
  int y = 20;

  int r1 = my_add(x, y);
  int r2 = my_sub(x, y);

  printf("+: %d\n", r1);
  printf("-: %d\n", r2);
  
  return 0;
}
