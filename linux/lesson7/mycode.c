#include <stdio.h>
#include <unistd.h>

int main()
{
  //printf("hello world\n");
  int count = 5;
  while(count)
  {
    printf("%d\r", count);
    fflush(stdout);
    sleep(1); 
    count--;
  }

  return 0;
}
