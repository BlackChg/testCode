#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//struct A
//{
//	void SetStudentInfo(const char* name, const char* gender, int age) 
//	{
//		strcpy(_name, name); 
//		strcpy(_gender, gender);
//		_age = age;
//	}
//
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//
//	char _name[20]; 
//	char _gender[3]; 
//	int _age;
//};

//struct Student
//{
//public:
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//
//private:
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//
//int main()
//{
//	Student s;
//	s.SetStudentInfo("�׳���i", "��", 22);
//	s.PrintStudentInfo();
//	return 0;
//}

class A
{
public:
	void print()
	{
		cout << "A::print()" << endl;
	}
private:
	int _a;
};

class B
{
private:
	int _b;
};
class C
{
public:
	void print()
	{
		cout << "C::print()" << endl;
	}
};
class D
{};

int main()
{
	cout << "�к��������ԣ�" << sizeof(A) << endl;
	cout << "������û������" << sizeof(B) << endl;
	cout << "�к���û���ԣ�" << sizeof(C) << endl;
	cout << "���ࣺ" << sizeof(D) << endl;
}