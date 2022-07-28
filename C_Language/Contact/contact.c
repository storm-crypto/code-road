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

// �ҵ������±�
// �Ҳ�������-1
int FindByName(const Contact* pc, char name[])
{
    assert(pc);
    int i = 0;
    for (i = 0; i < pc->sz; i++)
    {
        if (0 == strcmp(pc->data[i].name, name))
        {
            return i;
        }
    }

    return -1;
}

// ɾ��ָ����ϵ��
void DelContact(Contact* pc)
{
    assert(pc);

    if (pc->sz == 0)
    {
        printf("ͨѶ¼�ѿ�, �޷�ɾ��\n");
        return;
    }

    // ɾ��
    // 1.�ҵ�
    char name[NAME_MAX] = {0};
    printf("������Ҫɾ���˵�����:>");
    scanf("%s", name);

    // 2. �ҵ�����Ȼ����ɾ��
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("Ҫɾ�����˲�����\n");
    }

    int j = 0;
    for (j = pos; j < pc->sz-1; j++)
    {
        pc->data[j] = pc->data[j + 1];
    }

    pc->sz--;
    printf("ɾ���ɹ�\n");
}

// ����ָ����ϵ��
void SearchContact(const Contact* pc)
{
    char name[NAME_MAX] = {0};
    printf("������Ҫ�����˵�����:>");
    scanf("%s", name);

    // 2. �ҵ�����Ȼ����ɾ��
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("Ҫ���ҵ��˲�����\n");
    }

    printf("%-20s %-5s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
    printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tele, pc->data[pos].addr);

}

// �޸�ָ����ϵ�˵���Ϣ
void ModifyContact(Contact* pc)
{
    assert(pc);

    if (pc->sz == 0)
    {
        printf("ͨѶ¼�ѿ�, �޷��޸���Ϣ\n");
        return;
    }

    // �޸�
    char name[NAME_MAX] = {0};
    printf("������Ҫ�����˵�����:>");
    scanf("%s", name);

    // �Ȳ�����Ϣ
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("Ҫ�޸ĵ���Ŀ������\n");
        return;
    }
    // ѯ��Ҫ�޸�ʲô
    printf("������Ҫ�޸�ʲô��Ϣ(1-���� 2-���� 3-�Ա� 4-�绰 5-סַ:>)");
    int msg;
    scanf("%d", &msg);
    switch (msg)
    {
        case 1:
            printf("�������µ�����:>");
            scanf("%s", pc->data[pos].name);
            break;
        case 2:
            printf("�������µ�����:>");
            scanf("%d", &pc->data[pos].age);
            break;
        case 3:
            printf("�������µ��Ա�:>");
            scanf("%s", pc->data[pos].sex);
            break;
        case 4:
            printf("�������µĵ绰:>");
            scanf("%s", pc->data[pos].tele);
            break;
        case 5:
            printf("�������µ�סַ:>");
            scanf("%s", pc->data[pos].addr);
            break;
        default:
            printf("������Ϣ����,�޸�ʧ��\n");
            break;
    }
    printf("�޸ĳɹ�\n");
}

// ������������
void SortContact(Contact* pc)
{
    int i = 0;
    int j = 0;
    PeoInfo tmp;

    for(i = 0; i < pc->sz - 1; i++)
    {
        for (j = 0; j < pc->sz - i - 1; j++)
        {
            if (0 < strcmp(pc->data[j].name, pc->data[j + 1].name))
            {
                tmp = pc->data[j];
                pc->data[j] = pc->data[j + 1];
                pc->data[j + 1] = tmp;

            }
        }
    }
}