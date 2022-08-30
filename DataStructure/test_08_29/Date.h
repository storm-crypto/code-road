//
// Created by ��� on 2022-08-30.
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
    // ���캯��
    Date(int year = 0, int month = 1, int day = 1);
    void Print();

    // �������������졢��ֵ���أ����Բ�д��Ĭ�����ɵľ͹�����
    // Stack����Ҫ�Լ�д������

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
