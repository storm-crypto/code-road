#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fun()
{
  printf("exit\n");
  return 11;
}

int main()
{
  fun();
  exit(66);
  for (int i = 0; i < 100; i++)
  {
    printf("%d:%s\n", i, strerror(i));
  }
  return 0;
}
