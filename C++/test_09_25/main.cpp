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

//int main()
//{
//
//	// ����
//	HeapOnly* p = HeapOnly::CreateObj();
//
//	return 0;
//}

// ����ģʽ��
// 1. ���캯��˽�ж��塣����������͸�ֵ����������

// ����ģʽ
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return _inst;
	}

private:
	// ���캯��˽�л�
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
