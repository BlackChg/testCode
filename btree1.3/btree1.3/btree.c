#include"btree.h"

//数组名，数组索引（为指针的目的是让函数在调用递归时索引的改变起全局作用）
Node* CreatBinaryTree(DataType arr[], int* idx) 
{
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;	//空结点
	}
	//当前树的根节点
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
		//根
		printf("%c ", root->_data);
		//左子树
		PreOrder(root->_left);
		//右子树
		PreOrder(root->_right);
	}
}

void InOrder(Node* root)
{
	if (root != NULL)
	{
		//左子树
		InOrder(root->_left);
		//根
		printf("%c ", root->_data);
		//右子树
		InOrder(root->_right);
	}
}

void PostOrder(Node* root)
{
	if (root != NULL)
	{
		//左子树
		PostOrder(root->_left);
		//右子树
		PostOrder(root->_right);
		//根
		printf("%c ", root->_data);
	}
}

int BTreeSize(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BTreeSize(root->_left)  //左子树结点数 + 右子树结点数+ 当前节点
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

	//返回该结点的左右孩子的度的最大值
	return left > right ? left + 1 : right + 1;
}

int BTreeLeafSize(Node* root)
{
	//空树
	if (root == NULL)
	{
		return 0;
	}
	//叶子结点
	if (root->_left == NULL 
			&& root->_right == NULL)
	{
		return 1;
	}
	//非叶子结点
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