#include<iostream>

using namespace std;

//int main()
//{
//	int num1 = 10;
//	int& num2 = num1;
//
//	cout << "num1 = " << num1 << endl;
//	cout << "num2 = " << num2 << endl;
//	printf("num1��ַ = %p\n",&num1);
//	printf("num2��ַ = %p\n", &num2);
//
//	return 0;
//}

//int main()
//{
//	int num1 = 10;
//	//int num1; ���뱨��
//	int& num2 = num1;
//	int & num3 = num1;
//	int& num4 = num3;
//
//	printf("num1��ַ = %p\n", &num1);
//	printf("num2��ַ = %p\n", &num2);
//	printf("num3��ַ = %p\n", &num3);
//	printf("num4��ַ = %p\n", &num4);
//
//	return 0;
//}

//int main()
//{
//
//	const int num1 = 10;
//	int& num2 = num1; //�������
//	const int& num3 = num1;//ok
//
//	int num4 = 20;
//	const double num5 = num4; //Ϊʲô������Ա���ͨ���أ�����
//
//	return 0;
//}

//void Swap(int& num1, int& num2)
//{
//	int tmp = num1;
//	num1 = num2;
//	num2 = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	cout << "a = " << a << " b = " << b << endl;
//	Swap(a, b);
//	cout << "a = " << a << " b = " << b << endl;
//
//	return 0;
//}

//int& Count()
//{
//	static int n = 0;
//		n++;
//	return n;
//}
//
//int main()
//{
//	int num1 = Count();
//
//	return 0;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}

//#include <time.h>
//struct A 
//{ 
//	int a[10000]; 
//};
//void TestFunc1(A a) 
//{}
//void TestFunc2(A& a) 
//{}
//void main()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}

//#include <time.h>
//struct A { 
//	int a[10000];
//};
//A a;
//// ֵ����
//A TestFunc1() { return a; }
//// ���÷���
//A& TestFunc2() { return a; }
//void main()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// �������������������֮���ʱ��
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}

//��װ
//1�������ݺͷ����ŵ�����һ��
//2��������㿴�������ݸ��㿴��������㿴�ķ�װ���� �����޶���
//class Stack
//{
//public:
//	//�������涨��
//	void Push(int x)
//	{
//
//	}
//	//������������
//	void Pop();
//	bool Empty();
//	
//	//�������Ƕ��壬��ռ�ռ䡣
//private:
//	int *_a;
//	int _size;
//	int _capitity;
//};
//
////�����涨��
//void Stack::Pop()
//{
//
//}
//
////�����ǳ�ŵ����������ʵ
//
//// ���м��г�Ա���������г�Ա����
//class A1 {
//public:
//	void f1() {}
//private:
//	int _a;
//	char _c;
//};
//// ���н��г�Ա����
//class A2 {
//public:
//	void f2() {}
//};
//// ����ʲô��û��---����
//class A3
//{};
//
//int main()
//{
//	//��ʵ���������� ������ĳ�Ա����
//	Stack s1;
//	Stack s2;
//	Stack s3;
//	s1.Pop();
//	s1.Push(1);
//	s2.Push(1);
//
//	//������ֻ�洢��Ա���������洢��Ա���� ����֮�Ͳ������ڴ����
//	cout << sizeof(s1) << endl;
//	//һ����ʵ������N������ÿ������ĳ�Ա���������Դ洢��ͬ��ֵ
//	//���ǵ��õĺ���ȴ����ͬһ������,���ÿ�����󶼴�ų�Ա�������˷ѿռ�
//	
//	// û�г�Ա��������Ĵ�СΪ1 ԭ�򣺿�һ���ֽڲ���Ϊ�˴�����ݣ�����Ϊ��ռλ����ʾ����
//	cout << sizeof(A1) << endl; //8
//	cout << sizeof(A2) << endl; //1
//	cout << sizeof(A3) << endl; //1
//
//	return 0;
//}

//class Date
//{
//public:
//	//this��˭���������Ա������this��ָ��˭
//	void Init(int year, int month, int day) //Init(Date* this,int year, int month, int day)
//	{
//		/*_year = year;
//		_month = month;
//		_day = day;*/
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print() //����������������
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	/*
//	void Print(Data* this) //������thisָ��
//	{
//		cout << this->_year << "-" << this->_month << "-" << this._day << endl;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////thisָ���Ǵ���ջ�ϵ�:thisָ����һ���β�(vs�ڼĴ����ϵ�)
//int main()
//{
//	Date d1;
//	d1.Init(2020, 12, 11); //d1.Init(&d1, 2020, 12, 11);
//	d1.Print(); //d1.Print(&d1);
//	
//
//
//	return 0;
//}

// 1.��������ܱ���ͨ����
// 2.����������������������
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = NULL;
//	p->PrintA(); //����
//	p->Show(); //����
//	//��Ա�������ڹ����Ĵ���Σ�����p->Show()���ﲻ��ȥpָ��Ķ�������
//	//���ʳ�Ա���� �Ż�ȥ��
//
//	A a;
//	a.PrintA(); //p->PrintA(&a)��
//
//}


//class Date
//{
//public:
//	//C++�е�Ĭ�Ϻ���
//	// ���캯�� ->�ڶ�����ʱ���õĺ��������������ɳ�ʼ������
//	Date(int year, int month, int day)// ���ι���
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date() //�޲ι���
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	//����ʵ�����Զ����ù��캯��
//	Date d1(2020, 4, 12); 
//	d1.Print();
//
//	Date d2; //���ܼ�����
//	d2.Print();
//
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	
//	//û���幹�캯����������Ĭ�Ϲ����޲ι���
//	//Ĭ�������޲ι���
//	//1������������ͳ�Ա����û��������
//	//2������Զ������͵ĳ�Ա�������������Ĺ��캯����ʼ��
//
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time t;
//};
//
//
//int main()
//{
//	Date d1; //���ñ����� ���ɵĹ��캯��
//	d1.Print();
//
//	return 0;
//}
//
//class Date
//{
//public:
//		
//	//���õķ�ʽ->ȫȱʡ���캯��
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1; //����Ĭ�Ϲ��캯��->1���Լ�ʵ���޲ι��캯�� 2���Լ�ʵ��ȫȱʡ���캯�� 3��������Ĭ�ϵ��޲κ���
//	d1.Print();
//
//	Date d2(2020,12,11);
//	d2.Print();
//
//	return 0;
//}

class Date
{
public:

	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//���������������������ڵ����Ժ��Զ����ã���ɶ����������Դ��������������ɶ���Ĵݻ�
	~Date() //ջ֡�����������������Ķ���
	{
		cout << "~Date()" << endl;
		//�������ж�̬�ڴ濪�ٵĿռ䣬���������Ϳ���������
		//free(a);
		//a = nullptr;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2;

	return 0;
}