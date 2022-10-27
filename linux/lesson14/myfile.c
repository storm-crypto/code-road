#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  
    int fd = open("./log.txt", O_WRONLY | O_CREAT, 0644);
    if (fd < 0){
      perror("open");
      return 1;
    }

    dup2(fd, 1); //本来应该显示到显示器的内容打印到文件
  
    // stdout -> 1 ->struct file*
    printf("hello printf\n");
    fprintf(stdout, "hello fprintf\n");
    fputs("hello fputs", stdout);
  
  
  
  
  
  
  
  
  //int fd = open("./log.txt", O_RDONLY);
  //if (fd < 0){
  //  perror("open");
  //  return 1;
  //}
  //// 读取文件的内容
  //char buffer[1024];
  //ssize_t s = read(fd, buffer, sizeof(buffer) - 1);
  //if (s > 0){
  //  //buffer[s] = 0;
  //  printf("%s\n", buffer);
  //}

  //close(fd);



 // int fd = open("./log.txt", O_CREAT|O_WRONLY, 0644);
 // int fd1 = open("./log1.txt", O_CREAT|O_WRONLY, 0644);
 // int fd2 = open("./log2.txt", O_CREAT|O_WRONLY, 0644);
 // int fd3 = open("./log3.txt", O_CREAT|O_WRONLY, 0644);
 // 
 //printf("%d %d %d %d\n", fd, fd1, fd2, fd3); 
  
  
  
  
  
  
  //if (fd < 0){
  //if (fd < 0){
  //  perror("open");
  //  return 1;
  //}
  //
  //const char *msg = "hello bit\n";

  //int cnt = 5;
  //while (cnt){
  //  write(fd, msg, strlen(msg));// 在我们写入文件的过程中，不需要写入\0,因为\0作为字符串的结束只是C的规定而已
  //  cnt--;
  //}
  //  
  //close(fd);
}
