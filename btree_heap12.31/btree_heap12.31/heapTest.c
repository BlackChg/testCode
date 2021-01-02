#include<stdio.h>
#include<stdlib.h>
typedef int HDataType;

typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;

void HeapInit(heap* hp)
{
	if (hp == NULL)
		return;
	hp->_data = NULL;
	hp->_capacity = hp->_size = 0;
}

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

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//logn
void SShiftUp(int* arr, int n, int cur)
{
	while (cur > 0)
	{
		//���ڵ��λ��
		int parent = (cur - 1) / 2;

		//�͸������бȽ�
		if (arr[cur] < arr[parent])
		{
			//����
			Swap(&arr[cur], &arr[parent]);

			//���µ����ڵ㲢����ִ�����ϵ����㷨
			cur = parent;
		}
		else
		{
			break;
		}
	}
}

void CheckCapacity(heap* hp)
{
	if (hp->_size == hp->_capacity)
	{
		int newCapacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType) * newCapacity);
	}
}

//�ѵĲ���
void HeapPush(heap* hp, HDataType val)
{
	//�������
	CheckCapacity(hp);
	//β��
	hp->_data[hp->_size++] = val;
	//���ϵ���
	SShiftUp(hp->_data, hp->_size, hp->_size - 1);
}

//�ѵ�ɾ��(�Ѷ�Ԫ��)
void HeapPop(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return;
	//����
	Swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
	hp->_size--;
	//���µ���
	SShiftDown(hp->_data, hp->_size, 0);
}

int HeapEmpty(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

HDataType HeapTop(heap* hp)
{
	return hp->_data[0];
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


void HeapSort()
{
	int arr[] = { 56, 12, 58, 87, 45, 36, 13 };
	int size = sizeof(arr) / sizeof(arr[0]);

	//����
	CreatSmallHeap(arr, size);

	//�ѵ����һ��Ԫ��
	int end = size - 1;
	//ѭ���������µ���
	for (int i = 0; i < size; ++i) //n
	{
		Swap(&arr[0], &arr[end]);
		SShiftDown(arr, end, 0); //logn
		--end;
	} //�������ʱ�临�Ӷ�nlogn

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//void test()
//{
//	heap hp;
//	HeapInit(&hp);
//	HeapPush(&hp, 28);
//	HeapPush(&hp, 29);
//	HeapPush(&hp, 45);
//	HeapPush(&hp, 46);
//	HeapPush(&hp, 25);
//	HeapPush(&hp, 38);
//	HeapPush(&hp, 19);
//	HeapPush(&hp, 8);
//
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//	//HeapPop(&hp);
//
//	while (!HeapEmpty(&hp))
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	printf("\n");
//}

//void test()
//{ 
//	int arr[] = { 10, 5, 3, 8, 7, 6 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	SShiftDown(arr, size, 0);
//}

int main()
{
	HeapSort();

	return 0;
}


