#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

template <class T1, class T2>
void printMap(const map<T1, T2>& m)
{
	//map�е�����pair������ֱ�ӽ����û��ֵ
	typename map<T1, T2>:: const_iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "-->" << it->second << endl;
		++it;
	}
}

template <class T1, class T2>
void printMap2(const map<T1, T2>& m)
{
	//map�е�����pair������ֱ�ӽ����û��ֵ
	typename map<T1, T2>::const_reverse_iterator it = m.rbegin();
	while (it != m.rend())
	{
		cout << it->first << "-->" << it->second << endl;
		++it;
	}
}

//void test()
//{
//	multimap<int, int> mm;
//	mm.insert(make_pair(10, 10));
//	mm.insert(make_pair(20, 20));
//	mm.insert(make_pair(10, 30));
//	mm.insert(make_pair(10, 40));
//	mm.insert(make_pair(10, 50));
//	mm.insert(make_pair(50, 60));
//	mm.insert(make_pair(40, 70));
//	mm.insert(make_pair(30, 80));
//	for (auto& e : mm)
//	{
//		cout << e.first << "-->" << e.second << endl;
//	}
//}

//void test()
//{
//	int arr[] = { 1, 6, 8, 5, 4, 9, 2, 4, 9 };
//	multiset<int> ms(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	for (auto& e : ms)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//void test()
//{
//	pair<int, int> arr[] = { pair<int ,int>(1, 3), pair<int ,int>(1, 2) ,
//		pair<int ,int>(3, 3) , pair<int ,int>(0, 0), pair<int ,int>(5, 5) };
//	map<int, int> map1(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	auto it = map1.find(1);
//
//}

//void test()
//{
//	map<int, int> map1;
//	auto ret = map1.insert(pair<int, int>(1, 1));
//	cout << ret.first->first << "-->" << ret.first->second << "insert:" << ret.second << endl;
//	ret = map1.insert(make_pair(2, 2));
//	cout << ret.first->first << "-->" << ret.first->second << "insert:" << ret.second << endl;
//	ret = map1.insert(make_pair(2, 3));
//	cout << ret.first->first << "-->" << ret.first->second << "insert:" << ret.second << endl;
//}

//void test()
//{
//	pair<int, int> arr[] = { pair<int ,int>(1, 3), pair<int ,int>(1, 2) ,
//		pair<int ,int>(3, 3) , pair<int ,int>(0, 0), pair<int ,int>(5, 5) };
//	map<int, int> map1(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	//at�ӿں�operator[]�����������atִ�в���������ʱ���쳣
//	cout << map1.at(10) << endl;
//}

//void test()
//{
//	pair<int, int> arr[] = { pair<int ,int>(1, 3), pair<int ,int>(1, 2) ,
//		pair<int ,int>(3, 3) , pair<int ,int>(0, 0), pair<int ,int>(5, 5) };
//	map<int, int> map1(arr, arr+sizeof(arr) / sizeof(arr[0]));
//	printMap(map1);
//	cout << "�޸ĵ�һ�����ݵ�value" << endl;
//	auto it = map1.begin();//��һ������
//	it->second = 10;
//	//it->first = 2; error
//	printMap(map1);
//}

//void test()
//{
//	map<int, int> map1;//�յ�map����
//	pair<int, int> arr[] = {pair<int ,int>(1, 3), pair<int ,int>(1, 2) ,
//		pair<int ,int>(3, 3) , pair<int ,int>(0, 0), pair<int ,int>(5, 5) };
//	map<int, int> map2(arr, arr+sizeof(arr) / sizeof(arr[0]));//ͨ�����ݴ���������
//	printMap2(map2);
//}

//void printSet(const set<int, greater<int>>& set)
//{
//	for (auto& s : set)
//		cout << s << " ";
//	cout << endl;
//}
//
//void test()
//{
//	vector<int> vec = { 4, 3, 9, 6, 3, 10, 12, 50, 1 };
//	set<int, greater<int>> set2 = { vec.begin(), vec.end() };
//	printSet(set2);
//}

//void test()
//{
//	vector<int> vec = { 4, 3, 9, 6, 3, 10, 12, 50, 1 };
//	set<int> set2 = { vec.begin(), vec.end() };
//	cout << set2.count(4) << endl;
//	cout << set2.count(40) << endl;
//}

//void test()
//{
//	vector<int> vec = { 4, 3, 9, 6, 3, 10, 12, 50, 1 };
//	set<int> set2 = { vec.begin(), vec.end() };
//	set<int> ::iterator it = set2.begin();
//	int ret = set2.erase(6);//ɾ���ɹ�����1
//	printSet(set2);
//	cout << ret << endl;
//	ret = set2.erase(5);//ɾ��ʧ�ܷ���0
//	printSet(set2);
//	cout << ret << endl;
//	set2.erase(it);//ע�ⲻ�ܴ��Ƿ�λ�ã�end()
//	printSet(set2);
//	set2.erase(++set2.begin(), --set2.end());//ɾ��ֻʣͷ��β��������
//	printSet(set2);
//}
//void test()
//{
//	vector<int> vec = { 4, 3, 9, 6, 3 };
//	set<int> set2 = { vec.begin(), vec.end() };
//	printSet(set2);
//	auto it = set2.end();
//	set2.insert(it, 1);
//	printSet(set2);
//}

//void test()
//{
//	vector<int> vec = { 4, 3, 9, 6, 3 };
//	set<int> set2 = { vec.begin(), vec.end() };//ͨ������������set����
//
//	//ret.second��ʾpair����ڶ������ݣ�ret.first��ʾpair�����һ������
//	pair<set<int>::iterator, bool> ret = set2.insert(7);
//	cout << ret.second << " " << *ret.first << endl;//����ɹ���pair��һ�������������ݵĵ�����
//
//	ret = set2.insert(7);
//	cout << ret.second << " " << *ret.first << endl;//����ʧ�ܣ�pair��һ���������Ѿ����ڵ����ݵĵ�����
//}

//void test()
//{
//	vector<int> vec = { 4, 3, 9, 6, 3 };
//	set<int> set1; //��set
//	set<int> set2 = { vec.begin(), vec.end()};//ͨ������������set����
//
//	set<int> ::iterator it = set2.begin();//set������
//	while (it != set2.end())
//	{
//		cout << *it << " ";
//		//*it = 10; error �������޸�
//		++it;
//	}
//	cout << endl;
//	cout << "reverse itertor��" << endl;
//	set<int> ::reverse_iterator rit = set2.rbegin();
//	while (rit != set2.rend())
//	{
//		cout << *rit << " ";
//		//*it = 10; error �������޸�
//		++rit;
//	}
//	cout << set2.size() << endl;
//
//	pair<set<int>::iterator, bool> ret = set2.insert(7);
//	cout << ret.second << " " << *ret.first << endl;
//}
int main()
{
	test();
	return 0;
}