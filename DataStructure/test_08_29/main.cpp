//#include <iostream>
//
//using namespace std;

//class Date
//{
//public:
//    // 编译时会增加一个隐含的参数
//    // void Init(Date* this, int year, int month, int day)
//    void Init(int year, int month, int day)
//    {
//        // 这里可以对日期的合法性进行检查
//
//        _year = year;
//        _month = month;
//        _day = day;
//        cout << "this:" << this << endl;
//    }
//private:
//    // 凡是成员变量，建议命名风格区分一下
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    Date d1;
//    // d1.year = 2021;
//    cout << "d1:" << &d1 << endl;
//    d1.Init(2021, 8, 29);
//    Date d2;
//    cout << "d2:" << &d2 << endl;
//    d2.Init(2021, 8, 30);
//}

// 关于this指针的分析题
//class A
//{
//public:
//    void PrintA()
//    {
//        cout<<_a<<endl;
//    }
//    void Show()
//    {
//        cout<<"Show()"<<endl;
//    }
//private:
//    int _a;
//};
//
//int main()
//{
//    A* p = nullptr;
//    p->PrintA(); // 错误：空指针访问
//    //p->Show();   // 正常运行
//}

// 类里面成员函数，我们什么都不写的时候，编译器会自动生成6个函数，这6个函数叫默认成员函数

// 1. 构造函数：对对象的初始化
//class Date
//{
//public:
//    // 可能我们会忘记调用它
//    // C++为了解决这个问题，引入构造函数,来初始化
////    void Init(int year, int month, int day)
////    {
////        _year = year;
////        _month = month;
////        _day = day;
////    }
//
//    // 构造函数->实例话对象的时候自动调用
//    // 全缺省参数的构造函数，不再使用重载这么麻烦了
//    Date(int year = 0, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    // 重载
////    Date()
////    {
////        _year = 0;
////        _month = 1;
////        _day = 1;
////    }
//
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    // 对象实例化时自动调用构造函数，参数也要一致的哦
//    Date d1(2021, 5, 24);
//    d1.Print();
//
//    Date d2;
//    d2.Print();
//
//}

//class A
//{
//public:
//    A(int a = 0)
//    {
//        cout << "A(int a = 0)构造函数" << endl;
//        _a = a;
//    }
//
//    void Print()
//    {
//        cout << _a << endl;
//    }
//private:
//    int _a;
//};
//
//class Date
//{
//public:
//    // 我们不写，编译器会默认会生成一个构造函数，我们写了编译器就不会生成了
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//        _aa.Print();
//    }
//
//private:
//    // 内置类型
//    int _year;
//    int _month;
//    int _day;
//
//    // 自定义类型
//    A _aa;
//};

// 默认构造函数

//class A
//{
//public:
//    A(int a = 0)
//    {
//        cout << "A(int a = 0)构造函数" << endl;
//        _a = a;
//    }
//
//    void Print()
//    {
//        cout << _a << endl;
//    }
//private:
//    int _a;
//};
//
//class Date
//{
//public:
//    // 我们不写，编译器会默认会生成一个构造函数，我们写了编译器就不会生成了
//
//    Date(int year = 0, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//        _aa.Print();
//    }
//
//private:
//    // 内置类型
//    int _year;
//    int _month;
//    int _day;
//
//    // 自定义类型
//    A _aa;
//};

// 默认构造函数的误区：很多同学认为我们不写，编译器默认生成的那个是默认构造函数

//int main()
//{
//    Date d2;
//    d2.Print();
//
//    return 0;
//}

// 析构函数

//class Date
//{
//public:
//    Date(int year = 0, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    // d1.Equel(d2)
//    bool Equel(Date d)
//    {
//        return _year == d._year
//        && _month == d._month
//        && _day == d._day;
//    }
//    // 重载==
//    bool operator==(Date x)
//    {
//        return _year == x._year
//               && _month == x._month
//               && _day == x._day;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//
//int main()
//{
//    Date d1(2021, 1, 1);
//    Date d2(2021, 1, 1);
//
//    // 内置类型，语言层面就支持运算符
//    // 自定义类型，默认不支持。C++可以用运算符重载来让类对象支持用某个运算符
//
//    // 重载==后的使用方法，下面这两种都是可以的
//    cout << d1.operator==(d2) << endl;
//    cout << (d1 == d2) << endl;
//
//    cout << d1.Equel(d2) << endl;
//
//    return 0;
//}

// 6个默认成员函数  我们不写编译器会默认生成
// 不过很多时候我们都要自己写
// 因为生成的不一定好用

//class Date
//{
//public:
//    Date(int year = 0, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    // 析构函数不需要写，编译默认生成就够用，对象没有内存清理
//    // 默认生成的析构函数也是基本不做什么事情，release一下就没了
//
//    Date(const Date& d)
//    {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//
//    // d1 = d2
//    // 赋值运算符的重载
//    // 改进：支持连续赋值，i = j = k
//    // 为了不使用拷贝构造，返回值传引用
//    // 防止自己给自己赋值d1 = d1
//    Date& operator=(const Date& d)
//    {
//        if (this != &d) // 检查如果不是自己给自己赋值，才需要拷贝
//        {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//
//        return *this;
//    }
//
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//class Stack
//{
//public:
//    Stack(int capacity = 4)
//    {
//        if (capacity <= 0)
//        {
//            _a = nullptr;
//            _size = _capacity = 0;
//        }
//        else
//        {
//            _a = (int*)malloc(sizeof(int) * capacity);
//            _capacity = capacity;
//            _size = 0;
//        }
//    }
//
//    // 析构函数
//    ~Stack()
//    {
//        free(_a);
//        _size = _capacity = 0;
//        _a = nullptr;
//    }
//
//private:
//    int* _a;
//    int _size;
//    int _capacity;
//};
//
//int main()
//{
//    Date d1(2020, 5, 25);
//    Date d2;
//    Date d3(2020, 1, 1);
//    d1.Print();
//    d2.Print();
//
//    // 对=运算符进行重载
//    d1 = d2;
//    d1.Print();
//    d2.Print();
//
//    // 连续赋值
//    d1 = d2 = d3;
//
//    Date d5(d1); // 拷贝构造：拿一个已经存在的对象去构造初始化另一个要创建的对象
//    d1 = d2;     // 赋值重载：两个已经存在的对象->拷贝
//    Date d6 = d1; // 拷贝构造
//
//   return 0;
//}

#include "Date.h"

void Test1()
{
    Date d1(2021, 5, 25);
    d1.Print();

    Date d2(2021, 0, 0);
    d2.Print();

    Date d3(2021, 2, 29);
    d3.Print();
}

void Test2()
{
    Date d1(2021, 5, 25);
    d1.Print();

    d1 += 3;
    d1.Print();
}

void Test3()
{
    Date d1(2021, 5, 25);
    d1.Print();

    Date d2 = d1 + 3;
    d2.Print();
}

void Test4()
{
    Date d1(2021, 5, 25);
    d1 -= 120;
    d1.Print();

    Date d2(2021, 5, 27);
    d2 -= -100;
    d2.Print();
}

void Test5()
{
    Date d1(2021, 5, 27);

    // 前置++和后置++都完成了++，不同的地方在于返回值不一样
    // 因为他们的运算符是一样的，函数名就是一样的
    // 为了区分，对后置++做了特殊处理，加了一个参数，形成用函数重载
    Date ret1 = d1++;
    ret1.Print();
    d1.Print();

    Date ret2 = ++d1;
    ret2.Print();
    d1.Print();
}

int main()
{
   // Test1();
   // Test2();
   // Test3();
   // Test4();
   Test5();

    return 0;
}