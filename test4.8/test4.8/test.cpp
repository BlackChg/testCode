#include <iostream>
using namespace std;

int main()
{
	int i = 1;
	char c = (*(char*)&i);
	if (c)
		cout << "С��" << endl;
	else
		cout << "���" << endl;
	return 0;
}

//int main()
//{
//	union
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	if (un.c)
//		cout << "С��" << endl;
//	else
//		cout << "���" << endl;
//	return 0;
//}