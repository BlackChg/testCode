#pragma once

#define N 100

typedef int SLDataType;

//��̬˳���
struct seqList1
{
	SLDataType data[N];
	int size;
};

//��̬����
typedef struct seqList
{
	SLDataType* data;
	int size;
	int capacity;
}seqList;

void initseqList(seqList* sl);

//���� ��ɾ�Ĳ�
//β�壺��˳������һ����Ч���ݵ�ĩβ�����µ�����
void seqListpushBack(seqList* sl, SLDataType val);

//βɾ��ɾ�����һ������
void seqListpopBack(seqList* sl);

//���ҵ�ǰ�±��Ԫ��
SLDataType seqListAt(seqList* sl, int pop);

//�жϱ��Ƿ�Ϊ��
int seqListEmpty(seqList* sl);

//��ӡ��
void seqListPrint(seqList* sl);

//�鿴�����Ч����
int seqListSize(seqList* sl);

//�������
void seqListCheckCapacity(seqList* sl);