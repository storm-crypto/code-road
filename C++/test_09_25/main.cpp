#include <iostream>
#include <mutex>
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
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return _inst;
//	}
//
//private:
//	// 构造函数私有化
//	Singleton()
//	{}
//
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//	static Singleton* _inst;
//};
//
//Singleton* Singleton::_inst = new Singleton;
//
//int main()
//{
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//
//	return 0;
//}

// 懒汉模式

//class Singleton
//{
//public:
//	// 懒汉模式可能会出现
//	static Singleton* GetInstance()
//	{
//		// 保护第一次需要加锁，后面都不需要加锁的场景，可以使用双检查加锁
//		// 特点：第一次加锁，后面不加锁，保护了线程安全，同时提高了效率
//		if (_inst == nullptr)
//		{
//			_mtx.lock();
//			if (_inst == nullptr)
//			{
//				_inst = new Singleton;
//			}
//			_mtx.unlock();
//		}
//
//		return _inst;
//	}
//
//	static void DelInstance()
//	{
//		_mtx.lock();
//		if (_inst)
//		{
//			delete _inst;
//			_inst = nullptr;
//		}
//		_mtx.unlock();
//	}
//
//private:
//	// 构造函数私有化
//	Singleton()
//	{}
//
//	~Singleton()
//	{
//		// 程序结束时，需要处理一下，持久化保存一下数据
//	}
//
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//	// 实现一个内嵌垃圾回收类
//	class CGarbo
//	{
//	public:
//		~CGarbo()
//		{
//			if (_inst)
//			{
//				delete _inst;
//				_inst = nullptr;
//			}
//		}
//	};
//
//	static Singleton* _inst;
//
//	static std::mutex _mtx;
//
//	static CGarbo _gc;
//};
//
//Singleton* Singleton::_inst = nullptr;
//std::mutex Singleton::_mtx;
//Singleton::CGarbo Singleton::_gc;

// 其他版本的懒汉
// 单例对象在静态区，如果单例对象太大，不太好
// 如果想主动释放单例对象，无法主动控制
class Singleton
{
public:
	// 懒汉模式可能会出现
	static Singleton* GetInstance()
	{
		static Singleton inst;
		return &inst;
	}

private:
	// 构造函数私有化
	Singleton()
	{}

	~Singleton()
	{
		// 程序结束时，需要处理一下，持久化保存一下数据
	}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

};


int main()
{
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;

	return 0;
}
