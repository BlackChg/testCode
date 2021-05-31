#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
#include <memory>
using namespace std;

//ʵ��auto_ptr
template<class T>
class Auto_ptr
{
public:
	Auto_ptr(T* ptr)
		:_ptr(ptr)
	{}
	~Auto_ptr()
	{
		if (_ptr)
			delete _ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}

	Auto_ptr(Auto_ptr<T>& ap)
		:_ptr(ap._ptr)
	{
		//��Դ����Ȩת�� 
		ap._ptr = nullptr;
	}

	Auto_ptr<T>& operator=(Auto_ptr<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr)
				delete _ptr;
			//��Դ����Ȩת�� 
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		return *this;
	}
private:
	T* _ptr;
};

void test()
{
	Auto_ptr<int> ap(new int);
}

//void test()
//{
//	auto_ptr<int> ap(new int);
//	auto_ptr<int> ap2(new int(2));
//	*ap = 10;
//	*ap2 = 20;
//	auto_ptr<int> ap3 = ap;
//	*ap = 10;//�����ñ���
//}

//RAII
//template<class T>
//class SmartPtr
//{
//public:
//	//���캯����ȡ��Դ����Ȩ
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	//ͨ�����������ͷ���Դ
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//	T& operator*()
//	{
//		return *_ptr;
//	}
//private:
//	T* _ptr;
//};
//
//class A
//{
//public:
//	int _a = 10;
//};
//
//void test()
//{
//	//����ָ��--���������������Զ��ͷ���Դ--�������ڴ�й©
//	SmartPtr<A> sp(new A);
//	(*sp)._a = 10;
//	sp->_a = 100;
//
//	//��ָͨ��--�ֶ��ͷ��ڴ�
//	int* p = new int;
//	A* pa = new A;
//	*p = 1;
//	pa->_a = 10;
//	//return  //��ǰ������ָͨ��ͻᵼ���ڴ�й©
//	delete p;
//	delete pa;
//}

//void test()
//{
//	//ͨ���쳣ģ��
//	try
//	{
//		vector<int> v;
//		//v.at(3) = 10;
//		v.reserve(1000000000000);
//	}
//	catch (exception& e)//�����γɶ�̬
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "..." << endl;
//	}
//}

int main()
{
	test();
	return 0;
}

//void fun1()
//{
//	//���쳣
//	throw "string error";
//	cout << "fun1()" << endl;
//}
//
//void fun2()
//{
//	int* arr = new int[100];
//	try
//	{
//		fun1();
//	}
//	catch (int i)
//	{ }
//	catch (double d)
//	{ }
//	catch (...)
//	{
//		delete[] arr;
//		cout << "delete[]" << endl;
//		//�����׳��쳣
//		throw;
//	}
//	cout << "fun2()" << endl;
//}
//
//void fun3()
//{
//	fun2();
//	cout << "fun3()" << endl;
//}
//
//int main()
//{
//	try
//	{
//		fun3();
//	}
//	catch (int i)
//	{ }
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//	catch (...)
//	{
//		cout << "..." << endl;
//	}
//
//	cout << "main()" << endl;
//
//	return 0;
//}



//template<class Mtx>
//class LockGuard //Ҳ������RAII˼��
//{
//public:
//	LockGuard(Mtx& mtx)
//		:_mtx(mtx)
//	{
//		_mtx.lock();//���첢����
//	}
//	~LockGuard()
//	{
//		_mtx.unlock();//�ͷŽ���
//	}
//
//	LockGuard(const LockGuard<Mtx>& lg) = delete;
//	LockGuard& operator=(const LockGuard<Mtx>& lg) = delete;
//private:
//	Mtx& _mtx;
//};
//
//mutex mtx;
//void fun1()
//{
//	//mtx.lock();
//	LockGuard<mutex> lg(mtx);
//	cout << "fun1()" << endl;
//	int n;
//	cin >> n;
//	if (n == 0)
//		return;
//	//mtx.unlock();
//}
//
//void fun2()
//{
//	//mtx.lock();//����
//	LockGuard<mutex> lg(mtx);
//	cout << "fun2()" << endl;
//	//mtx.unlock();
//}
//void test()
//{
//	thread t1(fun1);
//	thread t2(fun2);
//	t1.join();
//	t2.join();
//}

//mutex mtx;
////int sum = 0;
//atomic<int> sum(0);//ԭ�ӱ���
//void fun(int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		//�ӽ���������Ч��
//		//mt.lock();
//		//һ�д�������ж���ָ��
//		//ָ��֮���ִ�в���ԭ�Ӳ���
//		//mtx.try_lock();//����������
//		sum++;
//		//mt.unlock();
//	}
//}
//
//void test()
//{
//	int n;
//	cin >> n;
//	thread t1(fun, n);
//	thread t2(fun, n);
//	t1.join();
//	t2.join();
//	cout << sum << endl;
//}

//class threadManager
//{
//public:
//	explicit threadManager(thread& t)
//		:_t(t)
//	{}
//
//	~threadManager()
//	{
//		if (_t.joinable())//��ǰ�߳���Ч
//		{
//			_t.join();
//		}
//	}
//
//	threadManager(const threadManager &) = delete;
//	threadManager& operator=(const threadManager const&) = delete;
//private:
//	thread& _t;
//};
//
//void test()
//{
//	thread t1([] {});
//	//���߳���һ����������
//	threadManager tm(t1);//�ñ���ʱ�ֲ��������������ڽ������Զ��������������ͷ��߳�
//	//vector<int> v;
//	//v.at(3) = 10;//Խ���쳣���³�����ǰ����
//	return;
//}

//class A
//{
//public:
//	void fun1(int a, int b)
//	{
//		cout << "fun1(int, int)" << a << b << endl;
//	}
//};
//
//void fun(int& a)
//{
//	a *= 2;
//}
//
//void fun2(int* a) 
//{
//	*a += 2;
//}
//
//void test()
//{
//	A a;
//	//�������еĳ�Ա��������Ҫ������֮ǰȡ��ַ
//	thread t1(&A::fun1, &a, 1, 2);
//	t1.join();
//	int a1 = 1;
//	//fun������Ȼ�����ã�������ײ����������߳�ջ�ı��������ⲿ����Ӱ��
//	thread t2(fun, a1);
//	t2.join();
//	cout << a1 << endl;
//
//	thread t3(fun2, &a1);
//	t3.join();
//	cout << a1 << endl;
//
//	//������Ϊ���ã���Ҫʹ��ref(����)��ת��
//	thread t4(fun2, ref(a1));
//	t4.detach();//�����̷߳���
//	cout << a1 << endl;
//}

//void fun(int a)
//{
//	cout << "fun(int a)" << endl;
//}
//
//struct Fun
//{
//	void operator()()
//	{
//		cout << "operator())" << endl;
//	}
//};
//
//void test()
//{
//	//����ָ��
//	thread t(fun, 10);
//	//�ж��߳��Ƿ����
//	t.joinable();
//	t.join();//�̵߳ȴ�
//
//	//�º�������
//	Fun f;
//	thread t2(f);
//
//	//lambda
//	thread t3([] {cout << "lambda" << endl; });
//	cout << "test()" << endl;
//}

//struct Sum
//{
//	int operator()(int a, int b)
//	{
//		return a + b;
//	}
//};
//
//void test()
//{
//	auto f = [](int a, int b) {return a + b; };
//	int sum = f(10, 20);
//	Sum s;
//	s(10, 20);
//}

//void test()
//{
//	int t = 20;
//	auto f = [t](int a) {return a + t; };
//	auto f1 = [t](int a) {return a + t; };
//	f = f1;//error
//	auto f2(f);//ok
//}

