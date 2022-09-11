#include <iostream>
#include <string>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter";
//	int _age = 18;
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//
//int main()
//{
//	Student s;
//	Teacher t;
//
//	return 0;
//}

// ��ֵ���ݹ���

//class Person
//{
//protected :
//	string _name; // ����
//	string _sex; // �Ա�
//	int _age; // ����
//};
//class Student : public Person
//{
//public :
//	int _No ; // ѧ��
//};
//
//int main()
//{
//	Person p;
//	Student s;
//
//	p = s; // ������Ը����࣬��Ƭ�ķ�ʽ
//	Person* ptr = &s; // �����ָ�룬ָ������
//	Person& ref = s;  // ���������
//
//}

// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected :
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout<<" ����:"<<_name<< endl;
//		cout<<" ���֤��:"<<Person::_num<< endl;
//		cout<<" ѧ��:"<<_num<<endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};
//// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
//// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" <<i<<endl;
//	}
//};
//void Test1()
//{
//	B b;
//	b.fun(10);
//}

class Person
{
public:
	Person(const char *name = "peter")
		:_name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person &p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person &p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
protected :
	string _name; // ����'
};

class Student: public Person
{
public:
	Student(const char* name, int id)
		: Person(name)
		, _id(id)
	{
		// ���ø��๹�캯����ʼ���̳е��ǲ���
		// �ٳ�ʼ���Լ��ĳ�Ա
		cout << "Student()" << endl;
	}

private:
	int _id;
};

int main()
{
	Student s("����", 11);

	return 0;
}