//
// Created by 旭哥 on 2022-08-30.
//

#include "Date.h"

// 妙
inline int GetMonthDay(int year, int month)
{
    // 数组存储平年每个月的天数
    static int dayArray[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = dayArray[month];
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        day = 29;
    }
    return day;
}

// 声明和定义的缺省参数不能两边都有
Date::Date(int year, int month, int day)
{
    // 检查日期的合法性
    if (year >= 0
        && month > 0 && month < 13
        && day > 0 && day <= GetMonthDay(year, month))
    {
        _year = year;
        _month = month;
        _day = day;
    }
    else
    {
        cout << "非法日期" << endl;
        cout << _year << "-" << _month << "-" << _day << endl;
        // assert(false);
    }


}

void Date::Print()
{
    cout << _year << "-" << _month << "-" << _day << endl;
}

// d += 100
Date& Date::operator+=(int day)
{
    if (day < 0)
    {
        *this -= -day;
    }
    else
    {
        _day += day;
        // 天数不合法，不断进位，让他合法
        while (_day > GetMonthDay(_year, _month))
        {
            _day -= GetMonthDay(_year, _month);
            _month++;
            if (_month > 12)
            {
                ++_year;
                _month = 1;
            }
        }
    }


    return *this;
}

// d1 + 100;
//Date Date::operator+(int day)
//{
//    Date ret(*this);
//    ret._day += day;
//
//    // 天数不合法，不断进位，让他合法
//    while (ret._day > GetMonthDay(ret._year, ret._month))
//    {
//        ret._day -= GetMonthDay(ret._year, ret._month);
//        ret._month++;
//        if (ret._month > 12)
//        {
//            ++ret._year;
//            ret._month = 1;
//        }
//    }
//
//    return ret;
//}

// 复用+=
Date Date::operator+(int day)
{
    Date ret(*this);
    // 复用+=
    ret += day;

    return ret;
}

// d -= 100
// day是负数，怎么处理？
Date& Date::operator-=(int day)
{
    if (day < 0)
    {
//        _day += -day;
//        // 天数不合法，不断进位，让他合法
//        while (_day > GetMonthDay(_year, _month))
//        {
//            _day -= GetMonthDay(_year, _month);
//            _month++;
//            if (_month > 12)
//            {
//                ++_year;
//                _month = 1;
//            }
//        }
        // 优化：复用一下+=
        *this += -day;
    }
    else
    {
        _day -= day;
        while (_day <= 0)
        {
            --_month;
            if (_month == 0)
            {
                --_year;
                _month = 12;
            }

            _day += GetMonthDay(_year, _month);
        }
    }

    return *this;
}

Date Date::operator-(int day)
{
    Date tmp = *this;
    // Date tmp(*this);
    tmp -= day;

    return tmp;
}

// ++d
Date& Date::operator++()
{
    *this += 1;
    return *this;
}

// d++
Date Date::operator++(int)
{
    Date tmp(*this);
    *this += 1;
    return tmp;
}