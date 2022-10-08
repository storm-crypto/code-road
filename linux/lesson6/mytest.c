#include <stdio.h>

int SumToTop(int top)
{
  int sum = 0;
  for (int i = 1; i <= top; i++)
  {
    sum += i;
  }

  return sum;
}

int main()
{
  int top = 100;
  int result = SumToTop(top);

  printf("result = %d\n ", result);

  return 0;
}
