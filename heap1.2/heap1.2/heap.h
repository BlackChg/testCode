#pragma once

#include<stdio.h>
#include<stdlib.h>
typedef int HDataType;

typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;

//��ʼ����
void HeapInit(heap* hp);

//�������
void CheckCapacity(heap* hp);

//С�����µ���
void SShiftDown(HDataType* arr, int n, int curPos);

//������µ���
void BShiftDown(HDataType* arr, int n, int curPos);

//����������
void Swap(int* a, int* b);

//С�����ϵ���
void SShiftUp(int* arr, int n, int cur);

//������ϵ���
void BShiftUp(int* arr, int n, int cur);

//С�Ѳ���
void SHeapPush(heap* hp, HDataType val);

//��Ѳ���
void BHeapPush(heap* hp, HDataType val);

//С��ɾ��
void SHeapPop(heap* hp);

//��� ɾ��
void BHeapPop(heap* hp);

//�п�
int HeapEmpty(heap* hp);

//��ȡ�Ѷ�Ԫ��
HDataType HeapTop(heap* hp);

//С������
void SHeapSort(heap* hp);

//�������
void BHeapSort(heap* hp);

//�ݻٶ�
void HeapDestory(heap* hp);