#include <stdio.h>
#include <string.h>

// strtok函数的使用
int main()
{
    char arr[] = "zpengwei@yeah.net.hehe";
    char buf[50] = {0};
    strcpy(buf, arr);

    const char* sep = "@.";
    char* str = NULL;
    for (str = strtok(buf, sep); str != NULL; str = strtok(NULL, sep))
    {
        printf("%s\n", str);
    }

    return 0;
}
