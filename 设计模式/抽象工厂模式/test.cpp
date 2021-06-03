#include <iostream>
using namespace std;

//�����ֻ�
class AbstractPhone
{
public:
	virtual void ShowName() = 0;
};
//��Ϊ�ֻ�
class HuaweiPhone : public AbstractPhone
{
public:
	virtual void ShowName()
	{
		cout << "��Ϊ�ֻ�" << endl;
	}
};
//С���ֻ�
class XiaomiPhone : public AbstractPhone
{
public:
	virtual void ShowName()
	{
		cout << "С���ֻ�" << endl;
	}
};
//ƻ���ֻ�
class ApplePhone : public AbstractPhone
{
public:
	virtual void ShowName()
	{
		cout << "ƻ���ֻ�" << endl;
	}
};
//�������
class AbstractHeadset
{
public:
	virtual void ShowName() = 0;
};

//��Ϊ����
class HuaweiHeadset : public AbstractHeadset
{
public:
	virtual void ShowName()
	{
		cout << "��Ϊ����" << endl;
	}
};

//С�׶���
class XiaomiHeadset : public AbstractHeadset
{
public:
	virtual void ShowName()
	{
		cout << "С�׶���" << endl;
	}
};

//ƻ������
class AppleHeadset : public AbstractHeadset
{
public:
	virtual void ShowName()
	{
		cout << "Сƻ������" << endl;
	}
};

//�������
class AbstractComputer
{
public:
	virtual void ShowName() = 0;
};

//��Ϊ����
class HuaweiComputer : public AbstractComputer
{
public:
	virtual void ShowName()
	{
		cout << "��Ϊ����" << endl;
	}
};

//С�׵���
class XiaomiComputer : public AbstractComputer
{
public:
	virtual void ShowName()
	{
		cout << "С�׵���" << endl;
	}
};

//ƻ������
class AppleComputer : public AbstractComputer
{
public:
	virtual void ShowName()
	{
		cout << "ƻ������" << endl;
	}
};

//���󹤳� ��Բ�Ʒ��
class AbstrackFactory
{
public:
	virtual AbstractPhone* CreatePhone() = 0;
	virtual AbstractHeadset* CreateHeadset() = 0;
	virtual AbstractComputer* CreateComputer() = 0;

};
//��Ϊ����
class HuaweiFactory : public AbstrackFactory
{
public:
	virtual AbstractPhone* CreatePhone()
	{
		return new HuaweiPhone();
	}
	virtual AbstractHeadset* CreateHeadset()
	{
		return new HuaweiHeadset();
	}
	virtual AbstractComputer* CreateComputer()
	{
		return new HuaweiComputer();
	}
};

//С�׹���
class XiaomiFactory : public AbstrackFactory
{
public:
	virtual AbstractPhone* CreatePhone()
	{
		return new XiaomiPhone();
	}
	virtual AbstractHeadset* CreateHeadset()
	{
		return new XiaomiHeadset();
	}
	virtual AbstractComputer* CreateComputer()
	{
		return new XiaomiComputer();
	}
};

//ƻ������
class AppleFactory : public AbstrackFactory
{
public:
	virtual AbstractPhone* CreatePhone()
	{
		return new ApplePhone();
	}
	virtual AbstractHeadset* CreateHeadset()
	{
		return new AppleHeadset();
	}
	virtual AbstractComputer* CreateComputer()
	{
		return new AppleComputer();
	}
};

void test()
{
	//����һ������
	AbstrackFactory* factory = nullptr;
	//������Ʒ
	AbstractPhone* phone = nullptr;
	AbstractHeadset* headset = nullptr;
	AbstractComputer* computer = nullptr;

	//ָ���ù����ǻ�Ϊ����
	factory = new HuaweiFactory();
	//ͨ����Ϊ���������Ĳ�Ʒ
	phone = factory->CreatePhone();
	headset = factory->CreateHeadset();
	computer = factory->CreateComputer();
	
	phone->ShowName();
	headset->ShowName();
	computer->ShowName();

	delete phone;
	delete headset;
	delete computer;
	delete factory;
}

int main()
{
	test();
	return 0;
}