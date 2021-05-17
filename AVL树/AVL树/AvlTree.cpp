#include <iostream>
#include <time.h>
using namespace std;

template<class T>
struct AVLNode
{
	AVLNode<T>* _parent;
	AVLNode<T>* _left;  
	AVLNode<T>* _right;
	T _val;
	int _bf;//ƽ������

	AVLNode(const T& val = T())
		:_parent(nullptr)
		,_left(nullptr)
		,_right(nullptr)
		,_val(val)
		,_bf(0)//��ʼ��Ϊ0��Ҷ�������Һ���
	{}
};

//AVL��
template<class T>
class AVLTreeNode
{
public:
	typedef AVLNode<T> Node;

	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}

		//1.���ҵ�Ҫ�����λ��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;//��¼����ڵ�ĸ��ڵ�
			if (cur->_val == val)//������ͬ�ڵ��˳�
				return false;
			else if (cur->_val > val)//����ڵ�ȵ�ǰ�ڵ�С����Ӳ���뵱ǰ�ڵ����������
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		//2.���ӽڵ��ϵ
		cur = new Node(val);
		if (parent->_val > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//3.�޸�ƽ�����ӣ�������AVL��
		while (parent)
		{
			//���¸��ڵ��ƽ�����ӣ��ж��Ƿ�ƽ��
			if (parent->_left == cur)
				--parent->_bf;
			else
				++parent->_bf;

			if (parent->_bf == 0) //��ʾparent�������Ƚ϶̵������߶�+1����Ӱ��parent�ĸ��ڵ��ƽ�����ӣ��������
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)//��ʾparent����ǰΪ0�����º�Ϊ0�����ĸ߶��б䣬��Ӱ��parent�ĸ��ڵ�
			{
				//����׷���޸�parent���ڵ��ƽ������
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				if (parent->_bf == -2 && cur->_bf == -1)//��ߵ���߸�
				{
					//�ҵ���
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)//�ұߵ��ұ߸�
				{
					//����
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1) //��ߵ��ұ߸�
				{
					//����˫��
					Node* subLR = cur->_right;
					int bf = subLR->_bf;
					RotateL(cur);
					RotateR(parent);
					if (bf == -1)
					{
						parent->_bf = 1;
						cur->_bf = 0;
					}
					if (bf == 1)
					{
						parent->_bf = 0;
						cur->_bf = -1;
					}
				}
				else if(parent->_bf == 2 && cur->_bf == -1) //�ұߵ���߸�
				{
					//������ʱ
					Node* subRL = cur->_left;
					int bf = subRL->_bf;
					RotateR(cur);
					RotateL(parent);
					if (bf == 1)
					{
						parent->_bf = -1;
						cur->_bf = 0;
					}
					if (bf == -1)
					{
						parent->_bf = 0;
						cur->_bf = 1;
					}
				}
				break;
			}
		}
		return true;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)//�����Ϊ����Ҫ����_parent
			subLR->_parent = parent;

		if (parent == _root) //���ڵ�Ϊ�����򲻿���pparent������
		{
			//���¸��ڵ�
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
			subL->_parent = pparent;
		}

		subL->_right = parent;
		parent->_parent = subL;

		subL->_bf = parent->_bf = 0;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subR;
			else
				pparent->_right = subR;
			subR->_parent = pparent;
		}
		subR->_left = parent;
		parent->_parent = subR;

		subR->_bf = parent->_bf = 0;
	}

	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}

	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_val << " ";
			_inorder(root->_right);
		}
	}

	int height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = height(root->_left);
		int right = height(root->_right);

		return left > right ? left + 1 : right + 1;
	}

	bool _isBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		//�鿴ƽ�������Ƿ�����������ĸ߶Ȳ�һ��
		int left = height(root->_left);
		int right = height(root->_right);

		if (right - left != root->_bf || abs(root->_bf) > 1)//����Ȼ���ƽ�������������ʾ����AVL��
			return false;
		return _isBalance(root->_left) && _isBalance(root->_right);
	}

	bool isBalance()
	{
		cout << endl;
		return _isBalance(_root);
	}
private:
	Node* _root = nullptr;
};

void test()
{
	srand(time(nullptr));
	cout << "num : ";
	int num;
	cin >> num;
	AVLTreeNode<int> avl;
	for (int i = 0; i < num; ++i)
	{
		avl.insert(rand());
	}
	avl.inorder();
	cout << avl.isBalance() << endl;
}

//void test()
//{
//	AVLTreeNode<int> avl;
//	avl.insert(5);
//	avl.insert(3);
//	avl.insert(1); //�ҵ���
//	avl.insert(0);
//	avl.insert(2);
//	avl.insert(-1);//�ҵ���
//	//       1
//	//    0      3
//	// -1      2   5
//	avl.insert(10);
//	avl.insert(15); //����
//	//����ǰ
//	//       1
//	//    0      3
//	// -1      2   5
//	//               10
//	//                  15
//	//������
//	//       1
//	//    0      3
//	// -1      2    10
//	//             5  15
//	avl.insert(20);//����
//	//����ǰ
//	//       1
//	//    0      3
//	// -1      2    10
//	//            5    15
//	//                   20
//	//������
//	//       1
//	//    0      10
//	// -1      3    15
//	//       2   5     20
//	avl.inorder();
//}

//void test()
//{
//	AVLTreeNode<int> avl;
//	avl.insert(5);
//	avl.insert(3);
//	//    5
//	// 3
//	avl.insert(1); //�ҵ���
//	//    3
//	// 1     5 
//	avl.insert(0);
//	avl.insert(2);
//	avl.insert(-1);//�ҵ���
//	//����ǰ
//	//       3
//	//    1      5
//	//  0  2
//	//-1
//	//������
//	//       1
//	//    0      3
//	// -1      2   5
//}

int main()
{
	test();
	return 0;
}