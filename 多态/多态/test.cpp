#include <iostream>
using namespace std;

//class Base
//{
//public:
//	virtual void fun1()
//	{
//		cout << "Base::fun1()" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "Base::fun2()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void fun1()
//	{
//		cout << "Derive::fun1()" << endl;
//	}
//	virtual void fun3()
//	{
//		cout << "Derive::fun3()" << endl;
//	}
//	virtual void fun4()
//	{
//		cout << "Derive::fun4()" << endl;
//	}
//private:
//	int _d = 2;
//};

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; } 
	virtual void func2() { cout << "Base1::func2" << endl; }
private: int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; } 
	virtual void func2() { cout << "Base2::func2" << endl; }
private: int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; } 
	virtual void func3() { cout << "Derive::func3" << endl; }
private: int d1;
};

typedef void(*vfptr)();
void printfVftable(vfptr vtable[])
{
	cout << "����ַ��" << vtable << endl;
	//�������Ԫ�أ��麯��ָ��
	vfptr* fptr = vtable;
	while (*fptr != nullptr)
	{
		(*fptr)();
		++fptr;
	}
}

void test()
{
	Base1 b1;
	cout << "Base1��";
	vfptr* vtable = (vfptr*)(*(int*)&b1);
	printfVftable(vtable);
	Base2 b2;
	cout << "Base2��";
	vtable = (vfptr*)(*(int*)&b2);
	printfVftable(vtable);

	Derive d;
	cout << "Derive ��һ�����";
	vtable = (vfptr*)(*(int*)&d);
	printfVftable(vtable);

	cout << "Derive �ڶ������";
	vtable = (vfptr*)(*(int*)((char*)&d + sizeof(Base1)));
	printfVftable(vtable);
}

//class Vip
//{
//public:
//	virtual void online()
//	{
//		cout << "7���Ż�" << endl;
//	}
//};
//
//class Common : public Vip
//{
//public:
//	virtual void online()
//	{
//		cout << "ȫ�����Ż�" << endl;
//	}
//};
//
//void fun(Vip& v)
//{
//	v.online();
//}
//
//void test()
//{
//	Vip v;
//	Common c;
//	fun(v);
//	fun(c);
//	
//}

////�麯��ָ�����
////û�з���ֵ�������б�Ϊ�յ�ָ��
//typedef void(*vfptr)();
//
//class Base
//{
//public:
//	virtual void fun1()
//	{
//		cout << "fun1()" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "Base::fun2()" << endl;
//	}
//	void fun3()
//	{
//		cout << "Base::fun3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void fun1()
//	{
//		{
//			cout << "Derive::fun1()" << endl;
//		}
//	}
//private:
//	int _d = 2;
//};

//�麯��ָ�����
//û�з���ֵ�������б�Ϊ�յ�ָ��
//typedef void(*vfptr)();
//
//class Base
//{
//public:
//	virtual void fun1()
//	{
//		cout << "fun1()" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "Base::fun2()" << endl;
//	}
//	void fun3()
//	{
//		cout << "Base::fun3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//void test()
//{
//	int a = 10; //ջ
//	int* ptr = new int;//��
//	static int s = 1; //���ݶ�
//	const char* str = "123"; //���ֳ�����/�����
//	cout << "ջ��" << &a << endl;
//	cout << "�ѣ�" << ptr << endl;
//	cout << "���ݶΣ�" << &s << endl;
//	printf("����Σ�%p\n", str);
//
//	Base b;
//	vfptr* vfp = (vfptr*)(int*)&b;
//	cout << "����׵�ַ��"<< *vfp << endl;
//}

//class A
//{
//public:
//	virtual void fun1()
//	{
//		cout << "fun1()" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "fun2()" << endl;
//	}
//private:
//	int _a = 1;
//};
//
//class B
//{
//public:
//	virtual void fun3()
//	{
//		cout << "fun3()" << endl;
//	}
//private:
//	int _a = 2;
//};
//
//void test()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//}

//class Base
//{
//public:
//	virtual void fun1()
//	{
//		cout << "fun1()" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "Base::fun2()" << endl;
//	}
//	void fun3()
//	{
//		cout << "Base::fun3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void fun1()
//	{
//		{
//			cout << "Derive::fun1()" << endl;
//		}
//	}
//private:
//	int _d = 2;
//};
//
//void test()
//{
//	Base b;
//	Derive d;
//}

//class Base
//{
//public:
//	virtual void fun()
//	{
//		cout << "fun()" << endl;
//	}
//protected:
//	int _a = 1;
//};
//
//void test()
//{
//	Base b;
//}

//������
//class A
//{
//public:
//	//���麯��
//	virtual void fun() = 0
//	{}
//};
//
//class B : public A
//{
//public:
//	virtual void fun()
//	{
//		cout << "B::fun()" << endl;
//	}
//};
//
//class C : public A
//{
//public:
//	virtual void fun()
//	{
//		cout << "C::fun()" << endl;
//	}
//};
//
//class D: public A
//{};
//
//void test()
//{
//	A a;
//	B b;
//	C c;
//	D d;
//}

//class A final
//{};
//class B : A
//{};


//class Vip
//{
//public:
//	virtual void online() final
//	{
//		cout << "7���Ż�" << endl;
//	}
//};
//
//class Common : public Vip
//{
//public:
//
//	virtual void online()
//	{
//		cout << "ȫ�����Ż�" << endl;
//	}
//};


//class Vip
//{
//public:
//	virtual void online() 
//	{
//		cout << "7���Ż�" << endl;
//	}
//};
//
//class Common : public Vip
//{
//public:
//
//	virtual void online() override
//	{
//		cout << "ȫ�����Ż�" << endl;
//	}
//};



//class A
//{};
//
//class B : public A
//{};

//class Vip
//{
//public:
//	virtual void online()
//	{
//		cout << "7���Ż�" << endl;
//	}
//	virtual ~Vip()
//	{
//		cout << "~Vip" << endl;
//	}
//};
//
//class Common : public Vip
//{
//public:
//	virtual void online()
//	{
//		cout << "ȫ�����Ż�" << endl;
//	}
//	~Common()
//	{
//		if (_name)
//		{
//			delete[] _name;
//			cout << "delete[] _name" << endl;
//		}
//		cout << "~Common" << endl;
//	}
//private:
//	char* _name = new char[100];
//};

//void test()
//{
//	Vip * v = new Common;
//	delete v;
//}

////��̬
//void fun(Vip& v)
//{
//	v.online();
//}
//void fun1(Vip* v)
//{
//	v->online();
//}
//
////�Ƕ�̬
//void fun2(Vip v)
//{
//	v.online();
//}
//
//void test()
//{
//	Vip v;
//	Common m;
//	fun(v);
//	fun(m);
//	fun1(&v);
//	fun1(&m);
//	fun2(v);
//	fun2(m);
//}

int main()
{
	test();
	return 0;
}