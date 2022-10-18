#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define NUM 128
#define CMD_NUM 64

int main()
{
  char command[NUM];
  for(; ; ){
    char *argv[CMD_NUM] = {NULL};
    // 1.打印提示符
    command[0] = 0; // 用这种方式，可以做到O(1)的时间复杂度，情况字符串
    printf("[who@myhostname minishell]# ");
    fflush(stdout);
    // 2. 获取命令字符串
    fgets(command, NUM, stdin);
    command[strlen(command) - 1] = '\0'; // ls\n\0 , 去掉\n
    //printf("echo: %s\n", command);
    
    // "ls -a -b -c\0";
    // 3. 解析命令字符串, char* argv[];
    // strtok();
    const char *sep = " ";
    argv[0] = strtok(command, sep);
    int i = 1;
    while (argv[i] = strtok(NULL, sep)){
      i++;
    }

    // 4.检测命令是否是需要shell本身执行的，内建命令
    if (strcmp(argv[0], "cd") == 0)
    {
      if (argv[1] != NULL) chdir(argv[1]);
      continue;
    }

    // 执行第三方命令
    if (fork() == 0)
    {
      // child
      execvp(argv[0], argv);
      exit(1);
    }
    
    waitpid(-1, NULL, 0);
  //  for (int i = 0; argv[i]; i++)
  //  {
  //    printf("argv[%d]:%s\n", i, argv[i]);
  //  }
    
  }
}
