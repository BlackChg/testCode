#include <iostream>
#include <string>
using namespace std;

//�����ֻ�
class AbstractPhone
{
public:
	virtual void ShowName() = 0;
};

//��Ϊ
class Huawei : public AbstractPhone
{
public:
	virtual void ShowName()
	{
		cout << "Huawe Phone" << endl;
	}
};

//С��
class Xiaomi : public AbstractPhone
{
public:
	virtual void ShowName()
	{
		cout << "Xiaomi Phone" << endl;
	}
};

//ƻ��
class Apple : public AbstractPhone
{
public:
	virtual void ShowName()
	{
		cout << "Apple Phone" << endl;
	}
};

//�ֻ�����
class PhoneFactory
{
public:
	static AbstractPhone* CreatePhone(string name)
	{
		if (name == "huawei")
			return new Huawei;
		else if (name == "xiaomi")
			return new Xiaomi;
		else if (name == "apple")
			return new Apple;
		else
			return nullptr;
	}
};

void test()
{
	//��������
	PhoneFactory* factor = new PhoneFactory;
	//�����ֻ�
	AbstractPhone* phone;
	//ָ��������Ҫ�������ֻ�
	phone = factor->CreatePhone("huawei");
	phone->ShowName();
	delete phone;

	phone = factor->CreatePhone("xiaomi");
	phone->ShowName();
	delete phone;

	phone = factor->CreatePhone("apple");
	phone->ShowName();
	delete phone;

	delete factor;
}

int main()
{
	test();
	return 0;
}