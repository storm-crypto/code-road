#include <iostream>
#include <initializer_list>
#include <vector>
#include <map>
#include <string>
#include <list>

using namespace std;

//struct Point
//{
//	int _x;
//	int _y;
//};
//
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
//
//int main()
//{
//	// C++11��ʼ���и�ֵ��ʱ��Ҳ���Բ�ʹ��=
//	Point p1 = {1, 2};
//	Point p2{1, 2};
//
//	// ������ʼ�����͵�ʱ��Ҳ���Բ��õȺ�
//	int x1 = 1;
//	int x2{2};
//
//	int* p3 = new int[4]{0};
//	int* p4 = new int[4]{1, 2, 3, 4};
//
//	Date d1;
//	Date d2(2022, 9, 27);
//	// ������Ȼ���������ã����ǲ���������ʹ�ã�����������Ϊ�����ط���׼����
//	Date d3{2022, 9, 27};
//	Date d4 = {2022, 9, 27};
//
//
//	return 0;
//}

int main()
{
	// the type of il is an initializer_list
	auto il = {10, 20, 30};
	std::initializer_list<int> il2 = {1, 2, 3, 4};
	cout << typeid(il).name() << endl;

	vector<int> v = {1, 2, 3, 4, 5};
	list<int> lt {10, 20, 30};

	vector<Date> vd = {Date(2022, 9, 27), Date{2022, 9, 27}, {2022, 9, 27}};
	map<string, int> dict = {make_pair("sort", 2), {"insert", 2}};

	return 0;
}
