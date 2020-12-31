#include<stdio.h>

//����ΪС��
void SShiftDown(int* arr, int n, int curPos)
{
	//����
	int child = 2 * curPos + 1;
	
	while (child < n)
	{
		//�����Һ������ҵ�һ����Сֵ��λ��
		if ((child + 1 < n) && (arr[child + 1] < arr[child]))
		{
			//�Һ���
			++child;
		}
		//��Ҫ���������ݺ���Сֵ���бȽ�
		if (arr[child] < arr[curPos])
		{
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp; 

			curPos = child;
			child = 2 * curPos + 1;
		}
		else
		{
			break;
		}
	}
} 

//����Ϊ���
void BShiftDown(int* arr, int n, int curPos)
{
	//����
	int child = 2 * curPos + 1;

	while (child < n)
	{
		//�����Һ������ҵ�һ�����ֵ��λ��
		if ((child + 1 < n) && (arr[child + 1] > arr[child]))
		{
			//�Һ���
			++child;
		}
		//��Ҫ���������ݺ���� ֵ���бȽ�
		if (arr[child] > arr[curPos])
		{
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp;

			curPos = child;
			child = 2 * curPos + 1;
		}
		else
		{
			break;
		}
	}
}

void CreatSmallHeap(int* arr, int n)
{
	//�����һ����Ҷ�ӿ�ʼ���µ���
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		SShiftDown(arr, n, i);
	}
}

void CreaBigHeap(int* arr, int n)
{
	//�����һ����Ҷ�ӿ�ʼ���µ���
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		BShiftDown(arr, n, i);
	}
}

void test()
{
	int arr[] = { 56, 12, 58, 87, 45, 36, 12, 3, 99 };
	int size = sizeof(arr) / sizeof(arr[0]);
	CreatSmallHeap(arr, size);
	
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
}

//void test()
//{ 
//	int arr[] = { 10, 5, 3, 8, 7, 6 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	SShiftDown(arr, size, 0);
//}

int main()
{
	test();

	return 0;
}