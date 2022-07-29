#include <stdio.h>


// 打开和关闭文件
int main()
{
    // 打开文件
    FILE* pf = fopen("test.txt", "w");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    // 写文件
    char i = 'a';
    for (i = 'a'; i <= 'z'; i++)
    {
        fputc(i, pf);
    }

    // 关闭文件
    fclose(pf);
    pf = NULL;

    return 0;
}
