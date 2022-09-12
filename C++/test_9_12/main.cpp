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

//class Person
//{
//public:
//	// 建议把父类的析构函数定义为虚函数
//	// 这样子类的虚函数方便重写父类的虚函数
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	// Student和person析构函数的函数名，看起来不相同，但是他们构成虚函数重写
//	virtual ~Student()
//	{
//		cout << "~Student" << endl;
//	}
//};
//
//int main()
//{
//	// 在普通场景下，父子类的析构函数是否构成重写，不重要，不影响
//	Person p;
//	Student s;
//
//	return 0;
//}

//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz" << endl;
//	}
//};
//
//int main()
//{
//
//	return 0;
//}

//class Car
//{
//public:
//	virtual void Drive() {}
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Drive() override
//	{
//		cout << "Benz" << endl;
//	}
//};
//
//int main()
//{
//
//	return 0;
//}

//// 抽象类
//class Car
//{
//public:
//	// 纯虚函数
//	virtual void Drive() = 0;
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz 舒适" << endl;
//	}
//};
//
//int main()
//{
//	Benz b;
//
//	return 0;
//}

// 虚函数表
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Func1()" << endl;
//	}
//
//private:
//	int _b = 1;
//};

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
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person Mike;
//	Func(Mike);
//
//	Student Johnson;
//	Func(Johnson);
//
//
//	return 0;
//}

// 针对上面的代码我们做出以下改造
// 1.我们增加一个派生类Derive去继承Base
// 2.Derive中重写Func1
// 3.Base再增加一个虚函数Func2和一个普通函数Func3
//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base()" << endl;
//	}
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
// }

// 单继承：
//class Base
//{
//public:
//	virtual void func1() {cout << "Base::func1()" << endl; }
//	virtual void func2() {cout << "Base::func1()" << endl; }
//private:
//	int a;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void func1() {cout << "Derive::func1()" << endl; }
//	virtual void func3() {cout << "Derive::func3()" << endl; }
//	virtual void func4() {cout << "Derive::func4()" << endl; }
//private:
//	int b;
//};
//
//// 写一个程序打印一下虚表，确认虚表中调用的函数
//typedef void (*VFunc)();
//void PrintVFT(VFunc* ptr)
//{
//	printf("虚表地址：%p\n", ptr);
//	for (int i = 0; ptr[i] != nullptr; i++)
//	{
//		printf("VFT[%d]:%p->", i, ptr[i]);
//		ptr[i]();
//	}
//	printf("\n");
//}
//
//int main()
//{
//	Base b;
//	PrintVFT((VFunc*)(*(int*)&b));
//
//	Derive d;
//	PrintVFT((VFunc*)(*(int*)&d));
//
//	return 0;
//}

// 多继承中的虚函数
// 多继承

class Base1 {
public:
	virtual void func1() {cout << "Base1::func1" << endl;}
	virtual void func2() {cout << "Base1::func2" << endl;}
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() {cout << "Base2::func1" << endl;}
	virtual void func2() {cout << "Base2::func2" << endl;}
private:
	int b2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() {cout << "Derive::func1" << endl;}
	virtual void func3() {cout << "Derive::func3" << endl;}
private:
	int d1;
};

typedef void (*VFunc)();

void PrintVFT(VFunc* ptr)
{
	printf("虚表地址：%p\n", ptr);
	for (int i = 0; ptr[i] != nullptr; i++)
	{
		printf("VFT[%d]:%p->", i, ptr[i]);
		ptr[i]();
	}
	printf("\n");
}

int main()
{
	Base1 b1;
	Base2 b2;
//
//	PrintVFT((VFunc*)(*(int*)&b1));
//	PrintVFT((VFunc*)(*(int*)&b2));

	Derive d;
	PrintVFT((VFunc*)(*(int*)&d));
	PrintVFT((VFunc*)(*(int*)((char*)&d + sizeof(Base1))));

	return 0;
}

