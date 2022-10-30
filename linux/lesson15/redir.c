#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main()
{
  const char *msg1 = "hello 标准输出\n";
  write(1, msg1 , strlen(msg1));

  const char *msg2 = "hello 标准错误\n";
  write(2, msg2, strlen(msg2));
  
  return 0;
}
