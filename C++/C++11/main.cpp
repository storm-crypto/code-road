#include <cmath>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <assert.h>
#include <string.h>

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

//int main()
//{
//	// the type of il is an initializer_list
//	auto il = {10, 20, 30};
//	std::initializer_list<int> il2 = {1, 2, 3, 4};
//	cout << typeid(il).name() << endl;
//
//	vector<int> v = {1, 2, 3, 4, 5};
//	list<int> lt {10, 20, 30};
//
//	vector<Date> vd = {Date(2022, 9, 27), Date{2022, 9, 27}, {2022, 9, 27}};
//	map<string, int> dict = {make_pair("sort", 2), {"insert", 2}};
//
//	return 0;
//}

//int main()
//{
//	int i = 10;
//	auto p = &i;
//
//	decltype(p) px;
//
//	return 0;
//}

//#include <array>
//
//int main()
//{
//
//	// Խ������ϸ�
//	array<int, 10> a1;
//	array<int, 20> a2;
//
//	a1[11];
//
//	int a[10];
//	a[11];
//
//	return 0;
//}

//int main()
//{
//	// ��ֵ����
//	double x = 1.1, y = 2.2;
//// ���¼������ǳ�������ֵ
//	10;
//	x + y;
//	fmin(x, y);
//// ���¼������Ƕ���ֵ����ֵ����
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//// �������ᱨ����error C2106: ��=��: �����������Ϊ��ֵ
////	10 = 1;
////	x + y = 1;
////	fmin(x, y) = 1;
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra1 = a;
//
//	// int& ra2 = 10; // ����ʧ�ܣ���ֵ���ò���������ֵ
//
//	const int& ra3 = 10; // ����const����ֵ���ÿ���������ֵ
//}

//int main()
//{
//	// ��ֵ����ֻ����ֵ������������ֵ��
//	int&& r1 = 10;
//	// error C2440: ����ʼ����: �޷��ӡ�int��ת��Ϊ��int &&��
//	// message : �޷�����ֵ�󶨵���ֵ����
//	int a = 10;
//	int&& r2 = a;
//
//	// ��ֵ���ÿ�������move�Ժ����ֵ
//	int&& r3 = std::move(a);
//
//	return 0;
//}

namespace ljx
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// ��������
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;
			string tmp(s._str);
			swap(tmp);
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}

		// �ƶ�����
		string(string&& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;
			swap(s);
		}

		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- �ƶ�����" << endl;
			swap(s);
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // �������������ʶ��\0
	};
}

// ��ֵ���õ�ʹ�ó�����
// 1. ������
// 2. ������ֵ

void func1(ljx::string s)
{}

void func2(const ljx::string& s)
{}

int main()
{
	ljx::string s1("hello world");
	// func1��func2�ĵ������ǿ��Կ�����ֵ���������������˿�����
	// ���Ч�ʵ�ʹ�ó����ͼ�ֵ
	func1(s1);
	func2(s1);
	// string operator+=(char ch) ��ֵ���ش������
	// string& operator+=(char ch) ����ֵ����û�п��������Ч��
	s1 += '!';

	return 0;
}