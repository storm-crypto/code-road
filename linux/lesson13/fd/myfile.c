#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
  // fopen("./log.txt", "w");
  int fd = open("./log.txt", O_WRONLY | O_CREAT , 0644);
  if (fd < 0){
    printf("open error\n");

  }

  close(fd);
  
  //// FILE *fp = fopen("./log.txt", "w");
  //FILE *fp = fopen("./log.txt", "r");
  //if (NULL == fp)
  //{
  //  perror("fopen");
  //  return 1;
  //}

  //char buffer[64];
  //while (fgets(buffer, sizeof(buffer), fp))
  //{
  //  printf("%s", buffer);
  //}
  //
  //// 判断文件是否是正常退出
  //if (!feof(fp)){
  //  printf("fgets quit not normal!\n");
  //}
  //else{
  //  printf("fgets quit normal!\n");
  //}
  //
  ////int cnt = 10;
  ////while (cnt--){
  ////  const char *msg = "hello bit\n";
  ////  fputs(msg, fp);
  ////}
  //fclose(fp);
}
