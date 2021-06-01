//#include <unordered_map>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//enum STATE
//{
//	EXIST,
//	DELETE,
//	EMPTY
//};
////��ϣ������̽������ϣ��ͻ
//template<class K, class V>
//struct HashNode
//{
//	pair<K, V> _kv;//����
//	STATE _state = EMPTY;//״̬
//};
//
////˳���ʵ�ֹ�ϣ
//template<class K, class V>
//class HashTable
//{
//public:
//	typedef HashNode<K, V> Node;
//
//	HashTable(size_t n = 10)
//		:_hTable(n)
//		,_size(0)
//	{}
//
//	bool insert(const pair<K, V>& kv)
//	{
//		//0.�������
//		checkCapacity();
//
//		//1.��ǰԪ�صĹ�ϣλ��
//		int idx = kv.first % _hTable.size();
//
//		//2.�ж�key�Ƿ����
//		while (_hTable[idx]._state != EMPTY)//��ǰλ���������ݻ���Ϊɾ��λ�ã������ܴ��
//		{
//			//��ǰλ�ô���������key��ͬ�����ܲ���
//			if (_hTable[idx]._state == EXIST
//				&& _hTable[idx]._kv.first == kv.first)
//			{
//				return false;
//			}
//			//��������������λ��
//			++idx;
//			//�ߵ�ĩβ����Ҫ��ͷ��ʼ��
//			if (idx == _hTable.size())
//				idx = 0;
//		}
//
//		_hTable[idx]._kv = kv;
//		_hTable[idx]._state = EXIST;
//		++_size;
//		
//		return true;
//	}
//
//	void checkCapacity()
//	{
//		//��������[0, 1],���ﶨ��������Ϊ0.7
//		if (_hTable.size() == 0 || _size * 10 / _hTable.size() >= 7)
//		{
//			//�����±�
//			int newC = _hTable.size() == 0 ? 10 : 2 * _hTable.size();
//			HashTable<K, V> newHt(newC);
//
//			for (size_t i = 0; i < _hTable.size(); ++i)
//			{
//				//��ԭ�ȵı�����ݲ��뵽�µı��У�
//				if (_hTable[i]._state == EXIST)
//				{
//					newHt.insert(_hTable[i]._kv);
//				}
//			}
//			//���������������
//			Swap(newHt);
//		}
//	}
//
//	void Swap(HashTable<K, V>& Ht)
//	{
//		swap(_hTable, Ht._hTable);
//		swap(_size, Ht._size);
//	}
//
//	Node* find(const K& key)
//	{
//		//����λ��
//		int idx = key % _hTable.size();
//		while (_hTable[idx]._state != EMPTY)
//		{
//			//�ҵ�
//			if (_hTable[idx]._state == EXIST
//				&& key == _hTable[idx]._kv.first)
//			{
//				return &_hTable[idx];
//			}
//			++idx;
//			if (idx == _hTable.size())
//				idx = 0;
//		}
//		//��������ո����ʾû�ҵ������ؿ�
//		return nullptr;
//	}
//
//	bool erase(const K& key)
//	{
//		Node* node = find(key);
//		if (node)
//		{
//			//αɾ��
//			--_size;
//			node->_state = DELETE;
//			return true;
//		}
//		return false;
//	}
//private:
//	vector<Node> _hTable;//��
//	size_t _size;//��ЧԪ�ظ���
//};
//
//void test()
//{
//	HashTable<int, int> ht;
//	ht.insert(make_pair(1, 1));
//	ht.insert(make_pair(11, 11));
//	ht.insert(make_pair(3, 3));
//	ht.insert(make_pair(14, 14));
//	ht.insert(make_pair(4, 4));
//	ht.insert(make_pair(7, 7));
//	ht.insert(make_pair(9, 9));
//	ht.insert(make_pair(5, 5));
//
//	cout << ht.erase(11) << endl;//1
//	cout << ht.erase(21) << endl;//0
//}
//
////void test()
////{
////	unordered_map<int, int> m;
////	m.insert(make_pair(1, 1));
////	m[2] = 2;
////	for (int i = 3; i < 100; ++i)
////	{
////		m[i] = i+1;
////	}
////
////	auto it = m.begin();
////	while (it != m.end())
////	{
////		cout << it->first << " ";
////		++it;
////	}
////	cout << endl;
////}
//
//int main()
//{
//	test();
//	return 0;
//}