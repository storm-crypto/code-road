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
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};

int main()
{

	// 调用
	HeapOnly* p = HeapOnly::CreateObj();

	return 0;
}
