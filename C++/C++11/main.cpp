#include <iostream>

using namespace std;

struct Point
{
	int _x;
	int _y;
};

int main()
{
	// �ṹ��
	Point p2{1, 2};
	Point p1 = {1, 2};

	// ����
	int x{1};
	int x2 = 1;

	// ����
	int arr[]{1, 2, 3, 4};
	int arr1[] = {1, 2, 3, 4};

	// C++11֧��ֱ���ں�����г�ʼ��
	int* p3 = new int[4]{1, 2, 3, 4};
	int* p4 = new int[4]{0};

	return 0;
}
