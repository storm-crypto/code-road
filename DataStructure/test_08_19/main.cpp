#include <iostream>

using namespace std;
//class Date
//{
//public:
//    void Init(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
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
//    d1.Init(2022, 8, 20);
//    Date d2;
//    d2.Init(2021, 8, 20);
//
//    return 0;
//}

// 1.下面程序能编译通过吗？
// 2.下面程序会崩溃吗？在哪里崩溃
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
//    A* p = NULL;
//    p->PrintA();
//    p->Show();
//}

// 类里面成员函数什么都不写的时候，编译器会默认
//class Date
//{
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};

// 构造函数的重载
class Date
{
public:
    // 1. 无参构造函数
    Date()
    {}

    // 2. 带参构造函数
    Date(int year, int month, int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }

private:
    int _year;
    int _month;
    int _day;
};

void TestDate()
{
    Date d1;                // 调用无参构造函数
    Date d2(2022, 1, 1);    //调用有参构造函数
}