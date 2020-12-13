#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//class Person
//{
//private:
//	String _name;
//	int _age;
//};
//int main()
//{
//	Person p;
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d) //Date& d = d1;
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void func(Date dd)//���ÿ������� Date dd = d1;(���ÿ��������һ����ʽ)
//{
//
//}
//
//int main()
//{
//	Date d1(2020, 12, 13);
//	Date d2(d1); //��������==Date d2(2020, 12, 13);
//	Date d3 = d2;//�ȼ�
//	d1.print();
//	d2.print();
//	d3.print();
//	
//	//func(d1);
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d) //Date& d = d1;
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//
////�Զ��������ǲ�����������ģ�Ҫ�þ͵�ʵ�����غ������Զ��������õ�ʱ��͵ȼ��ڵ���������غ���
//int main()
//{
//	Date d1(2020, 12, 13);
//	Date d2(2020, 12, 14);
//
//	int flag =d1 == d2;//->operator ==(d1, d2);
//	//��������һ�㲻��������д����Ϊ�ɶ��Բ���
//	operator ==(d1, d2);
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d) //Date& d = d1;
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//d1 ==d2
//	//d1.operator==(&d1,d2)
//	bool operator==(const Date& d) //bool operator==(Date* this, const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//	bool operator>(const Date& d)
//	{
//		if (_year > d._year)
//		{
//			return true;
//		}		
//		else if (_year == d._year&&_month > d._month)
//		{
//			return true;
//		}	
//		else if (_year == d._year&&_month == d._month&&_day > d._day)
//		{
//			return true;
//		}
//		return false;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////�Զ��������ǲ�����������ģ�Ҫ�þ͵�ʵ�����غ������Զ��������õ�ʱ��͵ȼ��ڵ���������غ���
//int main()
//{
//	Date d1(2020, 12, 15);
//	Date d2(2020, 12, 14);
//
//	int flag = d1 == d2;//->d1.operator ==(d2);
//	int flag1 = d1 > d2;
//	cout << flag << endl;
//	cout << flag1 << endl;
//
//	return 0;
//}

//ʵ��һ�����Ƶ�������
class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//��2���������귵��29
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 ==0))
		{
			return 29;
		}
		return monthDays[month];
	}

	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0 
			&& month>=1 && month<=12 
			&& day >=1 && day<=GetMonthDay(year,month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "�Ƿ�����" << endl;
		}
		
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator<(const Date& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year && _month < d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day < d._day)
		{
			return true;
		}
		return false;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	//d1<=d2 =>d1<d2||d1==d2
	bool operator<=(const Date& d)//bool operator<=(Date* this, const Date& d)
	{
		return *this < d || *this == d; //���������ʵ��
	}

	//d1 > d2 =>!(d1<=d2)
	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	//d1>=d2
	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	void print()
	{
		cout << _year << "-" << _month << "-" << _day<<endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d;
	d.print();

	Date d2(2020, 12, 13);
	d2.print();

	Date d3(2021, 12, 14);
	d3.print();

	cout << (d3 < d2) << endl;
	cout << (d3 > d2) << endl;
	cout << (d3 == d2) << endl;
	cout << (d3 != d2) << endl;
	cout << (d3 <= d2) << endl;
	cout << (d3 >= d2) << endl;

	return 0;
}