#include <iostream>
#include <string>
#include <vector>
using namespace std;
//�����ж��Ƿ��ֵ�����
bool isDictionaries(const string& str1, const string& str2)
{
	//���еıȽ��Ծ��ǰ��ֵ������
	//ǰ�ߴ��ں��ߣ��������ֵ�����
	if (str1 >= str2)
		return false;
	return true;
}
int main()
{
	int n;
	cin >> n;
	int a = 1;
	int b = 1;
	vector<string> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 0; i < n - 1; ++i)
	{
		//�����ֵ�����
		if (v[i] >= v[i + 1])
		{
			a = 0;
		}
		//���ǰ���������
		if (v[i].size() >= v[i + 1].size())
		{
			b = 0;
		}
		if (b == 0 && a == 0)
			break;
	}
	if (a && b)
		cout << "both" << endl;
	else if (a && !b)
		cout << "lexicographically" << endl;
	else if (!a && b)
		cout << "lengths" << endl;
	else if (!a && !b)
		cout << "none" << endl;
	return 0;
}
