#include <iostream>
#include <time.h>
using namespace std;

template <class T>
struct BNode
{
	typedef BNode<T> Node;
	T _data; //����
	Node* _left;//����
	Node* _right;//�Һ���

	BNode(const T& data)
		:_data(data)
		,_left(nullptr)
		,_right(nullptr)
	{}
};

template <class T>
class BTree
{
public:
	typedef BNode<T> Node;
	BTree()
		:_root(nullptr)
	{}
	Node* find(const T& val)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_data == val)
				return cur;
			else if (cur->_data > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}//ƽ������logN
	}
	//�������ظ���ֵ
	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data == val)
				return false;
			else if (cur->_data > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(val);
		if (parent->_data > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		return true;
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
			cout << root->_data << " ";
			_inorder(root->_right);
		}
	}

	//�������������������ݺͽṹ
	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* newNode = new Node(root->_data);
		newNode->_left = copy(root->_left);
		newNode->_right = copy(root->_right);
		return newNode;
	}
	BTree(const BTree<T>& btree)
		:_root(copy(btree._root))
	{}

	void destroy(Node* root)
	{
		if (root)
		{
			destroy(root->_left);
			destroy(root->_right);
			delete root;
		}
	}
	~BTree()
	{
		if (_root)
		{
			destroy(_root);
			_root = nullptr;
		}
	}

	bool erase(const T& data)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			
			if (cur->_data == data)
				break;
			
			else if (cur->_data > data)
			{
				parent = cur;
				cur = cur->_left;
			}			
			else
			{
				parent = cur;
				cur = cur->_right;
			}
		}
		//�ж��Ƿ��ҵ�����Ҫɾ���Ľ��
		if (cur == nullptr)
			return false;//δ�ҵ�����
		//ɾ�����
		//1��ɾ���Ľ��ΪҶ�ӽ��
		if (cur->_left == nullptr && cur->_right == nullptr)
		{
			//��������Ƿ���ڵ�
			if (cur == _root)
			{
				_root = nullptr;
			}
			else
			{
				//��Ҫ�жϵ�ǰ�ڵ��λ��
				if (parent->_left == cur)
					parent->_left = nullptr;
				else
					parent->_right = nullptr;
			}
			//ɾ�����
			delete cur;
		}
		//2.����һ������
		else if (cur->_left == nullptr)//����Ϊ�գ��Һ��ӷǿ�
		{

			//��������Ƿ���ڵ�
			if (cur == _root)
			{
				_root = nullptr;
			}
			else
			{
				if (parent->_left == cur)//ɾ�����Ǹ��ڵ�����
					parent->_left = cur->_right;//���ø��ڵ�����ɾ���Ľ����Һ��ӣ�����Ϊ�գ��Һ��ӷǿգ�
				else
					parent->_right = cur->_right;//ͬ������ɾ�������Ǳߣ������ӵ����Һ���
			}
			//ɾ�����
			delete cur;
		}
		else if (cur->_right == nullptr)
		{
			//��������Ƿ���ڵ�
			if (cur == _root)
			{
				_root = nullptr;
			}
			else
			{
				if (parent->_left == cur)//ɾ�����Ǹ��ڵ�����
					parent->_left = cur->_left;//���ø��ڵ�����ɾ���Ľ������ӣ����ӷǿգ��Һ���Ϊ�գ�
				else
					parent->_right = cur->_left;//ͬ������ɾ�������Ǳߣ������ӵ�������
			}
			//ɾ�����
			delete cur;
		}
		else
		{
			//��һ�����-�������������ҽڵ�
			Node* leftRightMost = cur->_left;
			parent = cur;//��ʱ�����õ���parent��ΪleftRightMost�ĸ��ڵ�

			while (leftRightMost->_right)//�������ҽڵ�
			{
				parent = leftRightMost;
				leftRightMost = leftRightMost->_right;
			}

			//����
			swap(cur->_data, leftRightMost->_data);

			//ɾ�����ҽڵ�
			if (parent->_left == leftRightMost)
				parent->_left = leftRightMost->_left;//���ҽڵ�϶�û���Һ���
			else
				parent->_right = leftRightMost->_left;

			delete leftRightMost;
		}
		return true;
	}
private:
	Node* _root;//��
};

//void test()
//{
//	BTree<int> b;
//	srand(time(nullptr));
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; ++i)
//	{
//		b.insert(rand());
//	}
//	b.inorder();
//	cout << endl;
//	BTree<int> b1 = b;
//	b1.inorder();
//}
//
//int main()
//{
//	test();
//	return 0;
//}

int main()
{
	BTree<int> b;
	b.insert(5);
	b.insert(8);
	b.insert(3);
	b.insert(4);
	b.insert(7);
	b.insert(9);
	b.insert(1);
	b.inorder();
	b.erase(4);//ɾ��Ҷ�ӽ��
	b.inorder();
	b.erase(3);//ɾ��ֻ��������ҽ��
	b.inorder();
	b.erase(5);//��������Ҳ���Һ��ӵĽ��
	b.inorder();
	return 0;
}