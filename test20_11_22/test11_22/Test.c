#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>

//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�

/*
int main()
{

	for (int A = 1; A <= 5; A++)
	{
		for (int B = 1; B<= 5; B++)
		{
			for (int C = 1; C <= 5; C++)
			{
				for (int D = 1; D <= 5; D++)
				{
					for (int E = 1; E <= 5; E++)
					{
						if (A*B*C*D*E==120)
						{
							if (((A == 3) + (B == 2) == 1) &&
								((E == 4) + (B == 2) == 1) &&
								((D == 2) + (C == 1) == 1) &&
								((C == 5) + (D == 3) == 1) &&
								((E == 4) + (A == 1) == 1))
							{
								printf("����ΪA:%d B:%d C:%d D:%d E:%d\n", A, B, C, D, E);
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
*/

//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ��� :
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�

/*
int main()
{
	for (char k='A' ; k <= 'D'; k++)
	{
		int A = (k!= 'A') ? 1 : 0;
		int B = (k== 'C') ? 1 : 0;
		int C = (k== 'D') ? 1 : 0;
		int D = (k!= 'D') ? 1 : 0;

		if ((A + B + C + D) == 3)
		{
			printf("ɱ���ǣ� %C\n", k);
		}
	}
}
*/

/*�������
#define ROW 10
#define COL 10
int main()
{
	int arr[ROW][COL] = { 0 };
	int size = sizeof(arr) / sizeof(int);
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j <=i; j++)
		{
			if (j == 0 || j == i)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/


/*255
int main()
{
	char a[1000] = { 0 };
	int i = 0;
	for (i = 0; i<1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));
	return 0;
}
*/


/*ģ��ʵ��memmove
void *my_memmove(const void* dest, const void *src, size_t count)
{
	assert(dest != NULL&&src != NULL);
	char *pdest = (char *)dest;
	const char *psrc = (const char*)src;

	if (pdest>psrc&&pdest<(psrc+count))
	{
		psrc = psrc + count - 1;
		pdest = pdest + count - 1;
		while (count-- > 0)
		{
			*pdest-- = *psrc--;
		}
	}
	else
	{
		while (count-- > 0)
		{
			*pdest++ = *psrc++;
		}
	}
	return dest;
}

int main()
{
	char str[20] = "helloworld";
	int count = 4;
	my_memmove(str + 2, str, count);
	printf("%s\n", str);

	return 0;
}
*/


/*ģ��ʵ��memcpy
void *my_memcpy(const void *dest, const void *src,size_t count)
{
	assert(dest != NULL&&src != NULL);
	char*pdest = (char*)dest;
	const char*psrc = (const char*)src;

	while (count-- > 0)
	{
		*pdest++ = *psrc++;
	}
	return dest;
}

int main()
{
	char dest[20] = {0};
	char *src = "hello world";
	int count = 3;
	my_memcpy(dest, src,count);
	printf("%s\n", dest);

	return 0;
}
*/


/*
void main()
{
	union
	{
		short k;
		char i[2];
	}*s,a;

	s = &a;
	s->i[0] = 0x39;
	s->i[1] = 0x38;

	printf("%x\n", a.k); //3839
}
*/


/*�жϼ���ʽ�洢�Ǵ�˻���С��
int check_sys()
{
	int i = 1;
	return (*(char *)&i);
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}
*/


/*ģ��ʵ��strstr
char *my_strstr(const char *str, const char *str2)
{
	assert(str != NULL && str2 != NULL);
	char *pstr = str;
	char *p = pstr;
	char *pstr2 = str2;
	

	while (*p!='\0')
	{
		pstr = p;
		pstr2 = str2;

		while ((*pstr != '\0') && (*pstr2 != '\0') && *pstr == *pstr2)
		{
			pstr++;
			pstr2++;
		}

		if (*pstr2 == '\0')
		{
			return p;
		}
		p++;

	}
	return NULL;

}

int main()
{
	char str[20] = "abcdefgh";

	char *p;
	p= my_strstr(str, "def");

	printf("str3 = %s\n", p);

	return 0;
}
*/


/*ģ��ʵ��strcat
char *my_strcat(char *dest, const char *src)
{
	assert(dest != NULL && src != NULL);

	char *pdest = dest;
	char *psrc = src;

	while (*pdest != '\0')
	{
		pdest++;
	}
	while (*psrc != '\0')
	{
		*pdest++ = *psrc++;
	}
	*pdest = '\0';

	return dest;
}

int main()
{
	char dest[20] = "abc";
	char *src = "defg";
	printf("dest = %s\n", dest);
	my_strcat(dest, src);
	printf("dest = %s\n", dest);
	return 0;
}
*/


/* ģ��ʵ��strcmp
int my_strcmp(const char *str, const char *str2)
{
	assert(str != NULL && str2 != NULL);
	char *pstr = str;
	char *pstr2 = str2;

	while (*pstr != '\0' || *pstr2 != '\0')
	{
		if (*pstr - *pstr2 != 0)
			break;
		pstr++;
		pstr2++;
	}

	return (*pstr - *pstr2);

}

int main()
{
	char *str = "abcde";
	char *str2 = "abcdef";
	int ret = my_strcmp(str, str2);
	if (ret > 0)
	{
		printf("str > str2");
	}
	else if (ret < 0)
	{
		printf("str < str2");
	}
	else
	{
		printf("str = str2");
	}

	return 0;
}
*/


/*ģ��ʵ��strcpy
char *my_strcpy(char *dest, const char *src)
{
	assert(dest != NULL && src!=NULL);

	char *pdest = dest;
	char *psrc = src;

	while (*psrc != '\0')
	{
		*pdest++ = *psrc++;
	}
	*pdest = '\0';
	return dest;
}

int main()
{
	char dest[20] = "abc";
	char *src = "defg";
	printf("dest = %s\n", dest);
	my_strcpy(dest, src);
	printf("dest = %s\n", dest);
	return 0;
}
*/


/* ģ��ʵ��strlen
int my_strlen(const char *str)
{
	assert(str != NULL);
	int len=0;
	char *pstr = str;

	while (*pstr != '\0')
	{
		pstr++;
		len++;
	}
	return len;
}

int main()
{
	char *str = "abcdefg";

	int size = my_strlen(str);
	printf("%d \n", size);

	return 0;
}
*/