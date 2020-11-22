#include<stdio.h>
#include<malloc.h>


#define LOW 3
#define COL 3

int* spiralOrder(int (*arr)[COL], int* returnSize){

	//��������ĸ�����Ҳ�����б�ĳ���
	*returnSize = COL*LOW;

	int* val = (int*)malloc(sizeof(int)*(*returnSize));
	//�ֱ��� �� �� �� �� �ı߽� 
	int l = 0, r = COL - 1, t = 0, b = LOW - 1, x = 0;

	while (1)
	{
		// left to right.
		for (int i = l; i <= r; i++)	//�����ң�i�͵�����i<=��
		{
			val[x++] = arr[t][i]; //������һ��������仯�����У������б�=i
		}

		if (++t > b) break;	//����Ҫ�ߵ��Ǵ��ϵ��£��������ж��ϱ߽�+1�Ƿ���±߽�������˵���Ѿ���ӡ��ȫ��
		// top to bottom.
		for (int i = t; i <= b; i++)	//���ϵ��£�i�͵����ϣ�i<=��
		{
			val[x++] = arr[i][r]; //������һ��������仯�����У������б�=i
		}

		if (l > --r) break;	//����Ҫ�ߵ��Ǵ��ҵ����������ж���߽��Ƿ���ұ߽�-1�������˵���Ѿ���ӡ��ȫ��
		// right to left.
		for (int i = r; i >= l; i--)	//���ҵ���i�͵����ң�i>=��
		{
			val[x++] = arr[b][i];	//�����һ�����,�仯�����б�,�����б�=i
		}

		if (t > --b) break;	//����Ҫ�ߵ��Ǵ��µ��ϣ��������ж��ϱ߽��Ƿ���±߽�-1�������˵���Ѿ���ӡ��ȫ��
		// bottom to top.
		for (int i = b; i >= t; i--)	//���µ��ϣ�i�͵����£�i>=��
		{
			val[x++] = arr[i][l];	//������һ�����,�仯�����б�,�����б�=i
		}
		if (++l > r) break;	 //����Ҫ�ߵ��Ǵ����ң��������ж���߽�+1�Ƿ���ұ߽�������˵���Ѿ���ӡ��ȫ��
	}
	return val;
}

int main()
{
	//�����ά����
	int arr[][COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 

	//���ڽ���val���б�ĳ���
	int returnSize;

	//����arr2��������val���׵�ַ
	int *arr2 = spiralOrder(arr, &returnSize);

	//��ӡ�б�val
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");

	return 0;
}
