//
// Created by ��� on 2022-07-27.
//

#include "contact.h"


// ��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
    pc->sz = 0;
    memset(pc->data, 0, sizeof (pc->data));
}

void AddContact(Contact* pc)
{
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