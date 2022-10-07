#include <cmath>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <assert.h>
#include <string.h>
#include <algorithm>

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
//// �������ᱨ��error C2106: ��=��: �����������Ϊ��ֵ
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

namespace ljx
{
ljx::string to_string(int value)
{
	bool flag = true;
	if (value < 0)
	{
		flag = false;
		value = 0 - value;
	}

	ljx::string str;
	while (value > 0)
	{
		int x = value % 10;
		value /= 10;
		str += ('0' + x);
	}

	if (flag == false)
	{
		str += '-';
	}

	std::reverse(str.begin(), str.end());
	return str;
}
}

// ��ֵ���õ�ʹ�ó�����
// 1. ������
// 2. ������ֵ

void func1(ljx::string s)
{}

void func2(const ljx::string& s)
{}

//int main()
//{
//	ljx::string s1("hello world");
//	// func1��func2�ĵ������ǿ��Կ�����ֵ���������������˿�����
//	// ���Ч�ʵ�ʹ�ó����ͼ�ֵ
//	func1(s1);
//	func2(s1);
//	// string operator+=(char ch) ��ֵ���ش������
//	// string& operator+=(char ch) ����ֵ����û�п��������Ч��
//	s1 += '!';
//
//	return 0;
//}

//int main()
//{
//	list<ljx::string> v;
//	ljx::string s1("1111");
//	// ������õ��ǿ�������
//	v.push_back(s1);
//
//	// ������õ����ƶ�����
//	v.push_back("2222");
//	v.push_back(std::move(s1));
//
//	return 0;
//}

// ��������
void Fun(int &x){ cout << "��ֵ����" << endl; }
void Fun(const int &x){ cout << "const ��ֵ����" << endl; }
void Fun(int &&x){ cout << "��ֵ����" << endl; }
void Fun(const int &&x){ cout << "const ��ֵ����" << endl; }

// ģ���е�&&��������ֵ���ã������������ã�����ܽ�����ֵ���ܽ�����ֵ��
// ģ�����������ֻ���ṩ���ܹ�����ͬʱ������ֵ���ú���ֵ���õ�������
// �����������͵�Ψһ���þ��������˽��յ����ͣ�����ʹ���ж��˻�������ֵ��
// ����ϣ���ܹ��ڴ��ݹ����б���������ֵ������ֵ������, ����Ҫ����������ѧϰ������ת��
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(t);
//}

//// ����ת��
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(std::forward<T>(t));
//}
//int main()
//{
//	PerfectForward(10); // ��ֵ
//	int a;
//	PerfectForward(a); // ��ֵ
//	PerfectForward(std::move(a)); // ��ֵ
//	const int b = 8;
//	PerfectForward(b); // const ��ֵ
//	PerfectForward(std::move(b)); // const ��ֵ
//	return 0;
//}

// lambda���ʽ

//int main()
//{
//	// ��򵥵�lambda���ʽ
//	[]{};
//
//	int a = 1, b = 2;
//	// ʵ��add��lambder
//	auto add1 = [](int x, int y)->int{return x + y;};
//	cout << add1(a, b) << endl;
//
//	// �ڲ�׽�б�׽a��b��û�в���������ʡ�Բ����б�����ֵ�������Ƶķ�ʽ
//	// auto add2 = [a, b]{return a + b + 10;};
//	auto add2 = [a, b]()->int{return a + b + 10;};
//	cout << add2() << endl;
//
//	// ����ˢ�����ݿ�ĿΣ�û�����ʼ����֣����ˣ�����һ��
//
//	// ���첻��ѧϰ������
//	return 0;
//}

// �ݹ���ֹ����
//template<class T>
//void ShowList(const T& t)
//{
//	cout << t << endl;
//}


//// ��ֹ����
//void ShowListArg()
//{}
//
//// չ������
//template <class T, class ...Args>
//void ShowListArg(T value, Args... args)
//{
//	cout << value << " ";
//	ShowListArg(args...);
//}
//
//template<class ...Args>
//void ShowList(Args... args)
//{
//	ShowListArg(args...);
//}

//template <class T>
//void PrintArg(T t)
//{
//	cout << t << " ";
//}
//
//// 0����ʱ��ƥ�䵽���
//void ShowList()
//{
//	cout << endl;
//}
//
//// չ������
//template<class... Args>
//void ShowList(Args... args)
//{
//	// �б��ʼ��
//	int arr[] = { (PrintArg(args), 0)... };
//	cout << endl;
//}
//
//int main()
//{
//	ShowList();
//	ShowList(1, 2, 'A');
//
//	return 0;
//}

// lambda���ʽ

//int main()
//{
//	int a = 0, b = 1;
//	//��׼д��1��
//	auto swap1 = [](int& x, int& y)->void
//	{
//		int tmp = x;
//		x= y;
//		y = tmp;
//	};
//
//	swap1(a, b);
//
//	// �������ò�׽�б���׽��ǰ�ֲ���ı���
//	// �����Ͳ��ô��λ��߼��ٴ��Σ�ʡ�Բ����ͷ���ֵ
//	auto swap2 = [&a, &b]
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//
//	swap2();
//
//	auto swap3 = [&]
//	{
//	  int tmp = a;
//	  a = b;
//	  b = tmp;
//	};
//
//	swap3();
//
//
//	return 0;
//}

//class Rate
//{
//public:
//	Rate(double rate): _rate(rate)
//	{}
//	double operator()(double money, int year)
//	{
//		return money * _rate * year;
//	}
//private:
//	double _rate;
//};
//int main()
//{
//	// ��������
//	double rate = 0.49;
//	Rate r1(rate);
//	r1(10000, 2);
//	// lambda
//	auto r2 = [=](double monty, int year)->double
//	{
//		return monty*rate*year;
//	};
//	r2(10000, 2);
//	return 0;
//}

// ��װ��
////ret = func(x);
//// ����func������ʲô�أ���ôfunc�����Ǻ�����������ָ�룿��������(�º�������)��Ҳ�п���
//// ��lamber���ʽ����������Щ���ǿɵ��õ����ͣ���˷ḻ�����ͣ����ܻᵼ��ģ���Ч�ʵ��£�
//// Ϊʲô�أ����Ǽ������¿�
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//double f(double i)
//{
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//int main()
//{
//	// ������
//	cout << useF(f, 11.11) << endl;
//	// ��������
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber���ʽ
//	cout << useF([](double d)->double{ return d/4; }, 11.11) << endl;
//	return 0;
//}

// ��װ����ʹ�÷�����
#include <functional>

int f(int a, int b)
{
	return a + b;
}

struct Functor
{
public:
	int operator() (int a, int b)
	{
		return a + b;
	}
};

class Plus
{
public:
	static int plusi(int a, int b)
	{
		return a + b;
	}
	double plusd(double a, double b)
	{
		return a + b;
	}
};
int main()
{
	// ������(����ָ��)
	std::function<int(int, int)> func1 = f;
	cout << func1(1, 2) << endl;

	// ��������
	std::function<int(int, int)> func2 = Functor();
	cout << func2(1, 2) << endl;

	// lambda���ʽ
	std::function<int(int, int)> func3 = [](const int a, const int b)
	{return a + b; };
	cout << func3(1, 2) << endl;

	// ��ĳ�Ա����

	// ��̬��Ա��ֱ�ӵ��þ�����
	std::function<int(int, int)> func4 = &Plus::plusi;
	cout << func4(1, 2) << endl;

	// �Ǿ�̬��Ա����function��ʱ��Ҫ���һ������Plus
	std::function<double(Plus, double, double)> func5 = &Plus::plusd;
	cout << func5(Plus(), 1.1, 2.2) << endl;

	return 0;
}
