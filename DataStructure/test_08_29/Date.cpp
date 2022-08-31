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
    if (day < 0)
    {
        *this -= -day;
    }
    else
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
    }


    return *this;
}

// d1 + 100;
//Date Date::operator+(int day)
//{
//    Date ret(*this);
//    ret._day += day;
//
//    // �������Ϸ������Ͻ�λ�������Ϸ�
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

// ����+=
Date Date::operator+(int day)
{
    Date ret(*this);
    // ����+=
    ret += day;

    return ret;
}

// d -= 100
// day�Ǹ�������ô����
Date& Date::operator-=(int day)
{
    if (day < 0)
    {
//        _day += -day;
//        // �������Ϸ������Ͻ�λ�������Ϸ�
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
        // �Ż�������һ��+=
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

// --d
Date& Date::operator--()
{
    *this -= 1;
    return *this;
}

// d--
Date Date::operator--(int)
{
    Date tmp(*this);
    *this -= 1;
    return tmp;
}

// d1 > d2 ->d1.operator(&d1, d2);
bool Date::operator>(const Date& d)
{
    if (_year > d._year)
    {
        return true;
    }
    else if (_year == d._year)
    {
        if (_month > d._month)
        {
            return true;
        }
        else if(_month == d._month)
        {
            if (_day > d._day)
            {
                return true;
            }
        }
    }

    return false;
}

bool Date::operator==(const Date& d)
{
    return _year == d._year
           && _month == d._month
           && _day == d._day;
}

// ���� > �� ==
bool Date::operator<(const Date& d)
{
    return !(*this >= d);
}

// d1 >= d2
bool Date::operator>=(const Date& d)
{
    return *this > d || *this == d;
}
bool Date::operator<=(const Date& d)
{
    return !(*this > d);
}

bool Date::operator!=(const Date& d)
{
    return !(*this == d);
}