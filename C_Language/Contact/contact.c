//
// Created by 旭哥 on 2022-07-27.
//

#include "contact.h"


// 初始化通讯录
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
        printf("通讯录已满，无法添加\n");
        return;
    }

    // 录入信息
    printf("请输入名字:>");
    scanf("%s", pc->data[pc->sz].name);
    printf("请输入年龄:>");
    scanf("%d", &(pc->data[pc->sz].age));
    printf("请输入性别:>");
    scanf("%s", pc->data[pc->sz].sex);
    printf("请输入电话:>");
    scanf("%s", pc->data[pc->sz].tele);
    printf("请输入地址:>");
    scanf("%s", pc->data[pc->sz].addr);

    pc->sz++;
    printf("添加成功\n");
}

// 打印通讯录信息
void PrintContact(const Contact* pc)
{
    assert(pc);
    int i = 0;
    printf("%-20s %-5s %-5s %-12s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
    for (i = 0; i < pc->sz; i++)
    {
        printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);

    }
}

// 找到返回下标
// 找不到返回-1
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

// 删除指定联系人
void DelContact(Contact* pc)
{
    assert(pc);

    if (pc->sz == 0)
    {
        printf("通讯录已空, 无法删除\n");
        return;
    }

    // 删除
    // 1.找到
    char name[NAME_MAX] = {0};
    printf("请输入要删除人的名字:>");
    scanf("%s", name);

    // 2. 找到名字然后再删除
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("要删除的人不存在\n");
    }

    int j = 0;
    for (j = pos; j < pc->sz-1; j++)
    {
        pc->data[j] = pc->data[j + 1];
    }

    pc->sz--;
    printf("删除成功\n");
}

// 查找指定联系人
void SearchContact(const Contact* pc)
{
    char name[NAME_MAX] = {0};
    printf("请输入要查找人的名字:>");
    scanf("%s", name);

    // 2. 找到名字然后再删除
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("要查找的人不存在\n");
    }

    printf("%-20s %-5s %-5s %-12s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
    printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tele, pc->data[pos].addr);

}