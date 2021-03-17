#include <iostream>
#include <string>
using namespace std;

void test()
{
	string str = "123";
	string str2 = "abc";
	str.insert(0, str2);//abc123
	str.insert(3, str2, 1, 1);//abcb123
	str.insert(str.size(), "www"); // abcb123www
	str.insert(7, "abc", 2);//abcb123ab3www
	str.insert(str.size(), 5, 'a');//abcb123ab3wwwaaaaa
	str.insert(str.begin(), 2, '1');//11abcb123ab3wwwaaaaa
	str.insert(str.end(), str2.begin(), str2.end());//11abcb123ab3wwwaaaaaabc
}

//void test()
//{
//	string str;
//	string str2 = "abc";
//	str.assign(str2); //abc
//	str.assign(str2, 1, 2);// bc
//	str.assign("abc"); //abc
//	str.assign("abcde", 4); //abcd
//	str.assign(5, 'w'); //wwwww
//	str.assign(++str2.begin(), str2.end()); // bc
//}

//void test()
//{
//	string str;
//	string str2 = "abc"; 
//	str.append(str2);//"abc"
//	str.append(str2, 1, 2);//"abcbc"
//	str.append("abc"); //"abcbcabc"
//	str.append("123456789", 6);//"abcbcabc123456"
//	str.append(5, 'w'); // "abcbcabc123456wwwww"
//
//	char arr[] = "abc";
//	str.append(arr, arr + sizeof(arr) / sizeof(arr[0])); //"abcbcabc123456wwwwwabc"
//	str.append(str2.begin(), str2.end()); //"abcbcabc123456wwwwwabcabc"
//}

//void test()
//{
//	string str;
//	string str2 = "abc";
//	str += str2; //"abc"
//	str += "def"; //"abcdef"
//	str += 'g';//"abcdefg"
//}

//void test()
//{
//	string str = "White";
//	cout << str.size() << endl;
//	str.clear();
//	cout << str.size() << endl;
//
//	str.reserve(1000);
//	cout << str.capacity() << endl;
//	str.shrink_to_fit();
//	cout << str.capacity() << endl;
//}

//void test()
//{
//	string str = "White";
//	cout << str.capacity() << endl; //Ĭ��Ϊ15
//	cout << str.size() << endl; //5
//	//�޸���������Ӱ����ЧԪ�ظ���
//	str.reserve(30);
//	cout << str.capacity() << endl; //30����
//	cout << str.size() << endl; //5
//	//�޸���ЧԪ�ظ�����Ӱ������������ cap > size
//	str.resize(60);
//	cout << str.capacity() << endl; //60����
//	cout << str.size() << endl; //60
//}

//void test()
//{
//	string str = "White";
//	cout << str.size() << endl;
//	cout << str.length() << endl;
//	str.resize(10);
//	cout << str.size() << endl;
//	str.resize(2);
//	cout << str.size() << endl;
//
//	string str2 = "Shirt";
//	cout << str2.size() << endl;
//	str2.resize(10, 'I'); //"ShirtIIIII"
//	cout << str2.size() << endl;
//	str2.resize(5, 'I'); //��Ч�ַ�Ϊ5�����������������
//}

//void test()
//{
//	string str = "WhiteShirtI";
//	for (const auto& ch : str)
//	{
//		cout << ch;
//	}
//}

//void test()
//{
//	string str = "12345";
//	string::reverse_iterator rit = str.rbegin();
//	while (rit != str.rend())
//	{
//		cout << *rit << " "; //5 4 3 2 1
//		*rit = 'w';
//		//�����������ʲô���Ƿ���
//		++rit;
//	}
//
//	const string str2 = "12345";
//	string::const_reverse_iterator rit2 = str2.rbegin();
//	while (rit2 != str2.rend())
//	{
//		cout << *rit2 << " "; //5 4 3 2 1
//		*rit2 = 'w';//error ���ʽ����Ϊ���޸ĵ���ֵ
//		//�����������ʲô���Ƿ���
//		++rit2;
//	}
//}

//void test()
//{
//	string str = "WhiteShirtI";
//	string::iterator it = str.begin();
//	for (; it != str.end(); ++it)
//	{
//		cout << *it << " ";
//		*it = 'w';
//	}
//
//	const string str2 = "WhiteShirtI";
//	string::const_iterator it2 = str.begin();
//	for (; it != str.end(); ++it)
//	{
//		cout << *it2 << " ";
//		*it2 = 'w'; // error ���ʽ����Ϊ���޸ĵ���ֵ
//	}
//}

//void test()
//{
//	string str = "White shirtI";
//	char& ref = str[7];
//	ref = 'S';
//	str.at(0) = 'w';
//
//	const string str2 = "White ShirtI";
//	const char& ref2 = str2[0];
//	ref2 = 'w';  //error ��ʾ�����ǿ��޸ĵ���ֵ
//	str2.at(0) = 'w';//error ��ʾ�����ǿ��޸ĵ���ֵ
//}

//void test()
//{
//	string str; // ""
//	string copy(str); // ""
//	string str2("White"); // "White"
//	string substr(str2, 1, 2); //"hi"
//	string str3("White ShirtI", 5);//white
//	string str4(5, 'w'); //"wwwww"
//	str3 = "White ShirtI"; //"White ShirtI"
//	str4 = str3; //"White ShirtI"
//}

int main()
{
	test();
	return 0;
}