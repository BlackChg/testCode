#include <iostream>
using namespace std;

/* ��ʼʱ��С����������������ֵ��Ϊ 10000�����С���ܲ���ÿ�������600 ��������
���С����Ϣ��ÿ�������� 300 ����������������ĺ����Ӷ��Ǿ��ȱ仯�ġ�С��������һ���ӡ���Ϣһ���ӡ�����һ���ӡ�����Ϣһ���ӡ������ѭ����
���ĳ��ʱ��С������������ 0������ֹͣ����������С���ڶ�ú�ֹͣ������Ϊ��ʹ��Ϊ������������Ϊ��λ����𰸡�
*/
//int main()
//{
//	int a = 10000;
//	int b = 300;
//	int res = 0;
//	int count = 0;
//	while (res < 9400)
//	{
//		res += 300;
//		++count;
//	}
//	cout << res << endl;
//	
//	int c = a - res;
//
//	int d = c / 10;
//	count = count * 2 * 60;
//	cout << d + count << endl;
//	return 0;
//}

class Date
{
public:
	int getDay(int year, int month)
	{
		static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		//�жϵ����Ƿ�Ϊ����
		if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0))
		{
			++day;
		}
		return day;
	}

	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		,_day(day)
	{}

	Date& operator+=(int day)
	{
		_day += day;
		while (_day > getDay(_year, _month))
		{
			_day -= getDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}

	Date& operator++() 
	{
		*this += 1;
		return *this;
	}

	bool operator!=(Date& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
			return false;
		return true;
	}

	int operator-(Date& d)
	{
		int count = 0;
		while (*this != d)
		{
			++count;
			++d;
		}
		return count;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 7, 1);
	Date d2(1921, 7, 23);
	int res = d1 - d2;
	res = res * 24 * 60;
	cout << res << endl;
	return 0;
}