
#include <activdbg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//int main()
//{
////    int age = 0;
////    scanf("%d", &age);
//
//   /* if (age >= 18)
//        printf("����\n");*/
//
//    /*if (age >= 18)
//        printf("����\n");
//    else
//        printf("δ����\n");*/
//
////    if (age < 18)
////        printf("������\n");
////    else if (age >= 18 && age < 30)
////        printf("����\n");
////    else if (age >= 30 && age < 50)
////        printf("����\n");
////    else
////        printf("������\n");
//
//    int a = 0;
//    int b = 2;
//    if (a == 1)
//        if (b == 2)
//            printf("hehe\n");
//    else
//        printf("haha\n");
//
//    return 0;
//}

//int test()
//{
//    int a = 0;
//
//    if (a)
//        return 1;
//
//    return 0;
//}
//
//int main()
//{
//    int ret = test();
//    printf("ret = %d\n", ret);
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    printf("������һ������:");
//    scanf("%d", &n);
//    if (n % 2 == 0)
//    {
//        printf("��������");
//    }
//    else
//    {
//        printf("������");
//    }
//    return 0;
//}

//int main()
//{
//    for (int i = 1; i <= 100; i++)
//    {
//        if (i % 2 == 1)
//            printf("%d ", i);
//    }
//    return 0;
//}

//int main()
//{
//    int day = 0;
//    scanf("%d", &day);
//    switch (day)
//    {
//        case 1:
//            printf("Monday\n");
//            break;
//        case 2:
//            printf("Tuesday\n");
//            break;
//        case 3:
//            printf("Wednesday\n");
//            break;
//        case 4:
//            printf("Thursday\n");
//            break;
//        case 5:
//            printf("Friday\n");
//            break;
//        case 6:
//            printf("Saturday\n");
//            break;
//        case 7:
//            printf("Sunday\n");
//            break;
//        default:
//            printf("�������");
//            break;
//    }
//}

//int main()
//{
//    int i = 1;
//    while (i <= 10)
//    {
//        if (i == 5) continue;
//        printf("%d ", i);
//        i++;
//    }
//}

//int main(){
//    char password[20] = {0};
//    printf("���������룺");
//
//    scanf("%s", password);
//    int tmp = 0;
//    // ��һ��ɸ����Щ���������Ļس��ַ�(\n)���������������Щ�ո�
//    while ((tmp = getchar()) != '\n');
//
//    printf("��ȷ�����루Y/N��");
//    int ch = getchar();
//    if ('Y' == ch)
//        printf("ȷ�ϳɹ�");
//    else
//        printf("ȷ��ʧ��");
//}

//int main(){
//    int i = 0;
//    for (i = 1; i <= 10; i++)
//    {
//        if (5 == i) continue;
//        printf("%d ", i);
//    }
//    return 0;
//}

//int main()
//{
//    int i = 0;
//    int j = 0;
//    for (; i < 10; i++)
//    {
//        for (; j < 10; j++)
//        {
//            printf("hehe\n");
//        }
//    }
//}

//int main()
//{
//    int i = 1;
//    do
//    {
//        if (i == 5) continue;
//        printf("%d ", i);
//        i++;
//    } while (i <= 10);
//    return 0;
//}

// 1. ����n�Ľ׳�
//int main(){
//    int n = 0;
//    printf("������һ������");
//    scanf("%d", &n);
//    int i = 0;
//    int ret = 1;
//    for (i = 1; i <= n; i++)
//    {
//       ret = ret * i;
//    }
//    printf("%d", ret);
//    return 0;
//}

// 2. ����1! + 2! + 3! + ���� + 10��
//int main()
//{
//    int i = 0;
//    int res1 = 1; // ����ÿ���׳˵Ĵ�
//    int res2 = 0; // �������մ�
//    for (i = 1; i <= 10; i++)
//    {
//        res1 = res1 * i;
//        res2 += res1;
//    }
//
//    printf("%d ", res2);
//    return 0;
//}

// 3.��һ�����������в��Ҿ��������n(���ֲ���)
//int main()
//{
//    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int k = 7;
//    int sz = sizeof(arr) / sizeof(arr[0]);  // ����������Ҷ��ٸ�Ԫ��
//    // ����k
//    int l = 0; // ���±�
//    int r = sz - 1; // ���±�
//    while (l <= r)
//    {
//        int mid  = (l + r) / 2; // �м�ֵ
//        if (arr[mid] < k)
//        {
//            l = mid + 1;
//        }
//        else if (arr[mid] > k)
//        {
//            r = mid - 1;
//        }
//        else
//        {
//            printf("�ҵ��ˣ��±���%d\n", mid);
//            break;
//        }
//    }
//    if (l > r)
//    {
//        printf("�Ҳ�����\n");
//    }
//
//    return 0;
//}
//#include <stdlib.h>
//#include <windows.h>
//#include <string.h>
//// 4. ��д���룬��ʾ����ַ��������ƶ������м���
//int main()
//{
//    char arr1[] = "welcome to bit!!!!!";
//    char arr2[] = "###################";
//
//    int left = 0;
//    // int right = sizeof(arr1) / sizeof(arr1[0]) - 2; ��Ϊ�ַ����Ľ�β����'\0'
//    int right = strlen(arr1) - 1;
//
//    while (left <= right)
//    {
//        arr2[left] = arr1[left];
//        arr2[right] = arr1[right];
//        printf("%s\n", arr2);
//        Sleep(1000); // ��λ�Ǻ���
//        //system("cls");
//        left++;
//        right--;
//    }
//
//
//    return 0;
//
//}

// 5.��д����ʵ�֣�ģ���û���¼�龰��
// ����ֻ�ܵ�¼3�Σ�ֻ���������������룬���������ȷ����ʾ��¼�ɹ���������ξ�����������˳�����
//int main()
//{
//    int i = 0;
//    char password[20] = {0};
//    // ������ȷ������123456
//    for (i = 0; i < 3; i++)
//    {
//        printf("���������룺");
//        scanf("%s", password);
//        if (strcmp(password, "123456") == 0)
//        {
//            printf("������ȷ����¼�ɹ�\n");
//            break;
//        }
//        else
//        {
//            printf("�����������������\n");
//        }
//    }
//    if (3 == i)
//    {
//        printf("�����������ζ�����\n");
//    }
//
//}

// ��������Ϸ

//void menu()
//{
//    printf("-----------------\n");
//    printf("----1. ��ʼ��Ϸ---\n");
//    printf("----0. �˳���Ϸ---\n");
//    printf("-----------------\n");
//}
//// ��������Ϸ
//void game()
//{
//    int guess = 0;
//    // 1. ���������
//    int ret = rand() % 100 + 1;
//    // 2. ������
//
//    while(1)
//    {
//        printf("���������֣�");
//        scanf("%d", &guess);
//        if (guess < ret)
//        {
//            printf("��С��\n");
//        }
//        else if (guess > ret)
//        {
//            printf("�´���\n");
//        }
//        else
//        {
//            printf("��ϲ��¶���\n");
//            break;
//        }
//    }
//}
//
//int main()
//{
//    int input = 0;
//    srand((unsigned int) time(NULL));
//    do
//    {
//        menu();
//        printf("��ѡ��");
//        scanf("%d", &input);
//        switch (input)
//        {
//            case 1:
//                game();
//                break;
//            case 0:
//                printf("�˳���Ϸ\n");
//                break;
//            default:
//                printf("������������������\n");
//                break;
//        }
//    } while (input);
//
//    return 0;
//}

//int main()
//{
//    char input[20] = {0};
//
//    system("shutdown -s -t 60");//system��һ���⺯��������ִ��ϵͳ�����
//n:
//    printf("��ע�⣬��ĵ��Խ���1���Ӻ�ػ���������룺��������ȡ���ػ�\n");
//    scanf("%s", input);
//    // �ж�
//    if (strcmp(input, "������") == 0)
//    {
//        system("shutdown -a");
//    }
//    else
//    {
//        goto n;
//    }
//}

//int main()
//{
//    char input[20] = {0};
//
//    system("shutdown -s -t 60");//system��һ���⺯��������ִ��ϵͳ�����
//    while(1)
//    {
//        printf("��ע�⣬��ĵ��Խ���1���Ӻ�ػ���������룺��������ȡ���ػ�\n");
//        scanf("%s", input);
//        // �ж�
//        if (strcmp(input, "������") == 0)
//        {
//            system("shutdown -a");
//            break;
//        }
//    }
//
//}

// �����������մ�С�����˳�����
//int main()
//{
//    int a = 2;
//    int b = 3;
//    int c = 1;
//
//    scanf("%d%d%d", &a, &b, &c);
//
//    if (a < b)
//    {
//        int tmp = a;
//        a = b;
//        b = tmp;
//    }
//    if (a < c)
//    {
//        int tmp = a;
//        a = c;
//        c = tmp;
//    }
//    if (b < c)
//    {
//        int tmp = b;
//        b = c;
//        c = tmp;
//    }
//    printf("%d %d %d", a, b, c);
//
//    return 0;
//}


// ���1~100��3�ı���
//int main()
//{
//    int i = 0;
//    for (i = 1; i <= 100; i++)
//    {
//        if (i % 3 == 0)
//            printf("%d ", i);
//    }
//}

// �����ֵ
//int main()
//{
//    int arr[] = {1, 5, 66, 54, 23, 4, 9, 8, 12, 11};
//    int max = 0;
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        if (arr[i] > max)
//            max = arr[i];
//    }
//    printf("%d", max);
//}

//int main()
//{
//    int i = 0;
//    int j = 0;
//    for (i = 100; i <= 200; i++)
//    {
//        for (j = 2; j < i; j++)
//        {
//            if (i % j == 0) break;
//        }
//        if (j == i)
//            printf("%d ", i);
//    }
//}

// ��������������N�ܹ���4���������Ҳ��ܱ�100��������������
//           ���ߣ�N�ܱ�400������Ҳ������
//     ����4��һ���Ұ��겻��ÿ400������һ��
//int main()
//{
//    int i = 0;
//    for (i = 1000; i <= 2000; i++)
//    {
//        if ((i % 4 == 0 && i % 100 != 0)|| i % 400 == 0)
//            printf("%d ", i);
//    }
//}

// ��ҵ12��������Ŀ
// ��һ�����������鷳����֪����ô��flag������ɸ����������
//int main()
//{
//    double sum = 0.0;
//    int i = 0;
//    int flag = 1;
//    for (i = 1; i <= 100; i++)
//    {
//        sum += flag * 1.0 / i;
//        flag = -flag;
//    }
//    printf("���ս����%lf", sum);
//    return 0;
//}

// ������Ϸ

//void menu()
//{
//    printf("---------------\n");
//    printf("----1. ��ʼ��Ϸ-\n");
//    printf("----0. �뿪��Ϸ-\n");
//    printf("---------------\n");
//}
//
//void game()
//{
//    int guess = 0;
//
//    // 1.���������
//    int ret = rand() % 100 + 1;
//
//    while (1){
//        printf("����������:");
//        scanf("%d", &guess);
//        if (guess < ret)
//        {
//            printf("̫С��\n");
//        }
//        else if (guess > ret)
//        {
//            printf("̫����\n");
//        }
//        else
//        {
//            printf("�¶���\n");
//            break;
//        }
//    }
//
//}
//
//int main()
//{
//    srand((unsigned int) time(NULL));
//    int input = 0;
//    do
//    {
//        menu();
//        printf("���������ѡ��:");
//        scanf("%d", &input);
//        switch(input)
//        {
//            case 1:
//                game();
//                break;
//            case 0:
//                printf("�뿪��Ϸ\n");
//                break;
//            default:
//                printf("��������ȷ������\n");
//                break;
//        }
//    } while (input);
//    return 0;
//}

// ���ֲ���
//int main()
//{
//    int arr[] = {1, 2, 3 , 4, 5, 6, 7, 8, 9, 10};
//
//    int k = 7;
//
//    int l = 0;
//    int r = sizeof (arr) / sizeof (arr[0]) - 1;
//
//    while (l <= r)
//    {
//        int mid = (l + r) / 2;
//        if (k > arr[mid])
//        {
//            l = mid + 1;
//        }
//        else if (k < arr[mid])
//        {
//            r = mid - 1;
//        }
//        else
//        {
//            printf("7��Ӧ���±���:%d", mid);
//            break;
//        }
//
//    }
//    if (l > r)
//    {
//        printf("�Ҳ���\n");
//    }
//}


// ���������������������������Լ��
//���磺
//���룺20 40
//�����20

/*
���Լ���������������й���Լ��������ߡ�
���ķ�ʽ�Ƚ϶࣬������١�շת�������������𷨡�Stein�㷨�㷨
�˴���Ҫ���ܣ�շת�����
˼·��
���ӣ�18��24�����Լ��
��һ�Σ�a = 18  b = 24  c = a%b = 18%24 = 18
      ѭ���У�a = 24   b=18
�ڶ��Σ�a = 24   b = 18  c = a%b = 24%18 = 6
      ѭ���У�a = 18   b = 6
�����Σ�a = 18   b = 6   c=a%b = 18%6 = 0
  ѭ������

��ʱb�е����ݼ�Ϊ�������е����Լ����
*/
//int main()
//{
//    int a = 20;
//    int b = 40;
//    int c = 0;
//    while (c = a % b)
//    {
//        a = b;
//        b = c;
//    }
//    printf("%d ", b);
//    return 0;
//}

// ��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9

//int main()
//{
//    int i = 0;
//    int count = 0;
//
//    for (i = 1; i <= 100; i++)
//    {
//        if (i % 10 == 9)
//            count++;
//        if (i / 10 == 9)
//            count++;
//    }
//    printf("%d ", count);
//}

// ��ӡ9*9�˷���
//int main()
//{
//    int i = 0;
//    int j = 0;
//
//    for (i = 1; i <= 9; i++)
//    {
//        for (j = 1; j <= i; j++)
//        {
//            printf("%d * %d = %2d  ", i, j, i*j);
//        }
//        printf("\n");
//    }
//    return 0;
//}