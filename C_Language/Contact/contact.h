//
// Created by ��� on 2022-07-27.
//

#ifndef CONTACT_CONTACT_H
#define CONTACT_CONTACT_H

// ���͵�����
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
    PeoInfo data[MAX]; // ���Դ��1000���˵���Ϣ
    int sz;             // ��¼ͨѶ¼�Ѿ��������Ϣ����
}Contact;

// ����������

#endif//CONTACT_CONTACT_H
