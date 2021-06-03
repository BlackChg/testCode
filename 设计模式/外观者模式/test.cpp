#include <iostream>
using namespace std;

//������
class Television
{
public:
	void On()
	{
		cout << "���Ӵ�" << endl;
	}
	void Off()
	{
		cout << "���ӹر�" << endl;
	}
};

//����
class Light
{
public:
	void On()
	{
		cout << "�ƴ�" << endl;
	}
	void Off()
	{
		cout << "�ƹر�" << endl;
	}
};

//������
class Audio
{
public:
	void On()
	{
		cout << "�����" << endl;
	}
	void Off()
	{
		cout << "����ر�" << endl;
	}
};

//��˷���
class Microphone
{
public:
	void On()
	{
		cout << "��˷��" << endl;
	}
	void Off()
	{
		cout << "��˷�ر�" << endl;
	}
};

//dvd��
class DvdPlayer
{
public:
	void On()
	{
		cout << "DVD��" << endl;
	}
	void Off()
	{
		cout << "DVD�ر�" << endl;
	}
};



class KTVMode
{
public:
	KTVMode()
	{
		pTv = new Television;
		pLight = new Light;
		pAudio = new Audio;
		pMicrophone = new Microphone;
		pDvd = new DvdPlayer;
	}
	~KTVMode()
	{
		delete pTv;
		delete pLight;
		delete pAudio;
		delete pMicrophone;
		delete pDvd;
	}

	//��ktv
	void OnKty()
	{
		pTv->On();
		pLight->Off();
		pAudio->On();
		pMicrophone->On();
		pDvd->On();
	}
	//�ر�ktv
	void OffKty()
	{
		pTv->Off();
		pLight->On();
		pAudio->Off();
		pMicrophone->Off();
		pDvd->Off();
	}

private:
	Television* pTv;
	Light* pLight;
	Audio* pAudio;
	Microphone* pMicrophone;
	DvdPlayer* pDvd;
};

void test()
{
	KTVMode* ktv = new KTVMode();

	cout << "��KTVģʽ" << endl;
	ktv->OnKty();
	cout << endl;
	cout << "�ر�KTVģʽ" << endl;
	ktv->OffKty();
	
	delete ktv;
}

int main()
{
	test();
	return 0;
}