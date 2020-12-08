#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int LDataType;

typedef struct listNode
{
	LDataType data;
	struct listNode* next;
}listNode;

typedef struct list
{
	struct listNode* head;
}list;

//�����ڵ�
struct listNode* creatListNode(LDataType val);

//��ʼ������
void listInit(struct list* lst);

//β��
void listPushBack(struct list* lst, LDataType val);

//βɾ
void listPopBack(struct list* lst);

//ǰ��
void listPushFront(struct list* lst, LDataType val);

//ǰɾ
void listPopFront(struct list* lst);

//�ڵ�ǰ�ڵ��дһ������
void listInsertAfter(struct listNode* node, LDataType val);

//ɾ����ǰ�ڵ����һ��
void listEraseAfter(struct listNode* node);

//���ҽڵ�
listNode* listFind(struct list* lst, LDataType val);

//�ݻ�����
void listDestroy(struct list* lst);

//ɾ����ǰ�ڵ�
void listErase(struct listNode* node);