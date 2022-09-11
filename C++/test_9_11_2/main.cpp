#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter";
	int _age = 18;
};

class Student : public Person
{
protected:
	int _stuid; // Ñ§ºÅ
};

class Teacher : public Person
{
protected:
	int _jobid; // ¹¤ºÅ
};

int main()
{
	Student s;
	Teacher t;



	return 0;
}
