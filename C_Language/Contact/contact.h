//
// Created by 旭哥 on 2022-07-27.
//

#ifndef CONTACT_CONTACT_H
#define CONTACT_CONTACT_H

// 类型的声明
#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30

enum Option
{
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SORT,
    PRINT
};

typedef struct PeoInfo
{
    char name[NAME_MAX];
    char sex[SEX_MAX];
    int age;
    char tele[TELE_MAX];
    char addr[ADDR_MAX];
}PeoInfo;

typedef struct Contact
{
    PeoInfo data[MAX]; // 可以存放1000个人的信息
    int sz;             // 记录通讯录已经保存的信息个数
}Contact;

// 函数的声明

#endif//CONTACT_CONTACT_H
