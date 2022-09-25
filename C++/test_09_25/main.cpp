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

	// ����
	HeapOnly* p = HeapOnly::CreateObj();

	return 0;
}
