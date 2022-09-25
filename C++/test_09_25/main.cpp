#include <iostream>
using namespace std;

class HeapOnly
{
public:
	// ����������ĺ����ŵ���̬��
	static HeapOnly* CreateObj()
	{
		return new HeapOnly;
	}

private:
	// ���캯��˽�л�
	HeapOnly()
	{}

	// ��������˽�У�����ֻ������ʵ��
	// ��ֹ����
	HeapOnly(const HeapOnly&);
};

// ����һ��
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

// ��������
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

int main()
{

	// ����
	HeapOnly* p = HeapOnly::CreateObj();

	return 0;
}
