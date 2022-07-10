#include <stdio.h>

// 冒泡排序
// 低到高
void bubble_sort(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz - 1; i++)
    {
        int flag = 1; // 假设是有序
        int j = 0;
        for (j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 0;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (1 == flag)
        {
            break;
        }
    }
}
int main() {
    int arr[] = {1, 2, 3, 10, 9, 11, 21};
    int sz = sizeof (arr) / sizeof (arr[0]);
    bubble_sort(arr, sz);
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
