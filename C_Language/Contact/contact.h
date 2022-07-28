//
// Created by 旭哥 on 2022-07-27.
//

#ifndef CONTACT_CONTACT_H
#define CONTACT_CONTACT_H

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

// 类型的声明
#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30

// 通讯录初始状态的容量大小
#define DEFAULT_SZ 3

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

// 静态版本
//typedef struct Contact
//{
//    PeoInfo data[MAX]; // 可以存放1000个人的信息
//    int sz;             // 记录通讯录已经保存的信息个数
//}Contact;

// 动态版本
typedef struct Contact
{
    PeoInfo *data; // 可以存放1000个人的信息
    int sz;        // 记录通讯录已经保存的信息个数
    int capacity;  // 当前通讯录最大容量
}Contact;

// 函数的声明

// 初始化通讯录
void InitContact(Contact* pc);

// 销毁通讯录
void DestoryContact(Contact* pc);

// 添加联系人
void AddContact(Contact* pc);

// 打印通讯录中的信息
void PrintContact(const Contact* pc);

// 删除指定联系人
void DelContact(Contact* pc);

// 查找指定联系人
void SearchContact(const Contact* pc);

// 修改指定联系人的信息
void ModifyContact(Contact* pc);

// 按照名字排序
void SortContact(Contact* pc);



#endif//CONTACT_CONTACT_H
