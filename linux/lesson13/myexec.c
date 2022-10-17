#include <stdio.h>
#include <unistd.h>

int main()
{
  printf("command begin...\n");
  execl("/usr/bin/ls", "ls", "-a", "-l", "-i", NULL); 
  printf("command end...\n");

  return 0; // 退出码
}
