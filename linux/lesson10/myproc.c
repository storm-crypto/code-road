#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
  for (int i = 0; i < argc; i++)
  {
    printf("argv[%d]:%s\n", i, argv[i]);
  }
 // int cnt = 5;
 // while (cnt)
 // {
 //   //printf("I am a process. pid: %d, ppid: %d\n", getpid(), getppid());
 //   printf("I am a cmd -> process!\n");
 //   cnt--;
 //   sleep(1);
 // }

  return 0;
}
