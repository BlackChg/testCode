#include <iostream>
#include "fun.h"
using namespace std;

int main()
{
	fun(1);
	return 0;
}

//#include <iostream>
//#include <array>
//#include <string>
//using namespace std;

//void test()
//{
//	//����10��int���͵ľ�̬����
//	//������ջ������ģ��ڶ���ֵ����̫��
//	//array<class T, size_t N>
//	array<int, 2> arr;
//	int sz = arr.size();
//	cout << sz << endl;
//}

//template<class T>
//bool isEqual(T a, T b)
//{
//	return a == b;
//}
//
////�ػ�ģ��
//template<>
//bool isEqual<char*>(char* a, char* b)
//{
//	return strcmp(a, b) == 0;
//}
//
//void test()
//{
//
//	char ptr1[] = "123";
//	char ptr2[] = "123";
//	int ret = isEqual(ptr1, ptr2);
//	cout << ret << endl;
//}

//ͨ����ģ��
//template<class T1, class T2>
//class D
//{
//public:
//	D(const T1& d1, const T2& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(T1, T2)" << endl;
//	}
//	T1 _d1;
//	T2 _d2;
//};
//
////��ģ���ػ�
//template<>
//class D<int, char>
//{
//public:
//	D(const int& d1, const char& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(int, char)" << endl;
//	}
//	int _d1;
//	char _d2;
//};
//
////��ģ��ƫ�ػ�
//template<class T1>
//class D<T1, double>
//{
//public:
//	D(const T1& d1, const double& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(T1, double)" << endl;
//	}
//	T1 _d1;
//	double _d2;
//};
//
////��������
//template<class T1, class T2>
//class D<T1*, T2*>
//{
//public:
//	D(const T1& d1, const T2& d2)
//		:_d1(d1)
//		, _d2(d2)
//	{
//		cout << "D(T1*, T2*)" << endl;
//	}
//	T1 _d1;
//	T2 _d2;
//};
//
//void test()
//{
//	//����ͨ��ģ��
//	D<int, int> d1(1, 2);
//	//�����ػ�ģ��
//	D<int, char> d2(1, 'a');
//	//����ƫ�ػ�ģ��
//	D<int, double> d3(1, 2.2);
//	//����ƫ�ػ�ģ��
//	D<int*, int*> d4(1, 2);
//}

//int main()
//{
//	test();
//	return 0;
//}