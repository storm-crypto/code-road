#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main()
{
  // 系统接口
  const char *msg1 = "hello 标准输出\n";
  write(1, msg1 , strlen(msg1));

 // C语言接口 
  printf("hello printf\n");
  fprintf(stdout, "hello fprintf\n");
  fputs("hello fputs\n", stdout); 
  
  fflush(stdout);

  fork();

  return 0;
}
