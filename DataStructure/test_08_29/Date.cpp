//
// Created by ��� on 2022-08-30.
//

#include "Date.h"

// ��
inline int GetMonthDay(int year, int month)
{
    // ����洢ƽ��ÿ���µ�����
    static int dayArray[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = dayArray[month];
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        day = 29;
    }
    return day;
}

// �����Ͷ����ȱʡ�����������߶���
Date::Date(int year, int month, int day)
{
    // ������ڵĺϷ���
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
        cout << "�Ƿ�����" << endl;
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
    _day += day;
    // �������Ϸ������Ͻ�λ�������Ϸ�
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

    return *this;
}

// d1 + 100;
Date Date::operator+(int day)
{
    Date ret(*this);
    ret._day += day;

    // �������Ϸ������Ͻ�λ�������Ϸ�
    while (ret._day > GetMonthDay(ret._year, ret._month))
    {
        ret._day -= GetMonthDay(ret._year, ret._month);
        ret._month++;
        if (ret._month > 12)
        {
            ++ret._year;
            ret._month = 1;
        }
    }

    return ret;
}

//Date Date::operator-(int day);