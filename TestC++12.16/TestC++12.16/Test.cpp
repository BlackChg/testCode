//#include<iostream>
//using namespace std;
//
////class Date
////{
////public:
////	Date(int year=0, int month=1, int day=1)
////		:_year(year)
////		,_month(month)
////		,_day(day)
////	{}
////
////	//2. �Ǿ�̬��Ա�������Ե�����ľ�̬��Ա������?
////	void f1()
////	{
////		f2();
////	}
////
////	//1. ��̬��Ա�������Ե��÷Ǿ�̬��Ա������
////	static void f2() //��̬��Ա����û��thisָ�� 
////	{
////		//f1();
////	}
////
////private:
////	int _year; 
////	int _month; 
////	int _day;
////};
////
////int main()
////{
////	Date d1(1, 2, 3);
////	Date d2 = 1; //C++98
////	Date d3 = { 1,2 };  //C++11
////	Date d4 = { 1,2,3 };
////
////	return 0;
////}
//
//class Sum
//{
//public:
//	Sum()
//	{
//		_sum += _i;
//		++_i;
//	}
//	static void Init()
//	{
//		_i = 1;
//		_sum = 0;
//	}
//	static int GetSum()
//	{
//		return _sum;
//	}
//private:
//	static int _i;
//	static int _sum;
//};
//
//int Sum::_i = 1;
//int Sum::_sum = 0;
//
//class Solution {
//public:
//
//	int Sum_Solution(int n) {
//		//Sum a[n];
//		Sum::Init();
//		Sum* p = new Sum[n];
//		return Sum::GetSum();
//	}
//};
//
//int main()
//{
//	Solution st;
//	Solution st2;
//	cout << st.Sum_Solution(5) << endl;
//	cout << st2.Sum_Solution(5) << endl;
//	return 0;
//}
#include<iostream>
using namespace std;
//
//class Date
//{
//public:
//
//	Date()
//		:_year(2020)
//		,_month(12)
//		,_day(16)
//	{}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	//C++11
//	//����ʱ��ȱʡֵ
//	int _year = 0;
//	int _month = 1;
//	int _day = 1;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	return 0;
//}

//��Ԫ
//class Date
//{
//	friend void f(const Date& d); //��Ԫ����
//public:
//
//	Date()
//		:_year(2020)
//		, _month(12)
//		, _day(16)
//	{}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	
//	int _year = 0;
//	int _month = 1;
//	int _day = 1;
//};
//
//void f(const Date& d)
//{
//	cout << d._year << endl;
//}
//
//int main()
//{
//	Date d1;
//	d1.Print();
//	f(d1);
//	return 0;
//}

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 0,int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{}

private:
	int _year = 0;
	int _month = 1;
	int _day = 1;
};

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	in >> d._year>>d._month>>d._day;
	return in;
}
//cout->ostream
//cin->istream
int main()
{
	Date d1(2020,12,16);
	Date d2(2020, 12, 17);
	//cin >> d1;
	cout << d1 << d2 << endl;

	int x = 1;
	double y = 1.11;
	//Ϊʲô���Զ�ʶ�����ͣ���Ϊ�Ǵ��ں���������
	cout << x << endl;//cout.operator<<(&cout, x)
	cout << y << endl;//cout.operator<<(&cout, y)

	return 0;
}