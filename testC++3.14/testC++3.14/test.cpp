#include <iostream>
using namespace std;

class A
{
public:
	A(int a)
		:_a(a)
	{
		cout << "A(int)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

void test()
{
	A* pa = (A*)malloc(sizeof(A));
	//�����пռ���г�ʼ��
	new(pa) A(10);
	//��ʾ��������
	pa->~A();
	free(pa);
}

//class ListNode
//{
//public:
//	void* operator new(size_t n)
//	{
//		//�����ڴ�صķ�ʽ
//		cout << "operator new" << endl;
//		allocator<ListNode> alloc; //�ռ�������
//		return alloc.allocate(1);
//	}
//
//	void operator delete(void* ptr)
//	{
//		cout << "operator delete" << endl;
//		allocator<ListNode> alloc;//�ռ�������
//		alloc.deallocate((ListNode*)ptr, 1);
//	}
//private:
//	int _data = 0;
//	ListNode* _next = nullptr;
//};
//void test()
//{
//	ListNode* node = new ListNode;
//	delete node;
//}

//void test()
//{
//	int* ptr = (int*)operator new(sizeof(int) * 2);
//	operator delete(ptr);
//
//	//����ʧ�����쳣
//	int* ptr1 = (int*)operator new(0x7fffffff);
//	operator delete(ptr1);
//}

//class A
//{
//public:
//	A(int a, int b, int c)
//		:_a(a)
//		,_b(b)
//		,_c(c)
//	{}
//
//private:
//	int _a;
//	int _b;
//	int _c;
//};
//
//void test()
//{
//	A* pa1 = new A(10, 20, 30);
//	delete pa1;
//
//	A* arr = new A[10];
//	delete[] arr;
//}

//void test()
//{
//	//����ռ�
//	int* ptr = new int;
//	//����ռ䲢��ʼ��
//	int* ptr2 = new int(1);
//	//���������Ŀռ䣬�ռ��СΪ4*10=40
//	int* arr = new int[10];
//
//	//�ͷŵ����ռ�
//	delete ptr;
//	delete ptr2;
//
//	//�ͷ������Ķ���ռ�
//	delete[] arr;
//}

int main()
{
	test();
	return 0;
}