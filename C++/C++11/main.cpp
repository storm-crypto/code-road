#include <iostream>
#include <initializer_list>
#include <vector>
#include <map>
#include <string>
#include <list>

using namespace std;

struct Point
{
	int _x;
	int _y;
};


int main()
{
	// C++11��ʼ���и�ֵ��ʱ��Ҳ���Բ�ʹ��=
	Point p1 = {1, 2};
	Point p2{1, 2};

	// ������ʼ�����͵�ʱ��Ҳ���Բ��õȺ�
	int x1 = 1;
	int x2{2};

	int* p3 = new int[4]{0};
	int* p4 = new int[4]{1, 2, 3, 4};

	return 0;
}
