#include <accctrl.h>
#include <math.h>
#include <stdio.h>


// 练习：变种水仙花
//int main()
//{
//    int i = 0;
//    for (i = 10000; i <= 99999; i++)
//    {
//        int j = 0;
//        int sum = 0;
//        for (j = 0; j < 4; j++)
//        {
//            int m = i % (int)pow(10, j);
//            int n = i / (int)pow(10, j);
//            sum += m*n;
//        }
//        if (sum == i)
//        {
//            printf("%d ", i);
//        }
//    }
//}

// 练习：字符串左旋
void left_move(char arr[], int k)
{
    int len = strlen(arr);
    int j = 0;
    for (j = 0; j < k; j++)
    {
        char tmp = arr[0];
        int i = 0;
        for (i = 0; i < len - 1; i++)
        {
            arr[i] = arr[i + 1]; // 后面所有的元素往前挪
        }
        arr[len - 1] = tmp;
    }

}

int main()
{
    // 左旋转字符的代码
    char arr[20] = "abcdef";
    int k = 0;
    scanf("%d", &k);

    left_move(arr, k);

    printf("%s\n", arr);
    return 0;
}