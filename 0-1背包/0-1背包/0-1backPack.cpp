#include <iostream>
#include <vector>
using namespace std;

int backPackII(int m, vector<int>& A, vector<int>& V)
{
    // write your code here
    //int n = A.size();
    //vector<vector<int>> maxValue(n + 1, vector<int>(m + 1, 0));
    //for (int i = 1; i <= n; ++i)//��ѡ�����Ʒ����
    //{
    //    for (int j = 1; j <= m; ++j)//�����Ĵ�С
    //    {
    //        if (A[i - 1] > j)//��Ʒ��С���ڱ��������������Ʒ�Ų��£������ܼ�ֵ������һ����Ʒ���ܼ�ֵ
    //            maxValue[i][j] = maxValue[i - 1][j];
    //        else
    //            //��������������Ʒ�������������������1�����Ÿ���Ʒ��2���Ÿ���Ʒ
    //            //1�����Ÿ���Ʒ���ֵ������һ����Ʒ���ܼ�ֵ
    //            //2������Ʒ����Ҫ��������С��ȥ��ǰ��Ʒ�Ĵ�С��Ȼ��������ʣ�µ�����������ֵ+��ǰ��Ʒ��ֵ
    //            //�ж��ĸ���ֵ����ͱ�ʾ��[i][j]������ֵ��Ϊ˭
    //            maxValue[i][j] = max(maxValue[i - 1][j], maxValue[i - 1][j - A[i - 1]] + V[i - 1]);
    //    }
    //}

    //return maxValue[n][m];

    int n = A.size();
    vector<int> maxValue(m + 1, 0);
    for (int i = 1; i <= n; ++i)//��ѡ�����Ʒ����
    {
        for (int j = m; j > 0; --j)//�����Ĵ�С
        {
            if (A[i - 1] <= j)
                maxValue[j] = max(maxValue[j], maxValue[j - A[i - 1]] + V[i - 1]);
        }
    }

    return maxValue[m];
}

int main()
{

	return 0;
}