//#include<iostream>
//using namespace std; //c++�������ж����Ƿŵ�stdd�����ռ���
//
//int main()
//{
//	cout << "hello world"<<endl; 
//
//	return 0;
//}


//#include<iostream>
////using namespace std; //c++�������ж����Ƿŵ�std�����ռ���
//
//int main()
//{
//	//�Զ�ʶ������
//	std::cout << "hello world"<<std::endl; 
//	int i = 1;
//	double d = 1.11;
//	std::cout << i <<" "<< d << std::endl;
//
//	return 0;
//}


//#include<iostream>
//using namespace std; //c++�������ж����Ƿŵ�std�����ռ���
//
//int main()
//{
//	//�Զ�ʶ������
//	std::cout << "hello world"<<std::endl; 
//	int i = 1;
//	double d = 1.11;
//	cin >> i >> d;//��������
//	std::cout << i <<" "<< d << std::endl;
//
//	return 0;
//}


//#include<iostream>
////using namespace std; //c++�������ж����Ƿŵ�std�����ռ���
////�󹤳��Ƽ�������
//using std::cout;
//using std::endl;
//using std::cin;
//int main()
//{
//	//�Զ�ʶ������
//	std::cout << "hello world"<<std::endl; 
//	int i = 1;
//	double d = 1.11;
//	cin >> i >> d;//��������
//	std::cout << i <<" "<< d << std::endl;
//
//	return 0;
//}


#include<iostream>
using namespace std;

////ȱʡ���� :ȫȱʡ+��ȱʡ
////ȱʡ�����������ģ����ұ���Ҫ��������
//
////void Fun1(int a, int b = 20 , int c )//���󣡣���
////{
////	cout << "a = " << a << endl;
////	cout << "b = " << b << endl;
////	cout << "c = " << c << endl;
////}
//
//void Fun(int a = 5)
//{
//	cout << a << endl;
//}
//
//void Fun1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//void Fun2(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	//Fun(10);//10
//	//Fun();//5
//	Fun1(1, 2);//1 2 30
//	Fun1();//10 20 30
//	Fun2(1);//1 20 30
//	Fun2(1, 2, 3);//1 2 3
//
//	return 0;
//}


//�������أ���������ͬ-> ������ͬ���������� or �������� or ����˳��ͬ��
//����ֵ����Ҫ��
//ֻ�Ƿ���ֵ��ͬ���������أ����뱨��
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//long Add(long left, long right)
//{
//	return left + right;
//}
//void Fun(int a, char c)
//{
//
//}
//void Fun(char c, int a)
//{
//
//}
//int main()
//{
////�����Զ�ʶ�����͵������Ӧ�ĺ���
//	Add(10, 20);
//	Add(10.0, 20.0);
//	Add(10L, 20L);
//
//	return 0;
//}


//1�����ñ����ڶ����ʱ���ʼ��
//2��һ���������Զ������
//3�����ö����ܱ��ı�
//4���������ͱ���һ��
//5������֮�丳ֵû��Ȩ����С�ͷŴ�Ĺ�ϵ�����ò���
int main()
{
	int a = 1;
	int& ra = a;//ra��a�����ã�����Ҳ���Ǳ�����a��ȡ��һ������
	ra = 10;
	int& raa = ra;//raa�����ͻ���int
	raa = 20;
	int b = 2;
	raa = b;//��b��ֵ��ֵ��raa

	const int c = 1;
	//int& rc = c; ���벻ͨ�� ԭ��aֻ��,b������Ϊ�ɶ���д �������ͱ���һ��
	
	int e = 1;
	int& d = e; 
	const int& f = e; //e�ǿɶ���д f��Ϊֻ��
	e = 2;//ok
	//f = 3;error
	//�ܽ᣺����ȡ����ʱ���������ʵ�Ȩ�޿�����С�����ܷŴ�

	int i = 1;
	double db = i;//��ʽ����װ��
	//double& rdb = i; ���벻ͨ��
	const double& rdb = i;//ok ͨ����ʱ������������  ��ʱ�����г���(��ʱ����ֻ�ɶ�)
	return 0;
}