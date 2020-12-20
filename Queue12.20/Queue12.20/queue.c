#include"queue.h"

// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = NULL;
}

// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newNode);
	newNode->_data = data;
	newNode->_next = NULL;

	if (q->_back == NULL)
	{
		q->_front = q->_back = newNode;
	}
	else
	{
		q->_back->_next = newNode;
		q->_back = newNode;
	}
}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front->_next == NULL)
	{
		free(q->_front);
		q->_front = q->_back = NULL;
	}
	else
	{
		QueueNode* second = q->_front->_next;
		free(q->_front);
		q->_front = second;
	}
	
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_back->_data;
}
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	int count = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		++count;
		cur = cur->_next;
	}
	return count;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	return q->_front == NULL ? 1 : 0;
}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_back = q->_front = NULL;
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	QueueDestroy(&q);
}

int main()
{

	TestQueue();
	return 0;
}