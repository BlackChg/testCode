#include <cstdio>

int main()
{
	int a[5] = { 1,3,5,7,9 };
	int* p = (int*)(&a + 1);
	printf("%d, %d", *(a + 1),*(p - 1));
}