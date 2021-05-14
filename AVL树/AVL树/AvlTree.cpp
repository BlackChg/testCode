#include <iostream>
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
				//...
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
private:
	Node* _root = nullptr;
};

void test()
{
	AVLTreeNode<int> avl;
	avl.insert(5);
	avl.insert(3);
	//    5
	// 3
	avl.insert(1); //�ҵ���
	//    3
	// 1     5 
	avl.insert(0);
	avl.insert(2);
	avl.insert(-1);//�ҵ���
	//����ǰ
	//       3
	//    1      5
	//  0  2
	//-1
	//������
	//       1
	//    0      3
	// -1      2   5
}

int main()
{
	test();
	return 0;
}