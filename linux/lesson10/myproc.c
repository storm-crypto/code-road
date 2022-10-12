#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int g_val = 100;

int main()
{
  int cnt = 5;
  if (fork() == 0)
  {
    // child
    while(cnt){
      sleep(1);
      if(cnt == 3){
        printf("##########子进程修改变量开始##########\n");
        g_val = 200;
        printf("I am child, cnt = %d, g_val = %d, addr = %p\n", cnt, g_val, &g_val);
        printf("##########子进程修改变量done##########\n");
      }
      printf("I am child, cnt = %d, g_val = %d, addr = %p\n", cnt, g_val, &g_val);
      cnt--;
    }
  }
  else 
  {
    // parent
    while (1){
      sleep(1);
      printf("I am parent, g_val = %d, addr = %p\n", g_val, &g_val);
    }

  return 0;
  }
}
//int g_unval; // 未初始化全局变量
//int g_val = 100; // 初始化全局变量
//
////int main(int argc, char *argv[], char* env[])
//int main()
//{
//  const char* s = "hello world";
//  printf("code addr: %p\n", main); // 代码区
//  printf("string rdonly addr: %p\n", s); // 字符常量区
//  printf("uninit addr:%p\n", &g_unval); // 未初始化全局变量区
//  printf("init addr:%p\n", &g_val); // 已初始化全局变量区
//  char *heap = (char*)malloc(10);
//
//  printf("heap addr: %p\n", heap); // 堆区
//  
//  printf("stack addr: %p\n", &s); // 栈区
//  printf("stack addr: %p\n", &heap); // 栈区
//  
//  int a = 10;
//  int b = 30;
//  printf("stack addr: %p\n", &a); // 栈区
//  printf("stack addr: %p\n", &b); // 栈区
//
//  //printf("%s\n", getenv("my_env_string"));
//////  printf("PATH:%s\n", getenv("PATH"));
////  printf("HOME:%s\n", getenv("HOME"));
////  printf("SHELL:%s\n", getenv("SHELL"));
//////  extern char **environ;
////  
////  for(int i = 0; environ[i]; i++){
////    printf("%d->%s\n", i, environ[i]);
////  }
////  //for (int i = 0; env[i]; i++)
// // {
// //   printf("%d->%s\n", i, env[i]);
// // }
// //// if (argc != 2)
// // {
// //   printf("Usage: %s -[a|h]\n", argv[0]);
// // }
//
// // // 为什么需要有命令行参数
// // if (strcmp(argv[1], "-h") == 0)
// // {
// //   printf("hello bit!\n");
// // }
// // else if (strcmp(argv[1], "-a") == 0)
// // {
// //   printf("helle all\n");
// // }
// // else 
// // {
// //   printf("hello world\n");
// // }
// //// for (int i = 0; i < argc; i++)
// // {
// //   printf("argv[%d]:%s\n", i, argv[i]);
// // }
// //// int cnt = 5;
// // while (cnt)
// // {
// //   //printf("I am a process. pid: %d, ppid: %d\n", getpid(), getppid());
// //   printf("I am a cmd -> process!\n");
// //   cnt--;
// //   sleep(1);
// // }
//
//  return 0;
//}
