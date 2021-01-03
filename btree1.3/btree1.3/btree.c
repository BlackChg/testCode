#include"btree.h"

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
		BTreeDestory(& ( (*root)->_left) );
		BTreeDestory(& ( (*root)->_right)) ;
		free(*root);
		*root = NULL;
	}
}
void Test()
{
	char str[] = "ABD##EG##H##CF###";
	int idx = 0;
	Node* root = CreatBinaryTree(str, &idx);
	Node* node;
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	printf("%d\n", BTreeSize(root));
	node = BTreeFind(root, 'H');
}

int main()
{
	Test();

	return 0;
}