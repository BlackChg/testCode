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
//class Date
//{
//public:
//
//	//��õ�ǰ����·ݵ�����
//	int GetMonthDay(int year, int month)
//	{
//		static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		//��2���������귵��29
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 ==0))
//		{
//			return 29;
//		}
//		return monthDays[month];
//	}
//
//	//���캯��
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		if (year >= 0 
//			&& month>=1 && month<=12 
//			&& day >=1 && day<=GetMonthDay(year,month))
//		{
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//		else
//		{
//			cout << "�Ƿ�����" << endl;
//		}
//		
//	}
//	
//	//��������
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	//ֻҪ�����������ڣ��;���������
//	Date& operator=(const Date& d) //��ֵ���ػ�ȥ���ÿ�������
//	{
//		if(this != &d)
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		return *this; 
//	}
//
//	//�жϵ�ǰ�����Ƿ��d����С
//	inline bool operator<(const Date& d)
//	{
//		if (_year < d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month < d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day < d._day)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	//�жϵ�ǰ���ں�d�����Ƿ����
//	inline bool operator==(const Date& d)
//	{
//		return _year == d._year && _month == d._month && _day == d._day;
//	}
//
//	//d1<=d2 =>d1<d2||d1==d2 
//	bool operator<=(const Date& d)//bool operator<=(Date* this, const Date& d)
//	{
//		return *this < d || *this == d; //���������ʵ��
//	}
//
//	//d1 > d2 =>!(d1<=d2)
//	bool operator>(const Date& d)
//	{
//		return !(*this <= d);
//	}
//
//	//d1>=d2
//	bool operator>=(const Date& d)
//	{
//		return !(*this < d);
//	}
//
//	//d1!=d2
//	bool operator!=(const Date& d)
//	{
//		return !(*this == d);
//	}
//
//	//d1+10; һ���µ����ڵ��ڵ�ǰ����+����
//	Date operator+(int day)
//	{
//		Date ret = *this; //��d1��������һ��ret;
//		ret._day += day;
//		while (ret._day > GetMonthDay(ret._year, ret._month))
//		{
//			//������ڵ��첻�Ϸ�������Ҫ���½�λ
//			ret._day -= GetMonthDay(ret._year, ret._month);
//			ret._month++;
//
//			if (ret._month == 13)
//			{
//				ret._year++;
//				ret._month = 1;
//			}
//		}
//		return ret;
//	}
//
//	//d1+=10
//	Date operator+=(int day)
//	{
//		_day += day;
//		while (_day > GetMonthDay(_year, _month))
//		{
//			_day -= GetMonthDay(_year, _month);
//			++_month;
//			if (_month == 13)
//			{
//				++_year;
//				_month = 1;
//			}
//		}
//		return *this;
//	}
//
//	Date& operator -= (int day)
//	{
//		_day -= day;
//		while (_day <= 0)
//		{
//			_month--;
//			if (_month == 0)
//			{
//				_year--;
//				_month = 12;
//			}
//			_day += GetMonthDay(_year, _month);
//		}
//		return *this;
//	}
//
//
//	Date operator-(int day)
//	{
//		Date ret = *this;
//		ret._day -= day;
//		while (ret._day<=0)
//		{
//			ret._month--;
//			if (ret._month == 0)
//			{
//				ret._year--;
//				ret._month = 12;
//			}
//			ret._day += GetMonthDay(ret._year, ret._month);
//		}
//		return ret;
//	}
//
//	//++d
//	Date& operator++()
//	{
//		_day ++;
//		while (_day > GetMonthDay(_year, _month))
//		{
//			_day -= GetMonthDay(_year, _month);
//			++_month;
//			if (_month == 13)
//			{
//				++_year;
//				_month = 1;
//			}
//		}
//		return *this;
//	}
//
//	Date& operator--()
//	{
//		_day --;
//		while (_day <= 0)
//		{
//			_month--;
//			if (_month == 0)
//			{
//				_year--;
//				_month = 12;
//			}
//			_day += GetMonthDay(_year, _month);
//		}
//		return *this;
//	}
//
//	int operator-(const Date& d) //��������
//	{
//
//	}
//
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day<<endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////�Զ������ʹ������ͷ���ֵʱ���ڿ��Ե�����¾���ʹ�����ã����ٿ�������ĵ���
//int main()
//{
//	Date d;
//	d.print();
//
//	Date d2(2020, 12, 13);
//
//	Date d3(2021, 12, 14);
//
//	
//	////����operator=
//	//d2 = d3;//���������Ѿ������ҳ�ʼ�����ˣ����������d2��ֵ����������d1
//	////���ÿ�������
//	//Date d4(d2);//d3�������ڣ�����d3ʱ��d1ȥ��ʼ��
//	//Date d5 = d2;//�ر�ע�⣬�����ǿ���������operator=
//
//	/*1�����ǲ�ʵ��ʱ�����������ɵ�Ĭ�Ϲ��캯����������������Գ�Ա������
//	�������;Ͳ������Զ������ͻ���������Ա����� ���������
//	  2�����ǲ�ʵ��ʱ�����������ɿ��������operator=������ɰ��ֽڵ�ֵ������ǳ������
//	  Ҳ����˵��Щ�࣬�����ǲ���Ҫȥʵ�ֿ��������operator=�ģ���Ϊ������Ĭ�����ɾ�
//	  �����ã�����Date���������ӵ�
//	*/
//
//	d2 = d3;
//	d2.print();
//	d3.print();
//
//	return 0;
//}

//ʵ��һ�����Ƶ�������
class Date
{
public:

	//��õ�ǰ����·ݵ�����
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//��2���������귵��29
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return monthDays[month];
	}

	//���캯��
	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0
			&& month >= 1 && month <= 12
			&& day >= 1 && day <= GetMonthDay(year, month))
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

	//��������
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Date& operator=(const Date& d) 
	{
		if (this != &d)
			_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	//�жϵ�ǰ�����Ƿ��d����С
	inline bool operator<(const Date& d)
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

	//�жϵ�ǰ���ں�d�����Ƿ����
	inline bool operator==(const Date& d)
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

	//d1!=d2
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	//d1+=10
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= -day;
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}

	//d1-=10
	Date& operator -= (int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	Date operator-(int day)
	{
		Date ret = *this;	
		return ret -= day;;
	}

	Date& operator--()
	{
		return *this -= 1;
	}

	Date operator--(int)
	{
		Date tmp = *this;
		*this -= 1;
		return tmp;
	}

	//d1+10; һ���µ����ڵ��ڵ�ǰ����+����
	Date operator+(int day)
	{
		Date ret = *this; //��d1��������һ��ret;

		return ret += day;
	}

	//++d1
	Date& operator++() //ֱ�ӷ��ؼ�֮���
	{
		return *this += 1;
	}

	//d1++
	Date operator++(int)//Ϊ�˹��캯������
	{
		Date tmp(*this); //���ص��Ǽ�֮ǰ��
		*this += 1;
		return tmp;
	}

	int operator-(const Date& d) //��������
	{
		Date max = *this; //��������
		Date min = d;
		int flag = 1;
		if (*this < d)
		{
			min = *this; //��ֵ operator=
			max = d;
			flag = -1;
		}
		int n = 0;
		while (min != max)
		{
			++min; //�Զ������;�����ǰ�ã��ٿ������ι���
			++n;
		}
		return flag*n;
	}

	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{

	Date d1(2020, 12, 15);
	Date d2(2020, 12, 12);
	int res = d1 - d2;
	cout << res << endl;
	

	return 0;
}