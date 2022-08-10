//
// Created by 旭哥 on 2022-08-10.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

typedef int HPDataType;
typedef struct Heap
{
    HPDataType* a;
    int size;
    int capacity;
}HP;

void Swap(int* p1, int* p2);
void AdjustDown(int* a, int n, int parent);

// HP* HeapInit(HPDataType* a, int n);
void HeapInit(HP* php ,HPDataType* a, int n);
void HeapDestroy(HP* php);
// 插入一个元素
void HeapPush(HP* php, HPDataType x);
// 删除堆顶元素
void HeadPop(HP* php);
HPDataType HeapTop(HP* php);
int HeapSize(HP* php);
bool HeapEmpty(HP* php);

#endif//HEAP_HEAP_H
