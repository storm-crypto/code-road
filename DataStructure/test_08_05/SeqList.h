//
// Created by ��� on 2022-08-05.
//

#ifndef TEST_08_05_SEQLIST_H
#define TEST_08_05_SEQLIST_H

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

// β��
void SeqListPushBack(SeqList seq, SeqDataType x);

// ͷ��
void SeqListPushFront(SeqList seq, SeqDataType x);

// βɾ
void SeqListPopBack(SeqList seq);

// ͷɾ
void SeqListPopFront(SeqList seq);




#endif//TEST_08_05_SEQLIST_H
