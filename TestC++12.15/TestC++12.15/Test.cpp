#include<iostream>
using namespace std;
//
////�������const
////class Date
////{
////public:
////	Date(int year = 0, int month = 1, int day = 1)
////	{
////		_year = year;
////		_month = month;
////		_day = day;
////	}
////	//void Print()->void Print(Date* this)
////	void Print() const //->void Print(const Date* this)
////	{
////		cout << _year << "-" << _month << "-" << _day << endl;
////		//�����޸ĳ�Ա�����ˣ���Ϊconst���α�����*this
////		//this->_year = 10;
////	}
////private:
////	int _year;
////	int _month;
////	int _day;
////};
////
////void f(const Date& d)
////{
////	d.Print();
////}
////
////int main()
////{
////	Date d1(2020, 12, 15);
////	f(d1);
////	d1.Print();
////	return 0;
////}
//
////class Date
////{
////public:
////	Date(int year = 0, int month = 1, int day = 1)
////	{
////		_year = year;
////		_month = month;
////		_day = day;
////	}
////	
////	void f1() //void f1(Date* this)
////	{
////		f2(); //this->f2(this) //Ȩ����С ����
////	}
////
////	void f2() const //void f2(const Date* this)
////	{
////
////	}
////	void f3() //void f3(Date* this)
////	{
////
////	}
////	void f4() const //void f4(const Date* this)
////	{
////		//f3(); //void f3(this) //Ȩ�޷Ŵ󣬲�����
////	}
////private:
////	int _year;
////	int _month;
////	int _day;
////};
////
////int main()
////{
////	
////	return 0;
////}
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	 Date* operator&() 
//	{
//		cout << "Date* operator&()" << endl;
//		return this;
//		//�����ñ���ȡ������ĵ�ַ
//		//return nullptr
//	}
//
//	const Date* operator&() const //const Date* this
//	{
//		cout << "const Date* operator&()" << endl;
//		return this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2020, 12, 15);
//	Date d2(2020, 12, 15);
//	const Date d3;
//
//	cout << &d1 << endl;
//	cout << &d2 << endl;
//	cout << &d3 << endl;
//	return 0;
//}
//#include"Date.h"
//
//void Fun(const Date& d3, const Date& d4)
//{
//	cout << d3 - d4 << endl;
//	cout << (d3 > d4) << endl;
//}
//
//int main()
//{
//	Date d1(2020, 12, 15);
//	Date d2(2020, 12, 24);
//	d1.print();
//	Fun(d1, d2);
//
//	cout << d1 - d2 << endl;
//}

//class Date
//{
//public:
//	/*Date(int year = 0, int month = 1, int day = 1)
//	{
//		//�������ڸ�ֵ
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{
//		//��ʼ���б�
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//class B
//{
//public:
//	//�������ɳ�ʼ���б��Ƕ���ĳ�Ա�����Ķ���ĵط�
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	//���������ֶ�����Ҫ��������ʱ���ʼ���ģ��ͷ��ڳ�ʼ���б���
//	//��Ա����������
//	A _aobj; // û�� Ĭ�Ϲ��캯��(���ô��ξͿ��Ե������ֹ��캯��)
//	int& _ref; // ����
//	const int _n; // const
//
//	int _x; //����Ҫ�����ͳ�ʼ��
//
//};
//

//
//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int day)
//	{}
//private:
//	int _day;
//	Time _t;
//};
//
//
//int main()
//{
//	B b(1, 2); //������
//
//	Date d(1);
//
//	return 0;
//}

//class Date
//{
//public:
//
//	//explicit Date(int year = 0) //������Date d2 = 2;����
//	 Date(int year = 0)
//		:_year(year)
//		
//	{
//		cout << "Date(int year = 0, int month = 1, int day = 1)" << endl;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(1); //����
//	Date d2 = 2; //��ʽ���͵�ת�� �����tmp(2)+����tmp��������d2(tmp)+�Ż���ֱ�ӹ���
//	Date d3 = d2; //��������
//
//	return 0;
//}

//class Date
//{
//public:
//
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//
//	{
//		cout << "Date(int year = 0, int month = 1, int day = 1)" << endl;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2020, 12, 15);
//
//	//C+11
//	Date d2 = { 2020, 12, 16 };//��ʽ����ת��
//
//	return 0;
//}

//static��Ա����
// ��Ƴ�һ���࣬���Լ���������ܼƲ����˶��ٶ���
//int n = 0;
//class A
//{
//public:
//	A()
//	{
//		++n;
//	}
//	A(const A& a)
//	{
//		++n;
//	}
//};
//
//A f1(A a)
//{
//	return a;
//}
//
//int main()
//{
//	A a1;
//	A a2;
//
//	f1(a1);
//	n = 1; //˭�����Զ�n�����޸�
//	f1(a2);
//
//	cout << n << endl;
//	return 0;
//}

class A
{
public:
	A()
	{
		++n;
	}
	A(const A& a)
	{
		++n;
	}

	static int GetN() //û��thisָ�룬�����в��ܷ��ʷǾ�̬�ĳ�Ա ֻ�ܷ��ʾ�̬��
	{
		//_a = 10  error ��Ϊû��this
		return n;
	}

private:
	static int n; //���� ��������ĳ������������������ж������������
	//n���ڶ����У�n�ھ�̬��
};

int A::n = 0;//����

A f1(A a)
{
	return a;
}

int main()
{
	A a1;
	A a2;

	f1(a1);
	f1(a2);

	cout << a1.GetN() << endl;
	cout << a2.GetN() << endl;
	cout << A::GetN() << endl;

	//public
	/*cout << a1.n << endl;
	cout << a2.n << endl;
	cout << A::n << endl;
	a1.n = 10;*/

	return 0;
}

