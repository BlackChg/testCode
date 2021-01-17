#include "btree.h"
#include "queue.h"

//������������������Ϊָ���Ŀ�����ú����ڵ��õݹ�ʱ�����ĸı���ȫ�����ã�
Node* CreatBinaryTree(DataType arr[], int* idx)
{
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;	//�ս��
	}
	//��ǰ���ĸ��ڵ�
	Node* root = (Node*)malloc(sizeof(Node));
	if (root != NULL)
	{
		root->_data = arr[*idx];
	}
	else
		return NULL;
	(*idx)++;

	root->_left = CreatBinaryTree(arr, idx);
	root->_right = CreatBinaryTree(arr, idx);

	return root;
}

void PreOrder(Node* root)
{
	if (root != NULL)
	{
		//��
		printf("%c ", root->_data);
		//������
		PreOrder(root->_left);
		//������
		PreOrder(root->_right);
	}
}

void InOrder(Node* root)
{
	if (root != NULL)
	{
		//������
		InOrder(root->_left);
		//��
		printf("%c ", root->_data);
		//������
		InOrder(root->_right);
	}
}

void PostOrder(Node* root)
{
	if (root != NULL)
	{
		//������
		PostOrder(root->_left);
		//������
		PostOrder(root->_right);
		//��
		printf("%c ", root->_data);
	}
}

int BTreeSize(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BTreeSize(root->_left)  //����������� + �����������+ ��ǰ�ڵ�
		+ BTreeSize(root->_right) + 1;
}

int BTreeHigh(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = BTreeHigh(root->_left);
	int right = BTreeHigh(root->_right);

	//���ظý������Һ��ӵĶȵ����ֵ
	return left > right ? left + 1 : right + 1;
}

int BTreeLeafSize(Node* root)
{
	//����
	if (root == NULL)
	{
		return 0;
	}
	//Ҷ�ӽ��
	if (root->_left == NULL
		&& root->_right == NULL)
	{
		return 1;
	}
	//��Ҷ�ӽ��
	return BTreeLeafSize(root->_left)
		+ BTreeLeafSize(root->_right);
}

int BTreeKSize(Node* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}

	return BTreeKSize(root->_left, k - 1)
		+ BTreeKSize(root->_right, k - 1);
}

Node* BTreeFind(Node* root, DataType val)
{
	if (root != NULL)
	{
		if (root->_data == val)
		{
			return root;
		}
		Node* node = BTreeFind(root->_left, val);
		if (node)
		{
			return node;
		}
		else
			return BTreeFind(root->_right, val);
	}
	else
	{
		return NULL;
	}
}

void BTreeDestory(Node** root)
{
	if (*root == NULL)
	{
		return;
	}
	else
	{
		BTreeDestory(&((*root)->_left));
		BTreeDestory(&((*root)->_right));
		free(*root);
		*root = NULL;
	}
}

void BinaryTreeLevelOrder(Node* root)
{
	//����
	Queue q;
	QueueInit(&q);

	//�����ڵ������
	if (root)
		QueuePush(&q, root);
	//ֻҪ���в�Ϊ�վͼ���ѭ��
	while (!QueueEmpty(&q))
	{
		//��ȡ��ͷԪ��
		Node* front = QueueFront(&q);
		//����
		QueuePop(&q);
		printf("%c ", front->_data);
		//���ӷǿգ����
		if (front->_left)
			QueuePush(&q, front->_left);
		//�Һ��ӷǿգ����
		if (front->_right)
			QueuePush(&q, front->_right);
	}
}

int BinaryTreeComplete(Node* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		Node* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
		{ //�����ս�㣬������һ��ѭ��������ڶ���ѭ��ȥ�жϺ����Ƿ�ȫΪ�ս��
			break;
		}
	}

	while (!QueueEmpty(&q))
	{
		Node* front = QueueFront(&q);
		QueuePop(&q);
		//�н�㲻Ϊ�գ�������ȫ������
		if (front)
			return 0;
	}

	return 1;
}

void Test()
{
	char str[] = "ABD##EG##H##CF###";
	int idx = 0;
	Node* root = CreatBinaryTree(str, &idx);
	BinaryTreeLevelOrder(root);
	int res = BinaryTreeComplete(root);
	printf("\n");
	//printf("%d\n", res);
}

int main()
{
	Test();

	return 0;
}