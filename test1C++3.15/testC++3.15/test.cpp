#include<iostream>
using namespace std;

//template <typename T>
//void Swap(T& left, T& right)
//{
//	T tmp = left;
//	left = right;
//	right = tmp;
//}
//
//void Swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//
//void Swap(double& left, double& right)
//{
//	double tmp = left;
//	left = right;
//	right = tmp;
//}
//void Swap(char& left, char& right)
//{
//	char tmp = left;
//	left = right;
//	right = tmp;
//}

//template<typename T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//
//void test()
//{
//	int a = 1;
//	double b = 1.1;
//
//	//1����ʾʵ���� (���߱�������������Ϊint��Add����)
//	Add<int>(a, b);
//	//2��ǿתΪint����ʱ��������һ��
//	Add(a, (int)b);
//}

//template <typename T1, typename T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//int Add(int left, int right)
//{
//	return left + right;
//}
//void test()
//{
//	int a = 1;
//	int b = 2;
//	double c = 2.2;
//	Add<int, double>(a, b);
//
//}

template <class T>
class seqList
{
public:
	seqList(int n)
		:_data(new T[n])
		, _size(0)
		, _capacity(n)
	{}

	T seqListAt(size_t pos);
private:
	T* _data;
	size_t _size;
	size_t _capacity;
};

template <class T>
T seqList<T>::seqListAt(size_t pos)
{
	return _data[pos];
}
void test()
{
	//��ģ��ʵ����������<����> ������(����)
	seqList<int> sq1(2);
	seqList<double> sq2(4);
	seqList<char> sq3(6);
}

int main()
{
	test();
	return 0;
}