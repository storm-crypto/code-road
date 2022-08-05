//
// Created by 旭哥 on 2022-08-05.
//

#ifndef TEST_08_05_SEQLIST_H
#define TEST_08_05_SEQLIST_H

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

// 尾插
void SeqListPushBack(SeqList seq, SeqDataType x);

// 头插
void SeqListPushFront(SeqList seq, SeqDataType x);

// 尾删
void SeqListPopBack(SeqList seq);

// 头删
void SeqListPopFront(SeqList seq);




#endif//TEST_08_05_SEQLIST_H
