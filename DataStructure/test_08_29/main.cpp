#include <iostream>

using namespace std;

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
class Date
{
public:
    // 可能我们会忘记调用它
    // C++为了解决这个问题，引入构造函数,来初始化
//    void Init(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }

    // 构造函数->实例话对象的时候自动调用
    // 全缺省参数的构造函数，不再使用重载这么麻烦了
    Date(int year = 0, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    // 重载
//    Date()
//    {
//        _year = 0;
//        _month = 1;
//        _day = 1;
//    }

    void Print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    // 对象实例化时自动调用构造函数，参数也要一致的哦
    Date d1(2021, 5, 24);
    d1.Print();

    Date d2;
    d2.Print();

}