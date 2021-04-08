#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//����ʽ
class Singleton
{
public:
	static Singleton* getSingleton()
	{
		if (_singleton == nullptr)
		{
			_mutex.lock();
			if (_singleton == nullptr)
			{
				_singleton = new Singleton();
			}
			_mutex.unlock();
		}
		return _singleton;
	}

	class Deletor
	{
	public:
		~Deletor()
		{
			if (Singleton::_singleton != nullptr)
			{
				delete Singleton::_singleton;
				Singleton::_singleton = nullptr;
			}
		}
	};
	//�����ͷŵ�������
	static Deletor _deletor;
private:
	Singleton() {};
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	static mutex _mutex;//������
	static Singleton* _singleton;
};
Singleton* Singleton::_singleton = nullptr;
mutex Singleton::_mutex;
Singleton::Deletor _deletor;

//����ʽ
//class Singleton
//{
//public:
//	//��ȡΨһʵ���ľ�̬����
//	static Singleton* getSingleton()
//	{
//		return &_singleton;
//	}
//
//private:
//	//˽�й���
//	Singleton() {};
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//	
//	static Singleton _singleton;
//};
//
////�ڳ������֮ǰ����ɵ�������ĳ�ʼ��
//Singleton Singleton::_singleton; 

int main()
{
	return 0;
}