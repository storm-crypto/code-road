#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

//int main(int argc, char *argv[], char* env[])
int main()
{
  printf("PATH:%s\n", getenv("PATH"));
  printf("HOME:%s\n", getenv("HOME"));
  printf("SHELL:%s\n", getenv("SHELL"));
//  extern char **environ;
//  
//  for(int i = 0; environ[i]; i++){
//    printf("%d->%s\n", i, environ[i]);
//  }
//  //for (int i = 0; env[i]; i++)
 // {
 //   printf("%d->%s\n", i, env[i]);
 // }
 //// if (argc != 2)
 // {
 //   printf("Usage: %s -[a|h]\n", argv[0]);
 // }

 // // 为什么需要有命令行参数
 // if (strcmp(argv[1], "-h") == 0)
 // {
 //   printf("hello bit!\n");
 // }
 // else if (strcmp(argv[1], "-a") == 0)
 // {
 //   printf("helle all\n");
 // }
 // else 
 // {
 //   printf("hello world\n");
 // }
 //// for (int i = 0; i < argc; i++)
 // {
 //   printf("argv[%d]:%s\n", i, argv[i]);
 // }
 //// int cnt = 5;
 // while (cnt)
 // {
 //   //printf("I am a process. pid: %d, ppid: %d\n", getpid(), getppid());
 //   printf("I am a cmd -> process!\n");
 //   cnt--;
 //   sleep(1);
 // }

  return 0;
}
