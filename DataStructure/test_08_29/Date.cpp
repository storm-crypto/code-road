//
// Created by 旭哥 on 2022-08-30.
//

#include "Date.h"

// 声明和定义的缺省参数不能两边都有
Date::Date(int year, int month, int day)
{

}

void Date::Print()
{

}

// d + 100
Date Date::operator+(int day);
Date Date::operator-(int day);