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

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	// ������д������麯����
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-���" << endl;
//	}
//};
//
//class Soldier : public Person
//{
//	// ������д������麯����
//public:
//	virtual void BuyTicket()
//	{
//		cout << "������Ʊ" << endl;
//	}
//};
//
//void f(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person p; // ��ͨ��
//	Student st; // ѧ��
//	Soldier so; // ����
//
//	f(p);
//	f(st);
//	f(so);
//
//	return 0;
//}

//class A{};
//class B : public A {};
//
//class Person
//{
//public:
//	virtual A* f()
//	{
//		cout << " A* Person::f()" << endl;
//		return new A;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual B* f()
//	{
//		cout << " B* Student::f()" << endl;
//		return new B;
//	}
//};
//
//
//int main()
//{
//	Person p;
//	Student s;
//
//	Person* ptr;
//	ptr = &p;
//	ptr->f();
//
//	ptr = &s;
//	ptr->f();
//
//	return 0;
//}

class Person
{
public:
	// ����Ѹ����������������Ϊ�麯��
	// ����������麯��������д������麯��
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person
{
public:
	// Student��person���������ĺ�����������������ͬ���������ǹ����麯����д
	virtual ~Student()
	{
		cout << "~Student" << endl;
	}
};

int main()
{
	// ����ͨ�����£�����������������Ƿ񹹳���д������Ҫ����Ӱ��
	Person p;
	Student s;



	return 0;
}