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

struct SeqList
{
    SeqDataType* a;
    int capacity; // 容量空间
    int size;     // 有效数据的个数
};



#endif//TEST_08_05_SEQLIST_H
