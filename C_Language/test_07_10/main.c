#include <stdio.h>

// 冒泡排序
// 低到高
//void bubble_sort(int arr[], int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz - 1; i++)
//    {
//        int flag = 1; // 假设是有序
//        int j = 0;
//        for (j = 0; j < sz - 1 - i; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                flag = 0;
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//        if (1 == flag)
//        {
//            break;
//        }
//    }
//}
//int main() {
//    int arr[] = {1, 2, 3, 10, 9, 11, 21};
//    int sz = sizeof (arr) / sizeof (arr[0]);
//    bubble_sort(arr, sz);
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

// 数组操作
//void init(int arr[], int sz, int set)
//{
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        arr[i] = set;
//    }
//}
//
//void print(int arr[], int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//}
//
//void reverse(int arr[], int sz)
//{
//    int i = 0;
//    int j = sz - 1;
//    while (i <= j)
//    {
//        int temp = arr[i];
//        arr[i] = arr[j];
//        arr[j] = temp;
//        i++;
//        j--;
//    }
//}
//
//int main()
//{
//    int arr[] = {1,2,(3,4),5};
//    printf("%d\n", sizeof(arr));
//    return 0;
//}

// 递归实现n的k次方

//double Power(int n, int k)
//{
//    if (k < 0)
//    {
//        return n * Power(n, k - 1);
//    }
//    else if (k == 0)
//        return 1;
//    else
//        return 1.0 / Power(n, -k);
//}
//int main()
//{
//    int n = 0;
//    int k = 0;
//    scanf("%d %d", &n, &k);
//    double ret = Power(n, k);
//    printf("%lf\n", ret);
//    return 0;
//}

int main()
{
    float a = 3 / 2;
    printf("%f\n", a);
    return 0;
}