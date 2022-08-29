//
// Created by 旭哥 on 2022-08-30.
//

#include "Date.h"

// 妙
int GetMonthDay(int year, int month)
{
    // 数组存储平年每个月的天数
    int dayArray[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = dayArray[month];
    if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month == 2 )
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

// d + 100
//Date Date::operator+(int day);
//Date Date::operator-(int day);