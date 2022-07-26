#include <math.h>
#include <stdio.h>


// 练习：变种水仙花
int main()
{
    int i = 0;
    for (i = 10000; i <= 99999; i++)
    {
        int j = 0;
        int sum = 0;
        for (j = 0; j < 4; j++)
        {
            int m = i % (int)pow(10, j);
            int n = i / (int)pow(10, j);
            sum += m*n;
        }
        if (sum == i)
        {
            printf("%d ", i);
        }
    }
}