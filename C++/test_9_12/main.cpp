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
//		cout << "买票-全价" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	// 子类重写父类的虚函数：
//	virtual void BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//};
//
//class Soldier : public Person
//{
//	// 子类重写父类的虚函数：
//public:
//	virtual void BuyTicket()
//	{
//		cout << "优先买票" << endl;
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
//	Person p; // 普通人
//	Student st; // 学生
//	Soldier so; // 军人
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
	// 建议把父类的析构函数定义为虚函数
	// 这样子类的虚函数方便重写父类的虚函数
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person
{
public:
	// Student和person析构函数的函数名，看起来不相同，但是他们构成虚函数重写
	virtual ~Student()
	{
		cout << "~Student" << endl;
	}
};

int main()
{
	// 在普通场景下，父子类的析构函数是否构成重写，不重要，不影响
	Person p;
	Student s;



	return 0;
}