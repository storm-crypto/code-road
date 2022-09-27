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
//	// C++11开始进行赋值的时候也可以不使用=
//	Point p1 = {1, 2};
//	Point p2{1, 2};
//
//	// 甚至初始化整型的时候也可以不用等号
//	int x1 = 1;
//	int x2{2};
//
//	int* p3 = new int[4]{0};
//	int* p4 = new int[4]{1, 2, 3, 4};
//
//	Date d1;
//	Date d2(2022, 9, 27);
//	// 这里虽然可以这样用，但是不建议这样使用，这种做法是为其他地方做准备的
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
//	// 越界检查更严格
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
//	// 右值引用
//	double x = 1.1, y = 2.2;
//// 以下几个都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//// 以下几个都是对右值的右值引用
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//// 这里编译会报错：error C2106: “=”: 左操作数必须为左值
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
//	// int& ra2 = 10; // 编译失败：左值引用不能引用右值
//
//	const int& ra3 = 10; // 加了const的左值引用可以引用右值
//}

//int main()
//{
//	// 右值引用只能右值，不能引用左值。
//	int&& r1 = 10;
//	// error C2440: “初始化”: 无法从“int”转换为“int &&”
//	// message : 无法将左值绑定到右值引用
//	int a = 10;
//	int&& r2 = a;
//
//	// 右值引用可以引用move以后的左值
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

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;
			string tmp(s._str);
			swap(tmp);
		}

		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}

		// 移动构造
		string(string&& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			cout << "string(string&& s) -- 移动语义" << endl;
			swap(s);
		}

		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动语义" << endl;
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
		size_t _capacity; // 不包含最后做标识的\0
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

// 左值引用的使用场景：
// 1. 做参数
// 2. 做返回值

void func1(ljx::string s)
{}

void func2(const ljx::string& s)
{}

//int main()
//{
//	ljx::string s1("hello world");
//	// func1和func2的调用我们可以看到左值引用做参数减少了拷贝，
//	// 提高效率的使用场景和价值
//	func1(s1);
//	func2(s1);
//	// string operator+=(char ch) 传值返回存在深拷贝
//	// string& operator+=(char ch) 传左值引用没有拷贝提高了效率
//	s1 += '!';
//
//	return 0;
//}

//int main()
//{
//	list<ljx::string> v;
//	ljx::string s1("1111");
//	// 这里调用的是拷贝构造
//	v.push_back(s1);
//
//	// 下面调用的是移动构造
//	v.push_back("2222");
//	v.push_back(std::move(s1));
//
//	return 0;
//}

// 万能引用
void Fun(int &x){ cout << "左值引用" << endl; }
void Fun(const int &x){ cout << "const 左值引用" << endl; }
void Fun(int &&x){ cout << "右值引用" << endl; }
void Fun(const int &&x){ cout << "const 右值引用" << endl; }

// 模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值。
// 模板的万能引用只是提供了能够接收同时接收左值引用和右值引用的能力，
// 但是引用类型的唯一作用就是限制了接收的类型，后续使用中都退化成了左值，
// 我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要用我们下面学习的完美转发
template<typename T>
void PerfectForward(T&& t)
{
	Fun(t);
}
int main()
{
	PerfectForward(10); // 右值
	int a;
	PerfectForward(a); // 左值
	PerfectForward(std::move(a)); // 右值
	const int b = 8;
	PerfectForward(b); // const 左值
	PerfectForward(std::move(b)); // const 右值
	return 0;
}
