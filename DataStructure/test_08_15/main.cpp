//#include <stdio.h>
//#include <string.h>
//
//namespace bit
//{
//    int scanf = 10;
//    int strlen = 20;
//
//    // Ƕ�׶��������ռ�
//    namespace N3
//    {
//        int c;
//        int d;
//        int Sub(int left, int right)
//        {
//            return left - right;
//        }
//    }
//}

//int main()
//{
//    // ��ӡ�⺯���е�scanf��strlen�ĵ�ַ
//    // û��ָ��Ĭ�Ϸ��ʾֲ�����ȫ�ֵ�
//    printf("%x\n", scanf);
//    printf("%x\n", strlen);
//
//    // ָ������bit��������ռ������scanf��strlen
//    printf("%x\n", bit::scanf);
//    printf("%x\n", bit::strlen);
//
//    // Ƕ�׶���������ռ��ʹ��
//    bit::N3::Sub(10, 3);
//
//    return 0;
//}


#include <iostream>

using namespace std;

//int main()
//{
//    std::cout << "helloworld" << std::endl;
//
//    // ����̨ʹ��cin�����ʱ�򣬿ո��ʾ����
//    char str[10];
//    int a = 10;
//    std::cin >> a;
//    std::cin >> str;
//
//    std::cout << a << str << std::endl;
//
//    return 0;
//}

// ȱʡ����
//void TestFunc(int a = 0)
//{
//    cout << a << endl;
//}
//
//int main()
//{
//    TestFunc();
//    TestFunc(10);
//}

// ȫȱʡ
//void TestFunc(int a = 10, int b = 20, int c = 30)
//{
//    cout<<"a = "<<a<<endl;
//    cout<<"b = "<<b<<endl;
//    cout<<"c = "<<c<<endl << endl;
//}
//
//int main()
//{
//    TestFunc(1, 2, 3);
//    TestFunc();
//    TestFunc(1);
//}
// ��ȱʡ
//void TestFunc1(int a, int b = 20, int c = 30)
//{
//    cout<<"a = "<<a<<endl;
//    cout<<"b = "<<b<<endl;
//    cout<<"c = "<<c<<endl << endl;
//}
//
//int main()
//{
//    TestFunc1(1, 2, 3);
//    TestFunc1(1);
//}

// ȱʡ���������ã�
//struct Stack
//{
//    int* a;
//    int size;
//    int capacity;
//};
//
//void StackInit(struct Stack* ps, int InitCapacity = 4)
//{
//    ps->a = (int*)malloc(sizeof(int) * InitCapacity);
//    ps->size = 0;
//    ps->capacity = InitCapacity;
//}
//
//int main()
//{
//    struct Stack st1;
//
//    // ����ֱ��ջ����Ҫ��100������
//    StackInit(&st1, 100);
//
//    // ���費֪��ջ����Ҫ����ٸ����ݣ�����ֱ��ȱʡ
//    StackInit(&st1);
//
//}
// ��������
int Add(int left, int right)
{
    return left + right;
}

double Add(double left, double right)
{
    return left + right;
}

int main()
{
    cout << Add(1, 3) << endl;
    cout << Add(1.1, 3.2) << endl;

    return 0;
}
