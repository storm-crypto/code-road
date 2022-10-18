#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
  if (fork() == 0){ // child
    printf("command begin...\n");
   //execl("/usr/bin/ls", "ls", "-a", "-l", "-i", NULL); 
   
    //char *argv[] = {
    //  "ls",
    //  "-a",
    //  "-l",
    //  "-i",
    //  NULL
    //};
    //execv("/usr/bin/ls", argv);
    
   // execlp("ls", "ls", "-a", "-l", "-d", NULL);
  //  char *argv[] = {
  //    "ls",
  //    "-a",
  //    "-l",
  //    "-i",
  //    NULL
  //  };
  //  execvp("ls", argv);
    
    // execl("./myexe", "myexe", NULL);
    
    char *env[] = {
      "MYENV=hahahahahahaha",
      "MYENV1=hahahahahahaha",
      "MYENV2=hahahahahahaha",
      "MYENV3=hahahahahahaha",
      NULL 
    };
    char *argv[] = {
      "myexe",
      NULL 
    };
    execve("./myexe", argv, env);
    // execle("./myexe", "myexe", NULL, env);
    printf("command end...\n");
    exit(1);
  }
  
  waitpid(-1, NULL, 0);

  printf("wait child success!\n");


  return 0; // 退出码
}
