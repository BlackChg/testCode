#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef char DataType;

typedef struct BNode
{
	DataType _data;
	struct BNode* _left;
	struct BNode* _right;
}Node;

//����������
Node* CreatBinaryTree(DataType arr[], int* idx);

//�������
void PreOrder(Node* root);

//�������
void InOrder(Node* root);

//�������
void PostOrder(Node* root);

//����������ĸ���
int BTreeSize(Node* root);

//��������ĸ߶�
int BTreeHigh(Node* root);

//Ҷ�ӽ��
int BTreeLeafSize(Node* root);

//��k��Ľ��
int BTreeKSize(Node* root, int k);

//���Ҷ������еĽ��
Node* BTreeFind(Node* root, DataType val);

//���ٶ�����
void BTreeDestory(Node** root);