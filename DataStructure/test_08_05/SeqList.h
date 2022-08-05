//
// Created by ��� on 2022-08-05.
//

#ifndef TEST_08_05_SEQLIST_H
#define TEST_08_05_SEQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// ��̬��˳���
//#define N 100
//struct SeqList
//{
//    int a[N];
//    int size;
//};

// ��̬˳���
typedef int SeqDataType;

typedef struct SeqList
{
    SeqDataType* a;
    int capacity; // �����ռ�
    int size;     // ��Ч���ݵĸ���
}SeqList, SEQ;

// �ڴ��й������ݵĽṹ��ɾ��ĵĽӿ�

// ��ʼ��
void SeqListInit(SeqList* pq);

// ����
void SeqListDestory(SeqList* pq);

// β��
void SeqListPushBack(SeqList* pq, SeqDataType x);

// ͷ��
void SeqListPushFront(SeqList* pq, SeqDataType x);

// βɾ
void SeqListPopBack(SeqList* pq);

// ͷɾ
void SeqListPopFront(SeqList* pq);

// ��ӡ
void SeqListPrint(SeqList* pq);




#endif//TEST_08_05_SEQLIST_H
