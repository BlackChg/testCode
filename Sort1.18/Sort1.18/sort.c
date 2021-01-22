#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

void Swap(int* arr, int pos1, int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

void ShiftDown(int* arr, int size, int parent)
{
	int child = 2 * parent + 1;
	
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] > arr[child])
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			int tmp = arr[parent];
			arr[parent] = arr[child];
			arr[child] = tmp;

			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}

}

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
		while (end >=0 && arr[end] > data)
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

//ϣ������
void ShellSort(int* arr, int size)
{
	int gap = size;
	while (gap > 0)
	{
		gap = gap / 2;
		//���һ�����򣬼��������1����֤������Ч������ͬһ��
		for (int i = gap; i < size; ++i)
		{
			//ͬһ�����ݣ����һ���������ݵ�λ��
			int end = i - gap;
			//����������
			int data = arr[i];
			while (end >= 0 && arr[end] > data)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}

//ѡ������
void SelectSort(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		int minIdx = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;
			}
		}
		if (minIdx != i)
		{
			Swap(arr, i, minIdx);
		}
	}
}

//�Ż�ѡ������
void SelectSort2(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		int minIdx = i;
		int maxIdx = i;
		int end = size - 1;
		for (int j = i + 1; j <= end; ++j)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;
			}
			if (arr[j] > arr[maxIdx])
			{
				maxIdx = j;
			}
		}

		Swap(arr, i, minIdx);
		if (maxIdx == i)
		{
			maxIdx = minIdx;
		}
		Swap(arr, end--,maxIdx);
	}
}

//������
void HeapSort(int* arr, int size)
{
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		ShiftDown(arr, size, i);
	}

	int end = size - 1;
	while (end > 0)
	{
		Swap(arr, 0, end);
		ShiftDown(arr, end, 0);
		--end;
	}
}

void BubbleSort(int* arr, int size)
{
	int n = size - 1;
	//���ڼ�¼ÿ��ð����󽻻���λ�ã��Ż���
	int pos = 0;

	for (int i = 0; i < size; ++i)
	{
		//���ڱ�Ǹ���ð���Ƿ������ݽ���
		bool flag = false;
		for (int j = 0; j < n; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr, j, j + 1);
				flag = true;
				//���һ�ν���λ�ã�����ð��ʱ����Ͳ��ñ����ˡ�
				pos = j;
			}
		}
		if (flag != true)
		{
			//Ԫ��δ������˵���������˳�
			break;
		}
		n = pos;
	}
}

//��ȡ��׼ֵ������ȡ�з�����ʼ�� �м䣬 ����
int GetMid(int* arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin;
	}
	else
	{
		if (arr[mid] < arr[end])
			return mid;
		else if (arr[begin] < arr[end])
			return end;
		else
			return begin;
	}
}

//hoare�汾
int Partion(int* arr, int begin, int end)
{
	//��ȡ��׼ֵ��λ��
	int mid = GetMid(arr, begin, end);
	//�ѻ�׼ֵ�ŵ���ʼλ��
	Swap(arr, begin, mid);
	int key = arr[begin];
	int start = begin;

	while (begin < end)
	{
		//�Ӻ���ǰ����С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key)
		{
			--end;
		}
		//��ǰ������Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key)
		{
			++begin;
		}
		Swap(arr, begin, end);
	}
	//��������λ�õ����ݺͻ�׼ֵ
	Swap(arr, start, begin);
	return begin;
}

//�ڿӷ�
int Partion2(int* arr, int begin, int end)
{
	//��ȡ��׼ֵ��λ��
	int mid = GetMid(arr, begin, end);
	//�ѻ�׼ֵ�ŵ���ʼλ��
	Swap(arr, begin, mid);
	int key = arr[begin];
	while (begin < end)
	{
		//�Ӻ���ǰ����С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key)
		{
			--end;
		}
		arr[begin] = arr[end];
		//��ǰ������Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key)
		{
			++begin;
		}
		arr[end] = arr[begin];
	}
	//����λ�ô�Ż�׼ֵ
	arr[begin] = key;
	return begin;
}

//ǰ��ָ�뷨
int Partion3(int* arr, int begin, int end)
{
	//��ȡ��׼ֵ��λ��
	int mid = GetMid(arr, begin, end);
	//�ѻ�׼ֵ�ŵ���ʼλ��
	Swap(arr, begin, mid);
	int key = arr[begin];
	int prev = begin;
	int cur = begin + 1;
	
	while (cur <= end)
	{
		if (arr[cur] < key && ++prev != cur)
		{
			//������ ��������
			Swap(arr, prev, cur);
		}

		++cur;
	}
	Swap(arr, begin, prev);
	return prev;
}

//��������ʱ��û���Ż����ܻᵼ��ջ����������Ż��������һ�׼ֵ��
void QuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div:һ�λ���֮�󣬻�׼ֵ��λ��
	int div = Partion3(arr, begin, end);
	//���������ֽ��п�������
	QuickSort(arr, begin, div - 1);
	QuickSort(arr, div + 1, end);
}

//�ǵݹ���� ,����ջ�������
void QuickSortNor(int* arr, int begin, int end)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, end);
	StackPush(&st, 0);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);

		int div = Partion(arr, left, right);

		//[left, div - 1]
		if (left < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, left);
		}
		//[div + 1, right]
		if (div + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, div + 1);
		}

	}
}

//�ϲ����к���
void Merge(int* arr, int begin, int mid, int end, int* tmp)
{
	//����1[begin, mid]
	int begin1 = begin;
	int end1 = mid;
	//����2[mid+1, end]
	int begin2 = mid + 1;
	int end2 = end;

	//�����ռ����ʼλ��
	int idx = begin;

	//�ϲ���������
	while (begin1 <= end1 && begin2 <= end2)
	{
		//˭С˭�Ƚ�
		if (arr[begin1] <= arr[begin2])
		{
			tmp[idx++] = arr[begin1++];
		}
		else
		{
			tmp[idx++] = arr[begin2++];
		}
	}

	//�ж��Ƿ���δ�ϲ���Ԫ�أ��оͽ�ʣ��Ԫ��ȫ������
	if (begin1 <= begin1)
	{
		memcpy(tmp + idx, arr + begin1, sizeof(int) * (end1 - begin1 + 1));
	}
	if (begin2 <= begin2)
	{
		memcpy(tmp + idx, arr + begin2, sizeof(int) * (end2 - begin2 + 1));
	}

	//�ϲ�֮������п���ԭʼ����Ķ�Ӧ����
	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void _MergeSort(int* arr, int begin, int end, int* tmp)
{
	//����Ԫ���Ѿ����򣬲�������
	if (begin >= end)
		return;
	//����м�����
	int mid = begin + (end - begin) / 2;

	//���Ⱥϲ�������
	//���[begin, mid]
	_MergeSort(arr, begin, mid, tmp);
	//�ұ�[mid+1,end]
	_MergeSort(arr, mid + 1, end, tmp);

	//�ϲ����������������[begin, mid]  [mid + 1, end]
	Merge(arr, begin, mid, end, tmp);
}

//�鲢����
void MergeSort(int* arr, int n)
{
	//���븨���ռ�
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}

void MergeSortNoR(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	//����������septΪһ�������
	int step = 1;
	while (step < n)
	{
		//����ÿһ�������
		for (int idx = 0; idx < n; idx += 2 * step)
		{
			//�����������ϲ�������������
			//[begin, mid]  [mid + 1, end]
			int begin = idx;
			int mid = idx + step - 1;
			//�ж��Ƿ���ڵڶ�������
			if (mid >= n - 1)
			{
				//�����ڵڶ��������У�ֱ������
				continue;
			}
			int end = idx + 2 * step - 1;
			//�жϵڶ����������Ƿ�Խ��
			if (end >= n)
			{
				end = n - 1;
			}

			//�ϲ�
			Merge(arr, begin, mid, end, tmp);
		}

		//���²���
		step *= 2;
	}
}

void CountSort(int* arr, int size)
{
	//�ҵ�������Сֵ
	int max, min;
	min = max = arr[0];
	
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	int range = max - min + 1;
	int* countArr = (int*)calloc(range, sizeof(int));

	for (int i = 0; i < size; ++i)
	{
		countArr[arr[i] - min]++;
	}

	int idx = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
		{
			arr[idx++] = i + min;
		}
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

void TestInsertSort()
{
	int arr[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int size = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, size);
	PrintArr(arr, size);
}

void TestShellSort()
{
	int arr[] = { 8, 9, 1, 7, 2, 3, 5, 4, 6, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, size);
	PrintArr(arr, size);
}

void TestSelectSort()
{
	int arr[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int size = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, size);
	PrintArr(arr, size);
}

void TestHeapSort()
{
	int arr[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);
	PrintArr(arr, size);
}

void TestBubbleSort()
{
	int arr[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, size);
	PrintArr(arr, size);
}

void TestQuickSort()
{
	int arr[] = { 4, 1, 3, 7, 9, 2, 6, 5, 10, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, size - 1);
	PrintArr(arr, size);
}

void TestQuickSortNor()
{
	int arr[] = { 4, 1, 3, 7, 9, 2, 6, 5, 10, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	QuickSortNor(arr, 0, size - 1);
	PrintArr(arr, size);
}

void TestMergeSort()
{
	int arr[] = { 3, 2, 6, 8, 1, 4, 9, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, size);
	PrintArr(arr, size);
}

void TestMergeSortNoR()
{
	int arr[] = { 3, 2, 6, 8, 1, 4, 9, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	MergeSortNoR(arr, size);
	PrintArr(arr, size);
}

void TestCountSort()
{
	int arr[] = { 2, 5, 3, 5, 6, 3, 2, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	CountSort(arr, size);
	PrintArr(arr, size);
}

void Test()
{
	int n = 0;
	printf("�������� ");
	scanf("%d", &n);

	srand((unsigned)time(NULL));
	int* src = (int*)malloc(sizeof(int) * n);
	int* dest1 = (int*)malloc(sizeof(int) * n);
	int* dest2 = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		src[i] = rand();
	}
	memcpy(dest1, src, sizeof(int) * n);
	memcpy(dest2, src, sizeof(int) * n);

	time_t begin = clock();
	InsertSort(dest1, n);
	time_t end = clock();
	printf("InsertSort��%lld\n", end - begin);

	begin = clock();
	ShellSort(dest2, n);
	end = clock();
	printf("ShellSort��%lld\n", end - begin);
}

int main()
{
	//TestInsertSort();
	//TestShellSort();
	//Test();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	//TestQuickSort();
	//TestQuickSortNor();
	//TestMergeSort();
	//TestMergeSortNoR();
	TestCountSort();
	return 0;
}