//#include <iostream>
//#include <vector>
//using namespace std;
//void fun1(vector<int>& vec)
//{
//	int sz = vec.size();
//	int left = 0;
//	int right = sz / 2;
//	vector<int> res;
//	while (left < sz / 2)//һ�η����ţ��������
//	{
//		res.push_back(vec[left++]);
//		res.push_back(vec[right++]);
//	}
//	vec = res;
//}
//void fun(vector<int>& vec, int k)
//{
//	while (k--)//ϴk����
//	{
//		fun1(vec);
//	}
//	for (int i = 0; i < vec.size(); ++i)
//	{
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int t, n, k;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n >> k;
//		vector<int> vec(2 * n);
//		for (int i = 0; i < 2 * n; ++i)
//		{
//			cin >> vec[i];
//		}
//		fun(vec, k);
//	}
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//С��4�׸���
void fun1(string& str, int n, vector<int>& vec, int& idx)
{
	vec.resize(n);
	for (int i = 0; i < n; ++i)
	{
		vec[i] = i + 1; //���ø���λ��
	}
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'U') //���������
		{
			if (idx == 1)//����ǵ�һҳ��Ҫ������������һ��
				idx = n;
			else
				--idx; //���������һ��
		}
		else    //���������
		{
			if (idx == n) //��������һҳ��Ҫ�����������һ��
				idx = 1;
			else
				++idx;//���������һ��
		}
	}
}
void fun2(string& str, int n, vector<int>& vec, int& idx)
{
	vec.resize(4);
	for (int i = 0; i < 4; ++i)
	{
		vec[i] = i + 1;//��ʼ����һҳ�ĸ����ʾ
	}
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'U')
		{
			if (idx == 1) //��Ҫ��ҳ�����һҳ
			{
				for (int i = 0; i < 4; ++i)
				{
					vec[i] += n - 4;//ҳ�涼��Ҫ����
				}
				idx = n;//����������һ��
			}
			else 
			{
				if (idx == vec[0])//�����һҳ�еĵ�һ�׸裬һҳһҳ�÷�
				{
					for (int i = 0; i < 4; ++i)
					{
						--vec[i];
					}
				}
				--idx;
			}
		}
		else
		{
			if (idx == n)//��Ҫ��ҳ����һҳ
			{
				for (int i = 0; i < 4; ++i)
				{
					vec[i] -= n - 4;
				}
				idx = 1;
			}
			else
			{
				if (idx == vec[3])//�����һҳ�����һ��λ�ã���Ҫһҳһҳ�÷�
				{
					for (int i = 0; i < 4; ++i)
					{
						++vec[i];
					}
				}
				++idx;
			}
		}
	}
}
void fun(string& str, int n)
{
	vector<int> res;
	int idx = 1;
	if (n <= 4)
		fun1(str, n, res, idx);
	else
		fun2(str, n, res, idx);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	cout << idx << endl;
}
int main()
{
	int n;
	while (cin >> n)
	{
		string str;
		cin >> str;
		fun(str, n);
	}
	return 0;
}