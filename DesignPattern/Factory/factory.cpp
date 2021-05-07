#include<iostream>
using namespace std;

//�������--�ֻ�
class Phone
{
public:
	//��Ʒҵ��--������
	virtual void listenMusic() = 0;
};
//�����Ʒ--����
class Computer
{
public:
	//��Ʒҵ��--����Ϸ
	virtual void playGame() = 0;
};

//���󹤳�
class Factory
{
public:
	//���ɳ����Ʒ--�����ֻ�
	virtual Phone* createPhone() = 0;
	//���ɳ����Ʒ--���ɵ���
	virtual Computer* createComputer() = 0;
};

//�����Ʒ--��Ϊ�ֻ�
class HuaweiPhone : public Phone
{
public:
	//��д�����Ʒ�е�ҵ�񷽷�
	virtual void listenMusic()
	{
		cout << "���Ż�Ϊ�ֻ�������" << endl;
	}
};
//�����Ʒ--��Ϊ����
class HuaweiComputer : public Computer
{	
public:
	//��д�����Ʒ�е�ҵ�񷽷�
	virtual void playGame()
	{
		cout << "���Ż�Ϊ���Դ���Ϸ" << endl;
	}
};
//�����Ʒ--ƻ���ֻ�
class ApplePhone : public Phone
{
public:
	//��д�����Ʒ�е�ҵ�񷽷�
	virtual void listenMusic()
	{
		cout << "����ƻ���ֻ�������" << endl;
	}
};
//�����Ʒ--ƻ������
class AppleComputer : public Computer
{
public:
	//��д�����Ʒ�е�ҵ�񷽷�
	virtual void playGame()
	{
		cout << "���Ż�Ϊ���Դ���Ϸ" << endl;
	}
};
//���幤��--��Ϊ����
class HuaweiFactory : public Factory
{
public:
	//��д���󹤳��е������ֻ�
	virtual Phone* createPhone()
	{
		return new HuaweiPhone();
	}
	//��д���󹤳��е���������
	virtual Computer* createComputer()
	{
		return new HuaweiComputer();
	}
};
//���幤��--ƻ������
class AppleFactory : public Factory
{
public:
	//��д���󹤳��е������ֻ�
	virtual Phone* createPhone()
	{
		return new ApplePhone();
	}
	//��д���󹤳��е���������
	virtual Computer* createComputer()
	{
		return new AppleComputer();
	}
};

int main()
{
	//������Ϊ����
	Factory* huaweiFactory = new HuaweiFactory();
	//��Ϊ���������ֻ�
	Phone* huaweiPhone = huaweiFactory->createPhone();
	//��Ϊ���ֻ�������
	huaweiPhone->listenMusic();
	//��Ϊ������������
	Computer* huaweiComputer = huaweiFactory->createComputer();
	//��Ϊ�ĵ��Դ���Ϸ
	huaweiComputer->playGame();

	//����ƻ������
	Factory* appleFactory = new AppleFactory();
	//ƻ�����������ֻ�
	Phone* applePhone = appleFactory->createPhone();
	//ƻ�����ֻ�������
	applePhone->listenMusic();
	//ƻ��������������
	Computer* appleComputer = appleFactory->createComputer();
	//ƻ���ĵ��Դ���Ϸ
	appleComputer->playGame();
	return 0;
}
////���ӳ����� 
//class Connection
//{
//public:
//	virtual void connection() = 0;
//};
//
////�������� 
//class Statement
//{
//public:
//	virtual void statement() = 0;
//};
//
////���󹤳�
//class DBFactory
//{
//public:
//	virtual Connection* createConnection() = 0;
//	virtual Statement* createStatement() = 0;
//};
//
////oracle������ 
//class OracleConnection : public Connection
//{
//public:
//	virtual void connection()
//	{
//		cout << "Oracle���ݿ������" << endl;
//	}
//};
//
////oracle����� 
//class OracleStatement : public Statement
//{
//public:
//	virtual void statement()
//	{
//		cout << "Oracle���ݿ�����" << endl;
//	}
//};
//
////mysql������ 
//class MySQLConnection : public Connection
//{
//public:
//	virtual void connection()
//	{
//		cout << "MySQL���ݿ������" << endl;
//	}
//};
//
////mysql����� 
//class MySQLStatement : public Statement
//{
//public:
//	virtual void statement()
//	{
//		cout << "MySQL���ݿ�����" << endl;
//	}
//};
//
////oracle���� 
//class OracleFactory : public DBFactory
//{
//	virtual Connection* createConnection()
//	{
//		return new OracleConnection();
//	}
//	virtual Statement* createStatement()
//	{
//		return new OracleStatement();
//	}
//};
//
////mysql���� 
//class MySQLFactory : public DBFactory
//{
//	virtual Connection* createConnection()
//	{
//		return new MySQLConnection();
//	}
//	virtual Statement* createStatement()
//	{
//		return new MySQLStatement();
//	}
//};
//
//int main()
//{
//
//	DBFactory* oracleFactory = new OracleFactory();
//	Connection* oracleConnection = oracleFactory->createConnection();
//	oracleConnection->connection();
//	Statement* oracleStatement = oracleFactory->createStatement();
//	oracleStatement->statement();
//	delete oracleConnection;
//	delete oracleStatement;
//	delete oracleFactory;
//
//	DBFactory* mySQLFactory = new MySQLFactory();
//	Connection* mySQLConnection = mySQLFactory->createConnection();
//	mySQLConnection->connection();
//	Statement* mySQLStatement = mySQLFactory->createStatement();
//	mySQLStatement->statement();
//	delete mySQLStatement;
//	delete mySQLConnection;
//	delete mySQLFactory;
//	return 0;
//}
