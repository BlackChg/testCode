#include<stdio.h>
#include<stdlib.h>

//����һ�����Ǯ��ĸ��һ������Ǯ��С������һ��Ǯ������Ҫ��һ�ٿ�Ǯ��һ��ֻ�����ʹ�����ĸ����С��������ֻ��
//int BuyChicken(int price, int num)
//{
//    int total = 0;
//    for (int x = 0; x < num / 5; ++x)
//    {
//        for (int y = 0; y < num / 3; ++y)
//        {
//            int z = num - x - y;
//            //15*x + 9*y + z = 3*price
//            if (14 * x + 8 * y == 2 * price)
//            {
//                ++total;
//                printf("������%d, ĸ����%d, С����%d, \n", x, y, z);
//            }
//        }
//    }
//    return total;
//}
//
//int main()
//{
//    int price = 100;
//    int num = 100;
//    int res = BuyChicken(price, num);
//    printf("��%d��Ǯ��%dֻ������%d�з���\n", price, num, res);
//    return 0;
//}

//��һ�����ӣ��ӳ������3������ÿ���¶���һ�����ӣ�С���ӳ����������º�ÿ��������һ������
//�������Ӷ���������ÿ���µ���������Ϊ���٣�
//size_t Rabbit(int count)
//{
//	if (count == 0)
//	{
//		return 0;
//	}
//	if (count == 1 || count == 2)
//	{
//		return 1;
//	}
//
//	int one = 1;
//	int two = 0;
//	int three = 0;
//	size_t total = 0;
//	while (--count)
//	{
//		three += two;
//		two = one;
//		one = three;
//	}
//	total = one + two + three;
//
//	return total;
//}
//
//int main()
//{
//	int count = 9;
//	size_t res = Rabbit(count);
//	printf("%d���¹����Բ�%u������\n", count, res);
//
//	return 0;
//}

size_t Rabbit(int count)
{
	if (count == 1 || count == 2)
	{
		return 1;
	}
	return Rabbit(count - 1) + Rabbit(count - 2);
}

int main()
{
	int count = 40;
	size_t res = Rabbit(count);
	printf("%d���¹����Բ�%u������\n", count, res);

	return 0;
}