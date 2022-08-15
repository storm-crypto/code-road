//#include <stdio.h>
//#include <string.h>
//
//namespace bit
//{
//    int scanf = 10;
//    int strlen = 20;
//
//    // 嵌套定义命名空间
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
//    // 打印库函数中的scanf和strlen的地址
//    // 没有指定默认访问局部或者全局的
//    printf("%x\n", scanf);
//    printf("%x\n", strlen);
//
//    // 指定访问bit这个命名空间里面的scanf和strlen
//    printf("%x\n", bit::scanf);
//    printf("%x\n", bit::strlen);
//
//    // 嵌套定义的命名空间的使用
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
//    // 控制台使用cin输入的时候，空格表示换行
//    char str[10];
//    int a = 10;
//    std::cin >> a;
//    std::cin >> str;
//
//    std::cout << a << str << std::endl;
//
//    return 0;
//}

// 缺省参数
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

// 全缺省
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
// 半缺省
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