#include <iostream>

using namespace std;

//int main()
//{
//	int i;
//	char ch;
//	cin >> i;
//	cin >> ch;
//
//	cout << ch << endl;
//	cout << i << endl;
//
//	return 0;
//}

class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "买票-全价" << endl;
	}
};

class Student : public Person
{
public:
	// 子类重写父类的虚函数：
	virtual void BuyTicket()
	{
		cout << "买票-半价" << endl;
	}
};

class Soldier : public Person
{
	// 子类重写父类的虚函数：
public:
	virtual void BuyTicket()
	{
		cout << "优先买票" << endl;
	}
};

int main()
{


	return 0;
}
