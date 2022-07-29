//
// Created by 旭哥 on 2022-07-27.
//

#include "contact.h"


// 初始化通讯录
// 静态版本
//void InitContact(Contact* pc)
//{
//    assert(pc);
//    pc->sz = 0;
//    memset(pc->data, 0, sizeof (pc->data));
//}

// 动态版本
//void InitContact(Contact* pc)
//{
//    assert(pc);
//    pc->sz = 0;
//    pc->capacity = DEFAULT_SZ;
//    pc->data = (PeoInfo*)malloc(pc->capacity * sizeof (PeoInfo));
//    if (pc->data == NULL)
//    {
//        perror("InitContact::malloc");
//        return;
//    }
//    memset(pc->data, 0, pc->capacity * sizeof (PeoInfo));
//}

void CheckCapacity(Contact* pc)
{
    // 动态版本增容的代码
    if (pc->sz == pc->capacity)
    {
        // realloc成功后才将tmp赋值给pc->data
        PeoInfo* tmp = (PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof (PeoInfo));
        if (tmp != NULL)
        {
            pc->data = tmp;
        }
        pc->capacity += 2;
        printf("增容成功\n");
    }
}

// 加载文件
void LoadContact(Contact* pc)
{
    // 打开文件
    FILE* pf = fopen("contact.dat", "rb");
    if (pf == NULL)
    {
        perror("LoadContact::fopen");
    }
    // 读文件
    PeoInfo  tmp = {0};
    while (fread(&tmp, sizeof (PeoInfo), 1, pf))
    {
        CheckCapacity(pc);
        pc->data[pc->sz] = tmp;
        pc->sz++;
    }
    // 关闭文件
    fclose(pf);
    pf = NULL;
}

// 初始化通讯录文件版本
void InitContact(Contact* pc)
{
    assert(pc);
    pc->sz = 0;
    pc->capacity = DEFAULT_SZ;
    pc->data = (PeoInfo*)malloc(pc->capacity * sizeof (PeoInfo));
    if (pc->data == NULL)
    {
        perror("InitContact::malloc");
        return;
    }
    memset(pc->data, 0, pc->capacity * sizeof (PeoInfo));

    // 加载文件信息到通讯录
    LoadContact(pc);
}




void AddContact(Contact* pc)
{
    assert(pc);
    // 静态版本
//    if (pc->sz == MAX)
//    {
//        printf("通讯录已满，无法添加\n");
//        return;
//    }

    CheckCapacity(pc);

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

// 销毁通讯录
void DestoryContact(Contact* pc)
{
    free(pc->data);
    pc->data = NULL;
    pc->capacity = 0;
    pc->sz = 0;
    printf("销毁成功\n");
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

// 修改指定联系人的信息
void ModifyContact(Contact* pc)
{
    assert(pc);

    if (pc->sz == 0)
    {
        printf("通讯录已空, 无法修改信息\n");
        return;
    }

    // 修改
    char name[NAME_MAX] = {0};
    printf("请输入要查找人的名字:>");
    scanf("%s", name);

    // 先查找信息
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("要修改的条目不存在\n");
        return;
    }
    // 询问要修改什么
    printf("请输入要修改什么信息(1-姓名 2-年龄 3-性别 4-电话 5-住址:>)");
    int msg;
    scanf("%d", &msg);
    switch (msg)
    {
        case 1:
            printf("请输入新的姓名:>");
            scanf("%s", pc->data[pos].name);
            break;
        case 2:
            printf("请输入新的年龄:>");
            scanf("%d", &pc->data[pos].age);
            break;
        case 3:
            printf("请输入新的性别:>");
            scanf("%s", pc->data[pos].sex);
            break;
        case 4:
            printf("请输入新的电话:>");
            scanf("%s", pc->data[pos].tele);
            break;
        case 5:
            printf("请输入新的住址:>");
            scanf("%s", pc->data[pos].addr);
            break;
        default:
            printf("输入信息有误,修改失败\n");
            break;
    }
    printf("修改成功\n");
}

// 按照名字排序
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

// 将信息保存到文件中
void SaveContact(const Contact* pc)
{
    // 打开文件
    FILE* pf = fopen("contact.dat", "wb");
    if (pf == NULL)
    {
        perror("SaveContact::fopen");
        return;
    }

    // 写文件
    int i = 0;
    for (i = 0; i < pc->sz; i++)
    {
        fwrite(pc->data+i, sizeof(PeoInfo), 1, pf);
    }

    // 关闭文件
    fclose(pf);
    pf = NULL;
}