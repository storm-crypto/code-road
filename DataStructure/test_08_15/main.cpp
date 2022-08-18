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

// 缺省参数的作用：
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
//    // 假设直到栈里面要存100个数据
//    StackInit(&st1, 100);
//
//    // 假设不知道栈里面要存多少个数据，可以直接缺省
//    StackInit(&st1);
//
//}
//// 函数重载
//int Add(int left, int right)
//{
//    return left + right;
//}
//
//double Add(double left, double right)
//{
//    return left + right;
//}
//
//int main()
//{
//    cout << Add(1, 3) << endl;
//    cout << Add(1.1, 3.2) << endl;
//
//    return 0;
//}

// 引用
//int main()
//{
//    int a = 10;
//
//    // b是a的别名(b是a的引用)
//    int& b = a;
//    b = 30;
//}

// 引用的作用
// 之前写的swap函数
//void swap(int* p1, int* p2)
//{
//    int tmp = *p1;
//    *p1 = *p2;
//    *p2 = tmp;
//}
//
//// 这个函数用了引用跟上面那个函数的作用是一样的
//// r1、r2分别是a和b的别名
//// 别名指向的是同一块内存空间，所以能够达到交换的作用
//void swap(int& r1, int& r2)
//{
//    int tmp = r1;
//    r1 = r2;
//    r2 = tmp;
//}
//
//int main()
//{
//    int a = 1;
//    int b = 2;
//
//    //swap(&a, &b);
//
//    swap(a, b);
//
//    return 0;
//}


//int main()
//{
//    // 一个变量可以有多个引用
//    int a = 0;
//    int& b = a;
//    int& c = a;
//    int&d = b;
//
//    // 引用必须初始化
//    int& r = a;
//
//    // 引用一旦引用一个实体，就不能引用其他实体
//    int x = 10;
//    // 不是让r变成x的别名，而是把x的值赋值给r
//    r = x;
//
//}

//int main()
//{
//    const int a = 10;
//    // 下面这个ra属于权限放大，所以不行
//    // int& ra = a;
//
//    const int& ra = a;
//
//
//    // 权限缩小,可以
//    int b = 10;
//    int& rb = b;
//    const int& crb = b;
//
//    int c = 0;
//    // double& rc = c; // 会报错
//    const double& rc = c; // rc是给c的临时变量取别名
//
//    return 0;
//}

// 传引用返回
//int& Add(int a, int b)
//{
//    int c = a + b;
//    return c;
//}
//
//int main()
//{
//    int& ret = Add(2, 3);
//    Add(5, 7);
//
//    cout << ret << endl;
//
//    return 0;
//}

// 范围的for循环(C++11新语法遍历)
int main()
{
    int array[] = {1, 2, 3, 4, 5};

    // 自动遍历，依次取出array中的元素，赋值给e，直到结束
    for (auto e : array)
    {
        cout << e << " ";
    }
    cout << endl;

    // 将array数组里面的每个数都*2
    for (auto& e : array)
    {
        e *= 2;
    }
    for (auto e : array)
    {
        cout << e << " ";
    }
    cout << endl;


    return 0;
}