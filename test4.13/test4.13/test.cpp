#include<stdio.h>
int main()
{
    while (1)
    {
        int x, y, z = 0;
        char c;
        printf("��ʽΪ���������������\n");
        printf("�����룺");
        scanf_s("%d%c%d", &x, &c, &y);//��vs2017�������ַ��ͱ�����Ҫ���峤�ȷ������
        switch (c)
        {
        case '+':
            z = x + y;
            break;
        case '-':
            z = x - y;
            break;
        case '*':
            z = x * y;
            break;
        case '/':
            z = x / y;
            break;
        default:
            printf("erro!");
            break;
        }
        printf("%d\n", z);
    }
    
    return 0;
}