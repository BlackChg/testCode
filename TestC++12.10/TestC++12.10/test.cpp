#include<iostream>
using namespace std;

//int main()
//{
//	//Ȩ����С�ͷŴ�������������ú�ָ��֮��
//	//Ȩ�޷Ŵ� ���ܰ�const����const
//	const int a = 10;
//	//int& b = a;
//
//	//Ȩ����С ��const���Ը�const��Ҳ���Ը�const
//	int c = 20;
//	int& d = c;
//	const int& e = c;
//
//	const int*cp = &a;
//	//int* p = cp; Ȩ�޷Ŵ� ����
//
//	int* p2 = &c;
//	const int* cp2 = p2;//���ԣ�Ȩ����С
//
//	const int x = 10;
//	int y = x;
//	
//}

//1������������
//void swap_cpp(int& n1, int& n2)
//{
//	int temp = n1;
//	n1 = n2;
//	n2 = temp;
//}
//
//int main()
//{
//
//	int a = 0, b = 1;
//	swap_cpp(a, b);
//
//}

//2������������ֵ


//int Count1()
//{
//	static int n = 0;
//		n++;
//	// ...
//	return n;
//}
//
//int& Count2()
//{
//	static int n = 0;
//	n++;
//	// ...
//	return n;
//}
//
//int main()
//{
//	//const int& num1 = Count1();
//	int& num2 = Count2();
//
//	int num = Count1();
//
//	return 0;
//}

//����ȫ
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	//����Addֱ�ӳ�Ϊret�ı��� 
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}

//int& Add(int a, int b)
//{
//	static int c = a + b; //�˳�ʼ��ִֻ��һ��
//	return c;
//}
//int main()
//{
//	//����Addֱ�ӳ�Ϊret�ı��� 
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}
//�ܽ�:һ������Ҫʹ�����÷��أ����ر���������������������򻹴���
//�Ϳ���ʹ�����÷��أ����򲻰�ȫ��
//����ʹ�����÷��غô����ٴ�������һ����ʱ�������Ч��

//���Ч��--��ֵ
/*
#include <time.h>

struct A {
	int a[10000];
};
void TestFunc1(A a) 
{
}
void TestFunc2(A& a) 
{
}
void main()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc1(a);
	size_t end1 = clock();

	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc2(a);
	size_t end2 = clock();

	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;//��
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;//��
}
*/

//���Ч��--����ֵ
//#include <time.h>
//struct A {
//	int a[10000]; 
//};
//A a;
//// ֵ����
//A TestFunc1()
//{
//	return a;
//}
//// ���÷���
//A& TestFunc2() 
//{ 
//	return a; 
//}
//void main()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	// �������������������֮���ʱ��
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	int a = 10;
//	auto b = a;//b�������Ǹ���a�������Ƶ���int
//	int& c = b;
//	const char& d = c;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name()<< endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	//���ݵ�ֵ��2�ٴ�ӡһ��
//	//C++11
//	for (auto& e : arr)
//	{
//		e *= 2;
//	}
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//
//
//	return 0;
//}

//int main()
//{
//	//C
//	int* p1 = NULL;
//
//	//C++�У��Ƽ�������
//	int* p2 = nullptr;
//}


//��
//class Person
//{
//	void Print()
//	{
//
//	}
//
//	char _name[10];
//	int _age;
//
//};

class Student
{
public:
	void ShowInfo()
	{
		cout << _name << endl;
		cout << _age << endl;
		cout << _stuid << endl;

	}

private:	//һ������³�Ա�������ǱȽ���˽�ģ��������˽�еĻ��߱�����
	char _name[20];
	int _age;
	int _stuid;
};

int main()
{
	Student s1;
	Student s2;

	s1.ShowInfo();

	return 0;
}