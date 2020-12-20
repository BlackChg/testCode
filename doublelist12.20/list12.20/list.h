#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

// �������������ͷ���. 
ListNode* ListCreate();
//����һ���������ݵĽ��
ListNode* BuyListNode(LTDataType x);
// ˫���������� 
void ListDestory(ListNode* phead);
// ˫�������ӡ 
void ListPrint(ListNode* phead);
// ˫������β�� 
void ListPushBack(ListNode* phead, LTDataType x);
// ˫������βɾ
void ListPopBack(ListNode* phead);
// ˫������ͷ��
void ListPushFront(ListNode* phead, LTDataType x);
// ˫������ͷɾ 
void ListPopFront(ListNode* phead);
// ˫��������� 
ListNode* ListFind(ListNode* phead, LTDataType x);
// ˫��������pos��ǰ����в��� 
void ListInsert(ListNode* pos, LTDataType x);
// ˫������ɾ��posλ�õĽڵ� 
void ListErase(ListNode* pos);