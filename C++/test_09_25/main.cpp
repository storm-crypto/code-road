#include <iostream>
using namespace std;

class HeapOnly
{
public:
	// 将创建对象的函数放到静态区
	static HeapOnly* CreateObj()
	{
		return new HeapOnly;
	}

private:
	// 构造函数私有化
	HeapOnly()
	{}

	// 拷贝构造私有，并且只声明不实现
	// 防止拷贝
	HeapOnly(const HeapOnly&);
};

// 方法一：
//class StackOnly
//{
//public:
//	static StackOnly CreateObj()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly()
//	{}
//};

// 方法二：
class StackOnly
{
public:
	StackOnly() {}

	// C++11
	void* operator new(size_t size) = delete;
	void operator delete(void* p) = delete;
private:
//	void* operator new(size_t size);
//	void operator delete(void* p);
};

//int main()
//{
//
//	// 调用
//	HeapOnly* p = HeapOnly::CreateObj();
//
//	return 0;
//}

// 单例模式：
// 1. 构造函数私有定义。将拷贝构造和赋值防拷贝禁掉

// 饿汉模式
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return _inst;
	}

private:
	// 构造函数私有化
	Singleton()
	{}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton* _inst;
};

Singleton* Singleton::_inst = new Singleton;

int main()
{
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;

	return 0;
}
