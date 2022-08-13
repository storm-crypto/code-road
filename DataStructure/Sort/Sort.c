//
// Created by ��� on 2022-08-12.
//

#include "Sort.h"

void Print(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

// ��������
void InsertSort(int* a, int n)
{
    // ���ˣ���Ϊend = n - 2��ʱ������������
    for (int i = 0; i < n - 1; i++)
    {
        // ��tmp���뵽0~end������������
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0)
        {
            if (tmp < a[end])
            {
                a[end + 1] = a[end];
                --end;
            }
            else
            {
                break;
            }
        }
        // �����������end = -1��ʱ���������ʽ��ͬ���ʺ�
        // ���Ըɴ�ֱ��else����break��������ҵ����ʵ�λ�þ�
        // ��tmp������λ������
        a[end + 1] = tmp;
    }
}
// ϣ������
void ShellSort(int* a, int n)
{
    // gap > 1��ʱ��Ԥ����
    // gap == 1��ʱ����ֱ�Ӳ�������
    int gap = n;
    while (gap > 1)
    {
        gap = gap / 3 + 1;
        // �������е�����Ԫ�ؽ���һ��Ԥ����
        for (int i = 0; i < n - gap; ++i)
        {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0)
            {
                if (tmp < a[end])
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = tmp;
        }
    }
}

void Swap(int* p, int* q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

// ֱ��ѡ������
void SelectSort(int* a, int n)
{
    int left = 0, right = n - 1;

    while (left < right)
    {
        // ѡ����С�ĺ�����
        int minIndex = left, maxIndex = left;

        for (int i = left; i <= right; i++)
        {
            if (a[i] < a[minIndex])
                minIndex = i;
            if (a[i] > a[maxIndex])
                maxIndex = i;
        }

        // ����������ķ��ұߣ�С�ķ����
        Swap(&a[left], &a[minIndex]);
        // ���������
        // ���max��leftλ���ص���max�������ˣ�Ҫ����һ��max��λ��
        if (left == maxIndex)
            maxIndex = minIndex;
        Swap(&a[right], &a[maxIndex]);
        left++;
        right--;
    }
}

// ������
void AdjustDwon(int* a, int n, int root)
{
    int parent = root;
    int child = parent * 2 + 1;
    while (child < n)
    {
        // ����ע���ж�һ��Խ����Щ
        if (child + 1 < n && a[child] < a[child + 1])
        {
            child++;
        }
        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }

}
void HeapSort(int* a, int n)
{
    // ���� �����
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)
    {
        AdjustDwon(a, n, i);
    }

    int end = n - 1;
    while (end >= 0)
    {
        Swap(&a[end], &a[0]);
        end--;
        AdjustDwon(a, end, 0);
    }
}

// ð������
void BubbleSort(int* a, int n)
{
//    // ��ʽһ
//    for (int j = 0; j < n; ++j)
//    {
//        for (int i = 1; i < n - j; i++)
//        {
//            if (a[i] < a[i - 1])
//            {
//                Swap(&a[i], &a[i - 1]);
//            }
//        }
//    }

    // ��ʽ����
    // ���Դ�end��λ�ÿ�ʼ������ѭ���Ĵ���
    for (int end = n; end > 0; end--)
    {
        // ����
        int exchang = 0;
        for (int i = 1; i < end; i++)
        {
            if (a[i] < a[i - 1])
            {
                Swap(&a[i], &a[i - 1]);
                exchang = 1;
            }
        }
        // �������һ������֮��û�з���������˵���ź�����
        if (exchang == 0)
        {
            break;
        }
    }
}

// �ҳ�a�����У�a[left]��a[right]��a[mid]�д�СΪmiddle��ֵ
int GetMidIndex(int* a, int left, int right)
{
    int mid = (left + right) >> 1;
    // a[left] a[mid] a[right]
    if (a[left] < a[mid])
    {
        if (a[right] > a[mid])
        {
            return mid;
        }
        else if (a[left] < a[right])
        {
            return left;
        }
        else
            return right;
    }
    else // a[left] > a[mid]
    {
        if (a[right] > a[left])
        {
            return left;
        }
        else if(a[mid] > a[right])
        {
            return mid;
        }
        else
            return right;
    }
}

// ��������hoare�汾 ����ָ�뷨
int PartSort1(int* a, int left, int right)
{
    int midIndex = GetMidIndex(a, left, right);
    // ʼ������ȥ��key������ÿ�ζ���key�ŵ�left��λ��
    Swap(&a[left], &a[midIndex]);
    int keyi = left;
    while (left < right)
    {
        // right��С����Ϊѡ��ߵ�ֵΪkey������Ҫright����
        while (left < right && a[right] >= a[keyi])
        {
            right--;
        }
        // left�Ҵ�
        while (left < right && a[left] <= a[keyi])
        {
            left++;
        }
        Swap(&a[left], &a[right]);
    }
    // ��Ϊ�����key = a[left]��key�Ǿֲ��������Ǹı䲻������a��
    int meeti = left;
    Swap(&a[keyi], &a[meeti]);

    return meeti;
}

// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
    // ������ߵ�Ԫ���ó������൱�������һ������
    int key = a[left];
    while (left < right)
    {
        // right����
        while (left < right && a[right] >= key)
        {
            right--;
        }
        // ���ұߵ�Ԫ�طŵ���ߵĿ����棬�ұ߾ͳ�����һ����
        a[left] = a[right];

        // left��
        while (left < right && a[left] <= key)
        {
            left++;
        }
        // ����ߵ�Ԫ�طŵ��ұߵĿ����棬��߾ͳ�����һ����
        a[right] = a[left];
    }

    // ���key���������
    a[left] = key;
    // ����key�źõĺ��ʵ�λ��
    return left;
}

// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
    // �����Ż�����������ȡ��
    int midIndex = GetMidIndex(a, left, right);
    // ʼ������ȥ��key������ÿ�ζ���key�ŵ�left��λ��
    Swap(&a[left], &a[midIndex]);

    int keyi = left;
    int prev = left;
    int cur = left + 1;
    while (cur <= right)
    {
        // ��С
        if (a[cur] < a[keyi] && ++prev != cur)
        {
            Swap(&a[cur], &a[prev]);
        }

        // ����ȥ����ĵط���++cur,������ҲҪ++
        ++cur;
    }

    // ����ѭ�������ҲҪ����һ��
    Swap(&a[keyi], &a[prev]);

    // �����ź�����Ǹ�λ��
    return prev;
}

// ����
void QuickSort(int* a, int begin, int end)
{
    // �ݹ���ֹ����
    if (begin >= end)
        return;

    // 1.����������������ݽ϶࣬����ѡkey���ˣ��ָ��������֧�ݹ�
    // 2.����������������ݽ��٣���ȥ��֧�ݹ鲻̫���㣬��ʱ����ѡ���������
    if (end - begin > 10)
    {
        int meeti = PartSort3(a, begin, end);
        // [begin, meeti - 1] meeti [meeti + 1, end]
        QuickSort(a, begin, meeti - 1);
        QuickSort(a, meeti + 1, end);
    }
    else
    {
        InsertSort(a + begin, end - begin + 1);
    }

}

// �������� �ǵݹ�ʵ��
// �ݹ� �ִ��������Ż��ĺܺã������Ѿ����Ǵ�������
// �������⣺�ݹ�̫�������û�����⣬����ջ�ռ䲻��������ջ���
// ֻ�ܸĳɷǵݹ飬�ĳɷǵݹ���������ʽ��
// 1��ֱ�Ӹĳ�ѭ��-��쳲������������
// 2�����ǵݹ�Ϳ��ŷǵݹ�ȵȣ�ֻ����Stack�洢����ģ��ݹ����
void QuickSortNonR(int* a, int begin, int end)
{
    Stack st;
    StackInit(&st);
    StackPush(&st, begin);
    StackPush(&st, end);

    while (!StackEmpty(&st))
    {
        int left, right;
        right = StackTop(&st);
        StackPop(&st);

        left = StackTop(&st);
        StackPop(&st);

        // ����һ������
        int keyi = PartSort1(a, left, right);
        // ��������
        if (left < keyi - 1)
        {
            StackPush(&st, left);
            StackPush(&st, keyi - 1);
        }
        // ��������
        if (keyi + 1 < right)
        {
            StackPush(&st, keyi + 1);
            StackPush(&st, right);
        }
    }

    StackDestory(&st);
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
    if (left >= right)
        return;

    int mid = (left + right) >> 1;
    // ��mid��ߺ��ұ�ͨ���ݹ��ź���
    _MergeSort(a, left, mid, tmp);
    _MergeSort(a, mid + 1, right, tmp);

    // ���й鲢
    int begin1 = left, end1 = mid;
    int begin2 = mid + 1, end2 = right;
    int i = left; // ���������tmp����
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (a[begin1] < a[begin2])
            tmp[i++] = a[begin1++];
        else
            tmp[i++] = a[begin2++];
    }
    // ����ɨβ
    while (begin1 <= end1)
        tmp[i++] = a[begin1++];

    while (begin2 <= end2)
        tmp[i++] = a[begin2++];

    // ��tmp�����ֵ���Ƶ�a��������ȡ
    for (int j = left; j <= right; j++)
        a[j] = tmp[j];
}

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n)
{
    // ����ʱ���鿪�ٿռ�
    int* tmp = (int*)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    _MergeSort(a, 0, n - 1, tmp);

    free(tmp);
}
