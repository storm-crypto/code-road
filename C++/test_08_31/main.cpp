#include <iostream>
using namespace std;

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
//    bool operator==(const Date& d) const
//    {
//        return _year == d._year
//        && _month == d._month
//        && _day == d._day;
//    }
//
//    void Print() const
//    {
//        cout << _year << "年" << _month << "月" << _day << "日" << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//int main()
//{
//    Date d1(2021, 5, 27);
//    Date d2(2021, 5, 27);
//
//
//    return 0;
//}


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
//    // 了解一下
//    // 他们基本没有被自己实现的价值
//    // 可以不自己写，编译器默认生成的就够用了
//    Date* operator&()
//    {
//        return this;
//    }
//
//    const Date* operator&() const
//    {
//        return this;
//    }
//
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//int main()
//{
//    Date d1(2021, 5, 27);
//    Date d2(2021, 5, 27);
//
//
//    return 0;
//}

//class Date
//{
//    // 友元函数的声明
//    friend ostream& operator<<(ostream& out, const Date& d);
//    friend istream& operator>>(istream& in, Date& d);
//
//public:
//    Date(int year = 0, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//// cout << d1;
//ostream& operator<<(ostream& out, const Date& d)
//{
//    out << d._year << "-" << d._month << "-" << d._day << endl;
//    return out;
//}
//
//// cin >> d1
//istream& operator>>(istream& in,  Date& d)
//{
//    in >> d._year >> d._month >> d._day;
//    return in;
//}
//
//
//int main()
//{
//    Date d1;
//    //cin >> d1;
//    cout << d1;
//
//    return 0;
//}

class A
{
public:
    explicit A(int a)
        :_a(a)
    {}

private:
    int _a;
};

int main()
{
    A aa1(1); // 拷贝构造
    // 单参数的构造函数，支持这样的隐式类型转换
    A aa2 = 2;
    // 用了explicit就不能用上面那种隐式类型转换了


    return 0;
}