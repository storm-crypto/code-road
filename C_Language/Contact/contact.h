//
// Created by ��� on 2022-07-27.
//

#ifndef CONTACT_CONTACT_H
#define CONTACT_CONTACT_H

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

// ���͵�����
#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30

// ͨѶ¼��ʼ״̬��������С
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

// ��̬�汾
//typedef struct Contact
//{
//    PeoInfo data[MAX]; // ���Դ��1000���˵���Ϣ
//    int sz;             // ��¼ͨѶ¼�Ѿ��������Ϣ����
//}Contact;

// ��̬�汾
typedef struct Contact
{
    PeoInfo *data; // ���Դ��1000���˵���Ϣ
    int sz;        // ��¼ͨѶ¼�Ѿ��������Ϣ����
    int capacity;  // ��ǰͨѶ¼�������
}Contact;

// ����������

// ��ʼ��ͨѶ¼
void InitContact(Contact* pc);

// ����ͨѶ¼
void DestoryContact(Contact* pc);

// �����ϵ��
void AddContact(Contact* pc);

// ��ӡͨѶ¼�е���Ϣ
void PrintContact(const Contact* pc);

// ɾ��ָ����ϵ��
void DelContact(Contact* pc);

// ����ָ����ϵ��
void SearchContact(const Contact* pc);

// �޸�ָ����ϵ�˵���Ϣ
void ModifyContact(Contact* pc);

// ������������
void SortContact(Contact* pc);



#endif//CONTACT_CONTACT_H
