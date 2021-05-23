#include <iostream>
#include <utility>
using namespace std;

enum COLOR
{
	BLACK,
	RED
};

template <class T>
struct RBTreeNode
{
	RBTreeNode<T>* _parent; //���ڵ�
	RBTreeNode<T>* _left; //����
	RBTreeNode<T>* _right; //�Һ���
	T _val; //��ֵ��
	COLOR _color; //��ɫ

	RBTreeNode(const T& val = T())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _val(val)
		, _color(RED)
	{}
};

template <class T>
class RBTree
{
public:
	typedef RBTreeNode<T> Node;

	RBTree()
		:_root(nullptr)
	{}

	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			//���ڵ�Ϊ��ɫ
			_root->_color = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		//1.Ѱ�ҵ�Ҫ����Ľ���λ��
		while (cur)
		{
			parent = cur;
			if (cur->_val == val)//keyֵ��ͬ����ʧ��
				return false;
			else if (cur->_val > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		//2.�����ڵ�
		cur = new Node(val);
		if (parent->_val > cur->_val)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//3.��ɫ���޸Ļ��߽ṹ�ĵ���
		while (cur != _root && cur->_parent->_color == RED)//��Ϊ���Ҵ���������ɫ������Ҫ����
		{
			parent = cur->_parent;
			Node* gfather = parent->_parent;

			if (gfather->_left == parent)
			{
				Node* uncle = gfather->_right;
				//���1.uncle������Ϊ��
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//����׷��
					cur = gfather;
				}
				else
				{
					if (parent->_right == cur)//���3
					{
						RotateL(parent);
						swap(cur, parent);
					}
					//���2.uncle�����ڻ���uncleΪ��
					RotateR(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
			else
			{
				Node* uncle = gfather->_left;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//����׷��
					cur = gfather;
				}
				else
				{
					if (parent->_left == cur)
					{
						RotateR(parent);
						swap(cur, parent);
					}

					RotateL(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
		}

		//���ڵ�Ϊ��ɫ
		_root->_color = BLACK;
		return true;
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
			Node* gfather = parent->_parent;
			if (gfather->_left == parent)
				gfather->_left = subR;
			else
				gfather->_right = subR;
			subR->_parent = gfather;
		}
		subR->_left = parent;
		parent->_parent = subR;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			Node* gfather = parent->_parent;
			if (gfather->_left == parent)
				gfather->_left = subL;
			else
				gfather->_right = subL;
			subL->_parent = gfather;
		}
		subL->_right = parent;
		parent->_parent = subL;
	}

	void inoder()
	{
		_inoder(_root);
		cout << endl;
	}
	void _inoder(Node* root)
	{
		if (root)
		{
			_inoder(root->_left);
			cout << root->_val << " ";
			_inoder(root->_right);
		}
	}

	bool isRBTree()
	{
		if (_root == nullptr) //����Ҳ���ں����
			return true;
		if (_root->_color == RED) //�����������������ڵ����Ϊ��ɫ
			return false;

		int bCount = 0; //ĳ��·���ϵĺ�ɫ�����
		Node* cur = _root;
		while (cur)
		{
			if (cur->_color == BLACK)
				++bCount;
			cur = cur->_left;
		}
		int pathCount = 0;
		return _isRBTree(_root, bCount, pathCount);//�����ж�ÿ��·���ϵĺ�ɫ�������Ƿ���ͬ
	}

	bool _isRBTree(Node* root, const int bCount, int pathCount)
	{
		if (root == nullptr)//·�����꣬�жϺ�ɫ������
		{
			if (pathCount == bCount)
				return true;
			else
				return false;//�������������� ÿһ��·���ϵĺ�ɫ��������ͬ
		}

		if (root->_color == BLACK)//������ɫ����++
			++pathCount;

		Node* parent = root->_parent;
		if (parent && parent->_color == RED && root->_color == RED)
			return false; //�����������ģ����ܴ���������ɫ�Ľڵ�

		return _isRBTree(root->_left, bCount, pathCount) //����������������������
			&& _isRBTree(root->_right, bCount, pathCount);
	}

private:
	Node* _root;
};

void test()
{
	RBTree<int> rbt;
	srand(time(nullptr));
	int n;
	cout << "num��" << endl;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		rbt.insert(rand());
	}
	rbt.inoder();
	cout << rbt.isRBTree() << endl;
}

int main()
{
	test();
	return 0;
}

//int main()
//{
//	RBTree<int> rbt;
//	for (int i = 10; i > 0; --i)
//	{
//		rbt.insert(i);
//	}
//	//rbt.insert(10);
//	//rbt.insert(15);
//	//rbt.insert(5);
//	//rbt.insert(2);
//	return 0;
//}