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

class Date
{
    // 友元函数的声明
    friend void operator<<(ostream& out, const Date& d);
    friend void operator>>(istream& in, Date& d);

public:
    Date(int year = 0, int month = 1, int day = 1)
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

// cout << d1;
void operator<<(ostream& out, const Date& d)
{
    out << d._year << "-" << d._month << "-" << d._day << endl;
}

// cin >> d1
void operator>>(istream& in,  Date& d)
{
    in >> d._year;
    in >> d._month;
    in >> d._day;
}


int main()
{
    Date d1;
    //cin >> d1;
    cout << d1;

    return 0;
}