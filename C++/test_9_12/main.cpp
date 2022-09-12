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

void f(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person p; // 普通人
	Student st; // 学生
	Soldier so; // 军人

	f(p);
	f(st);
	f(so);

	return 0;
}
