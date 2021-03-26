#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;

//class String
//{
//public:
//
//	String(const char* str = "")
//	{
//		//str����Ϊ��
//		assert(str != nullptr);
//		//����һ���봫����ַ����ĳ��� + 1�Ŀռ� +1�Ǳ��� \0
//		_str = new char[strlen(str) + 1];
//		//��������ַ������ݿ�������ǰ���������
//		strcpy(_str, str);
//	}
//
//	String(const String& s)
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			delete[] _str;
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//		return *this;
//	}
//
//	~String()
//	{
//		if (_str != nullptr)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//	const char* c_str() const 
//	{
//		return _str;
//	}
//private:
//	char* _str;
//};

//class String
//{
//public:
//
//	String(const char* str = "")
//	{
//		//str����Ϊ��
//		assert(str != nullptr);
//		//����һ���봫����ַ����ĳ��� + 1�Ŀռ� +1�Ǳ��� \0
//		_str = new char[strlen(str) + 1];
//		//��������ַ������ݿ�������ǰ���������
//		strcpy(_str, str);
//	}
//
//	String(const String& s)
//		:_str(nullptr)
//	{
//		String tmp(s._str);
//		swap(_str, tmp._str);
//	}
//
//	String& operator=(String s)
//	{
//		if (this != &s)
//		{
//			swap(_str, s._str);
//		}
//		return *this;
//	}
//
//	~String()
//	{
//		if (_str != nullptr)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//	const char* c_str() const
//	{
//		return _str;
//	}
//private:
//	char* _str;
//};

class String
{
public:
	//������
	typedef char* iterator;
	//const����ȥ
	typedef const char* const_iterator;

	iterator begin()
	{
		//��һ��Ԫ�ص�λ��
		return _str;
	}

	iterator end()
	{
		//���һ��Ԫ�ص���һ��λ��
		return _str + _size;
	}

	const_iterator begin() const
	{
		//��һ��Ԫ�ص�λ��
		return _str;
	}

	const_iterator end() const 
	{
		//���һ��Ԫ�ص���һ��λ��
		return _str + _size;
	}

	String(const char* str = "")
	{
		assert(str != nullptr);
		_size = strlen(str);
		_str = new char[_size + 1];
		_capacity = _size;
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(nullptr)
		,_size(0)
		,_capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);
	}

	//�Լ�ʵ��һ���������������������������������
	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}

	String& operator=(String s)
	{
		if (this != &s)
		{
			Swap(s);
		}
		return *this;
	}

	~String()
	{
		if (_str != nullptr)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

	const char* c_str() const
	{
		return _str;
	}

	size_t size() const
	{
		return _size;
	}

	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}

	const char& operator[](size_t pos) const 
	{
		assert(pos < _size);
		return _str[pos];
	}



	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//����ռ� 
			char* tmp = new char[n + 1];
			//����ԭ��������
			strcpy(tmp, _str);
			//�ͷ�ԭ�пռ�
			delete[] _str;
			//���������������¸�ֵ��_str
			_str = tmp;
			//����������С
			_capacity = n;
		}
	}

	void push_back(const char& ch)
	{
		//���ռ�
		if (_size == _capacity)
		{
			size_t newCapcity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newCapcity);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
	}

	void resize(size_t n, const char& ch = '\0')
	{
		//3��n > capacity ����
		if (n > _capacity)
		{
			reserve(n);
		}
		//2��_size < n <= capacity  ���ch
		if (n > _size)
		memset(_str + _size, ch, (n - _size) * sizeof(char));

		//1��n < size
		_size = n;
		_str[_size] = '\0';
	}

	void append(const char* str)
	{
		//�������
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}

		//β��
		memcpy(_str + _size, str, sizeof(char) * len);

		//����
		_size += len;
		_str[_size] = '\0';
	}

	String& operator+=(const String& str)
	{
		append(str._str);
		return *this;
	}
	String& operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	String& operator+=(const char ch)
	{
		push_back(ch);
		return *this;
	}

	void insert(size_t pos, const char& ch)
	{
		//���λ����Ч��
		assert(pos <= _size);
		//�������
		if (_size == _capacity)
		{
			size_t  newCapacity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newCapacity);
		}

		//�ƶ�Ԫ�أ��Ӻ���ǰ��
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		//������Ԫ�ز�������Ч�ַ�����
		_str[pos] = ch;
		++_size;
	}

	void insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		int len = strlen(str);
		if (_size + len >= _capacity)
		{
			reserve(_size + len);
		}
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}
		memcpy(_str + pos, str, sizeof(char) * len);
		_size += len;
	}

	void erase(size_t pos, size_t len)
	{
		//���λ����Ч��
		assert(pos < _size);
		//Ҫɾ���ĸ�������ʣ�µ��ַ�����
		if (pos + len >= _size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			//�ƶ�Ԫ�أ���ǰ����ƶ�
			size_t start = pos + len;
			while (start <= _size)
			{
				_str[pos++] = _str[start];
				++start;
			}
			_size -= len;
		}
	}

	size_t find(const char& ch, size_t pos = 0)
	{
		//���λ�õ���Ч��
		assert(pos < _size);
		
		for (size_t i = pos; i < _size; ++i)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}

	size_t find(const char* str, size_t pos = 0)
	{
		//����ֵ��
		//NULL��δ�ҵ�
		//��Ч��ַ���Ӵ����ֵ��׵�ַ
		char* ptr = strstr(_str, str);
		if (ptr != NULL)
		{
			return ptr - _str;
		}
		return npos;
	}

private:
	char* _str;
	size_t _size;
	size_t _capacity;
	static const size_t npos;
};

const size_t String::npos = -1;

String operator+(const String& str1, const String& str2)
{
	String tmp = str1;
	tmp += str2;
	return tmp;
}
String operator+(const String& str1, const char* str2)
{
	String tmp = str1;
	tmp += str2;
	return tmp;
}
String operator+(const char& ch, const String& str1)
{
	String tmp = str1;
	tmp += ch;
	return tmp;
}

ostream& operator<<(ostream& out, const String& str)
{
	for (const auto& ch : str)
	{
		cout << ch;
	}
	return out;
}

istream& operator>>(istream& in, String& str)
{
	char ch;
	while (ch = getchar())
	{
		if (ch == ' ' || ch == '\n' || ch == '\t')
		{
			break;
		}
		str += ch;
	}

	return in;
}

bool operator==(const String& str1, const String& str2)
{
	int res =  strcmp(str1.c_str(), str2.c_str());
	if (res == 0)
		return true;
	else
		return false;
}

bool operator==(const String& str1, const char*& str)
{
	int res = strcmp(str1.c_str(),str);
	if (res == 0)
		return true;
	else
		return false;
}

bool operator!=(const String& str1, const String& str2)
{
	return !(str1 == str2);
}

bool operator!=(const String& str1, const char*& str)
{
	return !(str1 == str);
}

void test()
{
	String str1 = "White";
	String str2 = "white";
	cout << (str1 != str2) << endl;
	cout << (str1 == "White") << endl;
}

int main()
{
	test();

	return 0;
}