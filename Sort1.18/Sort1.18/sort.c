#include <stdio.h>

//��������
void InsertSort(int* arr, int size)
{
	//������  �� ֻ��һ��Ԫ�ص�����
	if (arr == NULL || size == 1)
	{
		return;
	}

	//����δ�����Ԫ��
	for (int i = 1; i < size; ++i)
	{
		//����δ���򲿷ֵĵ�һ��Ԫ��
		int data = arr[i];
		//����������һ��Ԫ�ص�����
		int end= i - 1;
		while (end >=0 && arr[end] >= data)
		{
			//ǰ��Ԫ�ظ��Ǻ���Ԫ��
			arr[end + 1] = arr[end];
			//��ǰ����
			--end;
		}
		//�ҵ�λ�ò��ڸ�λ�õ���һ��λ�ò���
		arr[end + 1] = data;
	}
}

void PrintArr(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int size = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, size);
	PrintArr(arr, size);

	return 0;
}