//
// Created by 旭哥 on 2022-08-30.
//

#ifndef TEST_08_29_DATE_H
#define TEST_08_29_DATE_H

#include <iostream>
#include <assert.h>

using std::cout;
using std::cin;
using std::endl;


class Date
{
public:
    // 构造函数
    Date(int year = 0, int month = 1, int day = 1);
    void Print();

    // 析构、拷贝构造、赋值重载，可以不写，默认生成的就够用了
    // Stack才需要自己写这三个

    // d + 100
    Date& operator+=(int day);
    Date operator+(int day);
    // d - 100
    Date operator-(int day);

private:
    int _year;
    int _month;
    int _day;
};

#endif//TEST_08_29_DATE_H
