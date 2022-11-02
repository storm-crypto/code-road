#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  if (fork() == 0)
  {
    // child 
    // exec*
    
    execl("/usr/bin/ls", "ls", "-a", "-l", "-n", "-i", NULL);

    exit(1);
  }

  // parent
  waitpid(-1, NULL, 0);
  printf("wait success!\n");


}

//int main()
//{
//
//  pid_t id = fork();
//  if (id == 0)
//  {
//    printf("I am a process! pid: %d\n", getpid());
//    execl("/usr/bin/ls", "ls", "-a", "-l", NULL); // execl执行程序替换
//  
//    printf("hahahaha\n");
//    printf("hahahaha\n");
//    printf("hahahaha\n");
//    printf("hahahaha\n");
//    printf("hahahaha\n");
//    printf("hahahaha\n");
//    exit(0);
//  }
//
//  while(1)
//  {
//    printf("I am a father\n");
//    sleep(1);
//  }
//
//  // parent
//  waitpid(id, NULL, 0);
//
//  printf("wait success!\n");
//
//  return 0;
//}
//















//int main()
//{
//  pid_t id = fork();
//  if (id == 0){
//    // child
//    int cnt = 10;
//    while (cnt)
//    {
//      printf("child[%d] is running: cnt is %d\n", getpid(), cnt);
//      cnt--;
//      sleep(1);
//    }
//    exit(0);
//  }
//
//  // parent
//  int status = 0;
//  while (1)
//  {
//    pid_t ret = waitpid(id, &status, WNOHANG); // 阻塞等待
//    if (ret == 0)
//    {
//      // 子进程没有退出，需要父进程重复进行检测
//      printf("Do father things;\n");
//    }
//    else if (ret > 0)
//    {
//      // 子进程退出了，获取到了对应的结果
//      printf("father wait: %d, success, status exit code: %d, status exit signal: %d\n", ret, (status>>8)&0xFF, status&0x7F);
//      break;    
//    }
//    else
//    {
//      // 等待失败
//      perror("waitpid\n");
//      break;
//    }
//    sleep(1);
//  }
//  
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////  // parent
////  //sleep(10);
////  printf("father wait begin\n");
//// // pid_t ret = wait(NULL);
//// 
////  int status = 0;
//// 
////  pid_t ret = waitpid(id, &status, 0); 
////  if (ret > 0)
////  {
////    if (WIFEXITED(status))
////    {
////      // 正常退出，获取对应的退出码
////      printf("exit code: %d\n", WEXITSTATUS(status));
////    }
////    else
////    {
////      printf("error, get a signal!\n");
////    }
////  }
//////  if (ret > 0){
////    printf("father wait: %d, success\n, status exit code: %d, status exit signal: %d\n", ret, (status>>8)&0xFF, status&0x7F);
////  }
////  else{
////    printf("father wait failed!\n");
////  }
////  printf("father wait: %d\n", ret);
//
//
// // // 另一个状态，父进程把子进程回收完后，自己还活上10s
// // sleep(10);
//}//
//
//
//
//
//
//
//
//
//
////int fun()
////{
////  printf("exit\n");
////  return 11;
////}
////
////int main()
////{
////  fun();
////  exit(66);
////  for (int i = 0; i < 100; i++)
////  {
////    printf("%d:%s\n", i, strerror(i));
////  }
////  return 0;
////}
