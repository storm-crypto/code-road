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
class Person
{
protected :
	string _name = "小李子"; // 姓名
	int _num = 111; // 身份证号
};
class Student : public Person
{
public:
	void Print()
	{
		cout<<" 姓名:"<<_name<< endl;
		cout<<" 身份证号:"<<Person::_num<< endl;
		cout<<" 学号:"<<_num<<endl;
	}
protected:
	int _num = 999; // 学号
};
void Test()
{
	Student s1;
	s1.Print();
};
// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" <<i<<endl;
	}
};
void Test1()
{
	B b;
	b.fun(10);
}