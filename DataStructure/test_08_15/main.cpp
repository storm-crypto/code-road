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
void TestFunc1(int a, int b = 20, int c = 30)
{
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl << endl;
}

int main()
{
    TestFunc1(1, 2, 3);
    TestFunc1(1);
}