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

class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{}
};

int main()
{

	// 调用
	HeapOnly* p = HeapOnly::CreateObj();

	return 0;
}
