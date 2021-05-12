#include <iostream>
#include <time.h>
using namespace std;

template <class K, class V>
struct BNode
{
	typedef BNode<K, V> Node;
	K _key; //
	V _value;
	Node* _left;//����
	Node* _right;//�Һ���

	BNode(const K& key, const V& value)
		:_key(key)
		,_value(value)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template <class K, class V>
class BTree
{
public:
	typedef BNode<K, V> Node;
	BTree()
		:_root(nullptr)
	{}
	Node* find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key == key)
				return cur;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				cur = cur->_right;
		}//ƽ������logN
		return cur;
	}
	//�������ظ���ֵ
	bool insert(const K& key, const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key, value);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_key == key)
				return false;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(key, value);
		if (parent->_key > key)
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
			cout << root->_key << "-->" << root->_value <<" ";
			_inorder(root->_right);
		}
	}

	//�������������������ݺͽṹ
	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* newNode = new Node(root->_key, root->_value);
		newNode->_left = copy(root->_left);
		newNode->_right = copy(root->_right);
		return newNode;
	}
	BTree(const BTree<K, V>& btree)
		:_root(copy(btree._root))
	{}

	void destroy(Node* root)
	{
		if (root)
		{
			destroy(root->_left);
			destroy(root->_right);
			cout << "destory:" << root->_key << "-->" << root->_value << endl;
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

	bool erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{

			if (cur->_key == key)
				break;

			else if (cur->_key > key)
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
			swap(cur->_key, leftRightMost->_key);
			swap(cur->_value, leftRightMost->_value);

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

void test()
{
	BTree<int, int> b;
	b.insert(5, 50);
	b.insert(3, 30);
	b.insert(7, 70);
	b.insert(1, 10);
	b.insert(4, 40);
	b.insert(6, 60);
	b.insert(8, 80);
	b.insert(0, 100);
	b.insert(2, 50);
	b.insert(9, 90);
	b.inorder();
	b.erase(5);
	b.inorder();

}

int main()
{
	test();
	return 0;
}