#include <iostream>
#include "test.h"
using namespace std;

//inline int fun(int a, int b)
//{
//	return a * b;
//}
//
//int main()
//{
//	fun(10, 20);
//
//	return 0;
//}

//int main()
//{
//	auto a = 1;
//	auto b = 2.0;
//	auto c = 'a';
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	return 0;
//}

//void fun(auto a) {}

//void fun(int arr[], int n)
//{
//	for (const auto& num : arr)
//	{
//		cout << " " << num;
//	}
//}

//int main()
//{
//	//auto a = 1;
//	////ͨ���Ա���ȡ��ַ�Ƶ���ָ��
//	//auto pa = &a;
//	////��ȷpa2Ϊָ�����ͣ��������÷����һ��
//	//auto* pa2 = &a;
//
//	////�����Ƶ��������ã�ֻ���Ƶ�����aͬ���͵�����
//	//auto ra = a;
//	//ra = 2;
//	//cout << a << endl;
//	////��ȷra2��һ�����ã���a������ͬ������
//	//auto& ra2 = a;
//	//ra2 = 3;
//	//cout << a << endl;
//	//cout << typeid(a).name() << endl;
//	//cout << typeid(pa).name() << endl;
//	//cout << typeid(pa2).name() << endl;
//
//
//	//auto a = 1, b = 2, c = 3.0;
//
//	//auto arr[] = { 0, 1, 2, 3};
//
//	/*int arr[] = { 0, 1, 2, 3 , 4, 5, 6, 7, 8, 9, 10 };
//
//	int n = sizeof(arr) / sizeof(int);
//
//	for (int i = 0; i < n; ++i)
//	{
//		cout << " " << arr[i];
//	}
//	cout << endl;
//	for (int num : arr)
//	{
//		cout << " " << num;
//	}
//	cout << endl;
//	for (const auto& num : arr)
//	{
//		cout << " " << num;
//	}*/
//
//	int* pa = 0;
//	int* pb = NULL;
//	int* pc = nullptr;
//	return 0;
//}

void fun(int a)
{
	cout << "fun(int)"<< endl;
}

void fun(int* a)
{
	cout << "fun(int*)" << endl;
}

int main()
{

	fun(0);
	fun(NULL);
	fun(nullptr);

	return 0;
}