//
// Created by ��� on 2022-07-27.
//

#include "contact.h"


// ��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
    assert(pc);
    pc->sz = 0;
    memset(pc->data, 0, sizeof (pc->data));
}

void AddContact(Contact* pc)
{
    assert(pc);
    if (pc->sz == MAX)
    {
        printf("ͨѶ¼�������޷����\n");
        return;
    }

    // ¼����Ϣ
    printf("����������:>");
    scanf("%s", pc->data[pc->sz].name);
    printf("����������:>");
    scanf("%d", &(pc->data[pc->sz].age));
    printf("�������Ա�:>");
    scanf("%s", pc->data[pc->sz].sex);
    printf("������绰:>");
    scanf("%s", pc->data[pc->sz].tele);
    printf("�������ַ:>");
    scanf("%s", pc->data[pc->sz].addr);

    pc->sz++;
    printf("��ӳɹ�\n");
}

// ��ӡͨѶ¼��Ϣ
void PrintContact(const Contact* pc)
{
    assert(pc);
    int i = 0;
    printf("%-20s %-5s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
    for (i = 0; i < pc->sz; i++)
    {
        printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);

    }
}