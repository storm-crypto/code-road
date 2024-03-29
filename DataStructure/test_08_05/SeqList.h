//
// Created by 旭哥 on 2022-08-05.
//

#ifndef TEST_08_05_SEQLIST_H
#define TEST_08_05_SEQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 静态的顺序表
//#define N 100
//struct SeqList
//{
//    int a[N];
//    int size;
//};

// 动态顺序表
typedef int SeqDataType;

typedef struct SeqList
{
    SeqDataType* a;
    int capacity; // 容量空间
    int size;     // 有效数据的个数
}SeqList, SEQ;

// 内存中管理数据的结构增删查改的接口

// 初始化
void SeqListInit(SeqList* pq);

// 销毁
void SeqListDestory(SeqList* pq);

// 尾插
void SeqListPushBack(SeqList* pq, SeqDataType x);

// 头插
void SeqListPushFront(SeqList* pq, SeqDataType x);

// 尾删
void SeqListPopBack(SeqList* pq);

// 头删
void SeqListPopFront(SeqList* pq);

// 打印
void SeqListPrint(SeqList* pq);

// 查找,找到返回下标，没找到返回-1
int SeqListFind(SeqList* pq, SeqDataType x);

// 在中间某个位置插入数据
void SeqListInsert(SeqList* pq, int pos, SeqDataType x);

// 将pos位置的数据删掉
void SeqListErase(SeqList* pq, int pos);

// 修改
void SeqListModify(SeqList* pq, int pos, SeqDataType x);


#endif//TEST_08_05_SEQLIST_H
