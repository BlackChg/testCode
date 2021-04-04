#include <iostream>
#include <algorithm>
#include <string>
#include <assert.h>
using namespace std;

template<class T>
class Vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	//�޲�Ĭ�Ϲ���
	Vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_endOfStorage(nullptr)
	{}

	//n��val�Ĺ��캯��
	Vector(int n, const T& val = T())
		:_start(new T[n])
		,_finish(_start +n)
		,_endOfStorage(_finish)
	{
		for (int i = 0; i < n; ++i)
		{
			_start[i] = val;
		}
	}

	//ͨ�������������Ĺ��캯��
	template<class InputIterator>
	Vector(InputIterator first, InputIterator last)
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{
		while (first != last)
		{
			pushBack(*first);
			++first;
		}
	}

	void pushBack(const T& val)
	{
		//�������
		if (_finish == _endOfStorage)
		{
			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);
		}

		//��������
		*_finish = val;
		//����finish
		++_finish;
	}

	void reserve(size_t n)
	{
		//reserveֻ������ռ䲻����С�ռ�
		if (n > capacity())
		{
			//������ЧԪ��
			size_t sz = size();
			//����ռ�
			T* tmp = new T[n];
			//�����ݿ������µĿռ�
			if (_start != nullptr)
			{
				//������ЧԪ��
				//memcpy(tmp, _start, sizeof(T) * size());
				//���
				for (size_t i = 0; i < sz; ++i)
				{
					//�����Զ������͵ĸ�ֵ��������غ�����������
					//ǰ���Ǹ����غ���Ҳ�������string��STL���У��Ǳ���������
					tmp[i] = _start[i];
				}
				delete[] _start;
			}
			//����
			_start = tmp;
			_finish = _start + sz;
			_endOfStorage = _start + n;
		}
	}

	T& operator[](size_t pos)
	{
		assert(pos < size());
		return _start[pos];
	}

	const T& operator[](size_t pos) const
	{
		assert(pos < size());
		return _start[pos];
	}

	void resize(size_t n, const T& val = T())
	{
		//3.n >= capacity
		if (n > capacity())
		{
			reserve(n);
		}
		//2.size < n <= capacity
		if (n > size())
		{
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
		//1.n<=size
		_finish = _start + n;
	}

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	size_t size() const
	{
		return _finish - _start;
	}

	size_t capacity() const
	{
		return _endOfStorage - _start;
	}

	void insert(iterator pos, const T& val)
	{
		//���λ����Ч��
		assert(pos >= _start || pos < _finish);
		//�������
		if (_finish == _endOfStorage)
		{
			//���ݻᵼ�µ�����ʧЧ
			//����pos��_start��ƫ����
			size_t offset = pos - _start;
			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);
			//����pos
			pos = _start + offset;
		}
		//�ƶ�Ԫ��
		iterator end = _finish;
		while (end != pos)
		{
			*end = *(end - 1);
			--end;
		}
		//����
		*pos = val;
		//����
		++_finish;
	}

	iterator erase(iterator pos)
	{
		//���λ����Ч��
		assert(pos >= _start || pos < _finish);
		//�ƶ�Ԫ�أ���ǰ����
		iterator start = pos + 1;

		while (start != _finish)
		{
			*(start - 1) = *start;
			++start;
		}
		//����
		--_finish;
		return pos;
	}

	void popBack()
	{
		if (size() > 0)
			erase(end() - 1);
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	}

private:
	iterator _start;
	iterator _finish;
	iterator _endOfStorage;
};

template<class T>
void printVector(Vector<T>& vec)
{
	typename Vector<T>::iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}

template<class T>
void printVectorFor(Vector<T>& vec)
{
	for ( auto& e : vec)
	{
		cout << e;
	}
	cout << endl;
}

template<class T>
void printOperator(Vector<T>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec[i];
	}
	cout << endl;
}

void test()
{
	Vector<string> v;
	string str1 = "123";
	string str2 = "456";
	string str3 = "789";
	v.pushBack(str1);
	v.pushBack(str2);
	v.pushBack(str3);
}

//void test()
//{
//	Vector<int> v;
//	v.pushBack(1);
//	v.pushBack(2);
//	v.pushBack(3);
//	v.pushBack(4);
//	v.pushBack(5); //12345
//	v.erase(v.begin());//2345
//	v.erase(v.begin() + 1);//245
//	v.erase(v.end() - 1);//24
//	printOperator(v);
//}

//void test()
//{
//	Vector<int> v;
//	v.pushBack(2);
//	v.pushBack(3);
//	v.pushBack(5);
//	v.pushBack(6);//2 3 5 6
//	v.insert(v.begin(), 1);//1 2 3 5 6
//	v.insert(v.begin() + 3, 4);// 1 2 3 4 5 6
//	v.insert(v.end(), 7); // 1 2 3 4 5 6 7
//	printOperator(v);
//}

//void test()
//{
//	string str = "nihaoya";
//	Vector<char> v(str.begin(), str.end());
//	printVectorFor(v);
//	Vector<char>v1(5, 'c');
//	printVectorFor(v1);
//}

//void test()
//{
//	Vector<int> v1;
//	v1.pushBack(1);
//	v1.pushBack(2);
//	v1.pushBack(3);
//	v1.pushBack(4);
//	v1.pushBack(5);
//	cout << v1.size() << endl; // 5
//	cout << v1.capacity() << endl;// 8
//	v1.resize(3); //1 2 3
//	cout << v1.size() << endl;// 3
//	cout << v1.capacity() << endl;//8
//	v1.resize(4, 10); // 1 2 3 10
//	cout << v1.size() << endl;//4
//	cout << v1.capacity() << endl;//8
//	v1.resize(10, 20);// 1 2 3 10 20 20 20 20 20 20
//	cout << v1.size() << endl;//10
//	cout << v1.capacity() << endl;//10
//}

int main()
{
	test();

	return 0;
}