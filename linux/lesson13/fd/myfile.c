#include <stdio.h>

int main()
{
  FILE *fp = fopen("./log.txt", "w");
  if (NULL == fp)
  {
    perror("fopen");
    return 1;
  }
  
  int cnt = 10;
  while (cnt--){
    const char *msg = "hello bit\n";
    fputs(msg, fp);
  }
  fclose(fp);
}
