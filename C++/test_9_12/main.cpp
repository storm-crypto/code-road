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
		cout << "��Ʊ-ȫ��" << endl;
	}
};

class Student : public Person
{
public:
	// ������д������麯����
	virtual void BuyTicket()
	{
		cout << "��Ʊ-���" << endl;
	}
};

class Soldier : public Person
{
	// ������д������麯����
public:
	virtual void BuyTicket()
	{
		cout << "������Ʊ" << endl;
	}
};

void f(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person p; // ��ͨ��
	Student st; // ѧ��
	Soldier so; // ����

	f(p);
	f(st);
	f(so);

	return 0;
}
