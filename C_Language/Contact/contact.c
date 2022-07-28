//
// Created by 旭哥 on 2022-07-27.
//

#include "contact.h"


// 初始化通讯录
void InitContact(Contact* pc)
{
    pc->sz = 0;
    memset(pc->data, 0, sizeof (pc->data));
}

void AddContact(Contact* pc)
{
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