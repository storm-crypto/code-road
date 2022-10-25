#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  int fd = open("./log.txt", O_RDONLY);
  if (fd < 0){
    perror("open");
    return 1;
  }
  // 读取文件的内容
  char buffer[1024];
  ssize_t s = read(fd, buffer, sizeof(buffer) - 1);
  if (s > 0){
    //buffer[s] = 0;
    printf("%s\n", buffer);
  }

  close(fd);



  //int fd = open("./log.txt", O_CREAT|O_WRONLY, 0644);
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
