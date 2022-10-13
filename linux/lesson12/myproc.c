#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  pid_t id = fork();
  if (id == 0){
    // child
    int cnt = 5;
    while (cnt)
    {
      printf("child[%d] is running: cnt is %d\n", getpid(), cnt);
      cnt--;
      sleep(1);
    }
    exit(0);
  }

  // parent
  sleep(10);
  printf("father wait begin\n");
  pid_t ret = wait(NULL);
  if (ret > 0){
    printf("father wait: %d, success\n", ret);
  }
  else{
    printf("father wait failed!\n");
  }
  printf("father wait: %d\n", ret);


  // 另一个状态，父进程把子进程回收完后，自己还活上10s
  sleep(10);

}









//int fun()
//{
//  printf("exit\n");
//  return 11;
//}
//
//int main()
//{
//  fun();
//  exit(66);
//  for (int i = 0; i < 100; i++)
//  {
//    printf("%d:%s\n", i, strerror(i));
//  }
//  return 0;
//}
