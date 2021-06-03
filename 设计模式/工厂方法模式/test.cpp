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
		cout << "Huawei Phone" << endl;
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

//���󹤳�
class AbstractPhoneFactory
{
public:
	virtual AbstractPhone* CreatePhone() = 0;
};

//��Ϊ����
class HuaweiFactory : public AbstractPhoneFactory
{
public:
	virtual AbstractPhone* CreatePhone()
	{
		return new Huawei();
	}
};

//С�׹���
class XiaomiFactory : public AbstractPhoneFactory
{
public:
	virtual AbstractPhone* CreatePhone()
	{
		return new Xiaomi();
	}
};

//ƻ������
class AppleFactory : public AbstractPhoneFactory
{
public:
	virtual AbstractPhone* CreatePhone()
	{
		return new Apple();
	}
};

void test()
{
	//����һ������
	AbstractPhoneFactory* factory = nullptr;
	//����һ���ֻ�
	AbstractPhone* phone = nullptr;

	//ָ�������ǻ�Ϊ����
	factory = new HuaweiFactory;
	//ͨ����Ϊ��������һ���ֻ�
	phone = factory->CreatePhone();
	phone->ShowName();

	delete phone;
	delete factory;

	factory = new XiaomiFactory;
	phone = factory->CreatePhone();
	phone->ShowName();

	delete phone;
	delete factory;

	factory = new AppleFactory;
	phone = factory->CreatePhone();
	phone->ShowName();

	delete phone;
	delete factory;
}

int main()
{
	test();
	return 0;
}