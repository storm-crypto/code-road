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

//class Person
//{
//public:
//	// ����Ѹ����������������Ϊ�麯��
//	// ����������麯��������д������麯��
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	// Student��person���������ĺ�����������������ͬ���������ǹ����麯����д
//	virtual ~Student()
//	{
//		cout << "~Student" << endl;
//	}
//};
//
//int main()
//{
//	// ����ͨ�����£�����������������Ƿ񹹳���д������Ҫ����Ӱ��
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

//// ������
//class Car
//{
//public:
//	// ���麯��
//	virtual void Drive() = 0;
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz ����" << endl;
//	}
//};
//
//int main()
//{
//	Benz b;
//
//	return 0;
//}

// �麯����
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

// �������Ĵ��������������¸���
// 1.��������һ��������Deriveȥ�̳�Base
// 2.Derive����дFunc1
// 3.Base������һ���麯��Func2��һ����ͨ����Func3
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

// ���̳У�
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
//// дһ�������ӡһ�����ȷ������е��õĺ���
//typedef void (*VFunc)();
//void PrintVFT(VFunc* ptr)
//{
//	printf("����ַ��%p\n", ptr);
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

// ��̳��е��麯��
// ��̳�

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
	printf("����ַ��%p\n", ptr);
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

