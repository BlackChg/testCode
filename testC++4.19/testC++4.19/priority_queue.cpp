#include <iostream>
#include <queue>
using namespace std;

//�ô���С���ȼ�����
template<class T>
struct Less
{
	bool operator()(const T& a, const T& b)
	{
		return a < b;
	}
};

//������С���ȼ�����
template<class T>
struct Greater
{
	bool operator()(const T& a, const T& b)
	{
		return a > b;
	}
};

template<class T, class Container = vector<T>, class Compare = Less<T>>
class PriorityQueue
{
public:
	//���µ���
	void shiftDown()
	{
		int parent = 0;
		int child = 2 * parent + 1;
		while (child < con.size())
		{
			if (child + 1 < con.size() && cmp(con[child], con[child + 1]))
			{
				++child;
			}
			if (cmp(con[parent], con[child]))
			{
				swap(con[parent], con[child]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
			{
				break;
			}
		}
	}

	//���ϵ���
	void shiftUp(int child)
	{
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (cmp(con[parent], con[child]))
			{
				swap(con[parent], con[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

	void push(const T& val)
	{
		//β��
		con.push_back(val);
		shiftUp(con.size() - 1);
	}

	void pop()
	{
		//����
		swap(con[0], con[con.size() - 1]);
		con.pop_back();
		shiftDown();
	}

	T& top()
	{
		return con.front();
	}

	size_t size() const
	{
		return con.size();
	}

	bool empty() const
	{
		return con.empty();
	}
private:
	Container con;
	Compare cmp;
};

////�º�����
//template<class T>
//struct Greater
//{
//	//�º���
//	bool operator()(const T& a, const T& b)
//	{
//		return a > b;
//	}
//};

//void test()
//{
//	Greater<int> g;
//	//ԭ��
//	bool ret = g.operator()(13, 14);
//	cout << ret << endl;
//	//��д��ʽ-ʹ�÷����ͺ�������
//	ret = g(13, 14);
//	cout << ret << endl;
//}

void test()
{
	//Ĭ����Less
	PriorityQueue<int, deque<int>> pq;
	pq.push(123);
	pq.push(14);
	pq.push(13);
	pq.push(23);
	pq.push(88);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}



//class A
//{
//public:
//	A(int a = 1)
//		:_a(a)
//	{}
//
//	//֧�ֱȽϺ���
//	bool operator<(const A& a) const
//	{
//		return _a < a._a;
//	}
//	bool operator>(const A& a) const
//	{
//		return _a > a._a;
//	}
//	int _a;
//};
//
//void test()
//{
//	priority_queue<A> pq;
//	pq.push(A(123));
//	pq.push(A(14));
//	pq.push(A(13));
//	pq.push(A(23));
//	pq.push(A(88));
//	while (!pq.empty())
//	{
//		cout << pq.top()._a << " ";
//		pq.pop();
//	}
//	cout << endl;
//}

//void test()
//{
//	priority_queue<int, vector<int>, greater<int>> pq;
//	pq.push(13);
//	pq.push(14);
//	pq.push(9);
//	pq.push(23);
//	pq.push(12);
//	pq.push(22);
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//}

int main()
{
	test();
	return 0;
}