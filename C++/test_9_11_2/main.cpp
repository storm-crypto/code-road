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
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//
//int main()
//{
//	Student s;
//	Teacher t;
//
//	return 0;
//}

// 赋值兼容规则

//class Person
//{
//protected :
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public :
//	int _No ; // 学号
//};
//
//int main()
//{
//	Person p;
//	Student s;
//
//	p = s; // 子类可以给父类，切片的方式
//	Person* ptr = &s; // 父类的指针，指向子类
//	Person& ref = s;  // 父类的引用
//
//}

// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected :
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout<<" 姓名:"<<_name<< endl;
//		cout<<" 身份证号:"<<Person::_num<< endl;
//		cout<<" 学号:"<<_num<<endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};
//// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
//// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
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

//class Person
//{
//public:
//	Person(const char *name = "peter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person &p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person &p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected :
//	string _name; // 姓名'
//};
//
//class Student: public Person
//{
//public:
//	Student(const char* name, int id)
//		: Person(name)
//		, _id(id)
//	{
//		// 调用父类构造函数初始化继承的那部分
//		// 再初始化自己的成员
//		cout << "Student()" << endl;
//	}
//
//	// 拷贝构造
//	Student(const Student& s)
//		:Person(s)  // s传递给Person& s是一个切片行为
//		, _id(s._id)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	// 赋值拷贝
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s); // 父类的自己切
//			_id = s._id;
//		}
//
//		cout << "Student& operator=(const Student& s)" << endl;
//
//		return *this;
//	}
//
//	// 析构函数
//	~Student()
//	{
////		Person::~Person();
//
//		//清理自己的
//		cout << "~Student()" << endl;
//		// 为了保证析构时，保持先子再父的后进先出的顺序析构
//		// 子类析构函数完成后，会自动调用父类的析构函数
//	}
//
//private:
//	int _id;
//};
//
//int main()
//{
//	Student s1("张三", 11);
//
//	Student s2(s1);
//
//	return 0;
//}

// 虚继承的原理
class A
{
public:
	int _a;
};

//class B : public A
class B : virtual public A
{
public:
	int _b;
};

//class C : public A
class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

	return 0;
}