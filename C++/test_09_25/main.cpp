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

int main()
{

	// ����
	HeapOnly* p = HeapOnly::CreateObj();

	return 0;
}
