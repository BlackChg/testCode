//#include<iostream>
//
////���������ͻ
//namespace CHG
//{
//	int a = 10;
//	int b = 20;
//	int Add(int num1, int num2)
//	{
//		return num1 + num2;
//	}
//
//	int Sub(int num1, int num2)
//	{
//		return num1 - num2;
//	}
//}
//
////1��ָ�������ռ�
////2��չ�������ռ�->ȱ�㣺������¶������ʧȥ����Ч�� ��Ŀ���Ƽ����ճ���ϵ�Ƽ�ʹ��
////using namespace CHG;
//
////3��ָ��չ��
//using CHG::Sub;
//int main()
//{
//	int res = CHG::Add(1, 1);
//	int res2 = CHG::Sub(2, 1);
//	//int res = Add(1, 1); //ָ��չ��������
//	//int res2 = Sub(2, 1);����
//	printf("%d \n", res);
//	printf("%d \n", res2);
//
//	return 0;
//}

#include<iostream> //IO��ͷ�ļ�
using namespace std;//std��C++���namespace

int main()
{
	cout << "hello world!!!" << endl;

	int a = 1;
	double d = 1.11;
	printf("%d,%0.2f\n", a, d);
	//����Ҫָ�����͸�ʽ���Զ�ʶ���ʽ�����Ҹ�������
	cout << a << "," << d << endl;
	
	return 0;
}