#include <iostream>
using namespace std;

class A
{
public:
	//void setId(const A* const this)
	//ָ�����ݶ����ܱ�
	void setId(int id) const
	{
		_id = id;
	}
	//int getId(A* const this)
	//ָ���ܱ�
	int getId()
	{
		return _id;
	}
private:
	int _id;
};

int main()
{


	return 0;
}