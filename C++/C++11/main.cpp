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
	// C++11开始进行赋值的时候也可以不使用=
	Point p1 = {1, 2};
	Point p2{1, 2};

	// 甚至初始化整型的时候也可以不用等号
	int x1 = 1;
	int x2{2};

	int* p3 = new int[4]{0};
	int* p4 = new int[4]{1, 2, 3, 4};

	return 0;
}
