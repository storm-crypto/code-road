#include <iostream>
#include <mutex>
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
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return _inst;
//	}
//
//private:
//	// ���캯��˽�л�
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

// ����ģʽ

//class Singleton
//{
//public:
//	// ����ģʽ���ܻ����
//	static Singleton* GetInstance()
//	{
//		// ������һ����Ҫ���������涼����Ҫ�����ĳ���������ʹ��˫������
//		// �ص㣺��һ�μ��������治�������������̰߳�ȫ��ͬʱ�����Ч��
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
//	// ���캯��˽�л�
//	Singleton()
//	{}
//
//	~Singleton()
//	{
//		// �������ʱ����Ҫ����һ�£��־û�����һ������
//	}
//
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//	// ʵ��һ����Ƕ����������
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

// �����汾������
// ���������ھ�̬���������������̫�󣬲�̫��
// ����������ͷŵ��������޷���������
class Singleton
{
public:
	// ����ģʽ���ܻ����
	static Singleton* GetInstance()
	{
		static Singleton inst;
		return &inst;
	}

private:
	// ���캯��˽�л�
	Singleton()
	{}

	~Singleton()
	{
		// �������ʱ����Ҫ����һ�£��־û�����һ������
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
