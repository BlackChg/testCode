#include <iostream>
using namespace std;

//int funtion1(int a, int b)
//{
//	return a + b;
//}
//
//int funtion2(double a, double b)
//{
//	return a + b;
//}
////int funtion(int a, int b)
////{
////	return a + b;
////}
////
////int funtion(double a, double b)
////{
////	return a + b;
////}
////
////int funtion(int a, double b)
////{
////	return a + b;
////}
//
//extern "C" int funtion(int a, int b)
//{
//	return a + b;
//}
//
//double funtion(double a, double b)
//{
//	return a + b;
//}
//
//int main()
//{
//	funtion1(1.01, 2.02);
//	funtion2(10, 1.02);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//
//	int b = 20;
//	//��b��ֵ����ra
//	ra = b; //ra = 20
//
//	return 0;
//}

//int main()
//{
//	const int a = 10;
//	//���뱨��
//	int& ra = a;
//	//����ͨ��
//	const int& ra2 = a;
//
//	return 0;
//}

//int main()
//{
//	double b = 12.34;
//	const int& c = b;
//
//	return 0;
//}


//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	cout << "a = " << a << " b = " << b << endl;
//
//	return 0;
//}

//int& funtion(int a, int b)
//{
//	static int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int& res = funtion(a, b);
//	cout << "res = " << res << endl;
//
//	return 0;
//}

//int& funtion(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int& res = funtion(a, b);
//	cout << "res = " << res << endl;
//	cout << "res = " << res << endl;
//
//
//	return 0;
//}

#include <time.h> 
//struct A
//{
//	int a[10000];
//};
//void fun1(A a) {}
//void fun2(A& a) {}

//struct A
//{
//	int a[10000]; 
//};
//A a;
//// ֵ���� 
//A* fun1() 
//{ 
//	return &a;
//} 
//// ���÷��� 
//A& fun2()
//{
//	return a;
//}
//
//int main() 
//{
//
//	int n = 0;
//	cout << "ѭ������ ��";
//	cin >> n;
//	// ��ֵ��Ϊ��������ֵ
//	int begin = clock();
//	for (int i = 0; i < n; ++i)
//		fun1();
//	int end = clock();
//	cout << "��ֵ��Ϊ����������fun1() time :" << end - begin << endl;
//
//	// ��������Ϊ��������ֵ
//	 begin = clock();
//	for (int i = 0; i < n; ++i)
//		fun2();
//	 end = clock();
//	cout << "��������Ϊ�������� ��fun2() time :" << end - begin << endl;
//
//	return 0;
//}

int main()
{
	int a = 10;
	int& ra = a;

	int b = 10;
	int* pb = &b;

	return 0;
}