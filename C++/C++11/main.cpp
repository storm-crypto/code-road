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
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(t);
//}

//// 完美转发
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(std::forward<T>(t));
//}
//int main()
//{
//	PerfectForward(10); // 右值
//	int a;
//	PerfectForward(a); // 左值
//	PerfectForward(std::move(a)); // 右值
//	const int b = 8;
//	PerfectForward(b); // const 左值
//	PerfectForward(std::move(b)); // const 右值
//	return 0;
//}

// lambda表达式

//int main()
//{
//	// 最简单的lambda表达式
//	[]{};
//
//	int a = 1, b = 2;
//	// 实现add的lambder
//	auto add1 = [](int x, int y)->int{return x + y;};
//	cout << add1(a, b) << endl;
//
//	// 在捕捉列表捕捉a、b，没有参数，可以省略参数列表，返回值可以用推的方式
//	// auto add2 = [a, b]{return a + b + 10;};
//	auto add2 = [a, b]()->int{return a + b + 10;};
//	cout << add2() << endl;
//
//	// 今天刷了数据库的课，没有做笔记那种，算了，摆烂一天
//
//	// 今天不想学习，摆烂
//	return 0;
//}

// 递归终止函数
//template<class T>
//void ShowList(const T& t)
//{
//	cout << t << endl;
//}


//// 终止函数
//void ShowListArg()
//{}
//
//// 展开函数
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
//// 0个的时候匹配到这个
//void ShowList()
//{
//	cout << endl;
//}
//
//// 展开函数
//template<class... Args>
//void ShowList(Args... args)
//{
//	// 列表初始化
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

// lambda表达式

//int main()
//{
//	int a = 0, b = 1;
//	//标准写法1：
//	auto swap1 = [](int& x, int& y)->void
//	{
//		int tmp = x;
//		x= y;
//		y = tmp;
//	};
//
//	swap1(a, b);
//
//	// 尝试利用捕捉列表，捕捉当前局部域的变量
//	// 这样就不用传参或者减少传参，省略参数和返回值
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
//	// 函数对象
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

// 包装器
////ret = func(x);
//// 上面func可能是什么呢？那么func可能是函数名？函数指针？函数对象(仿函数对象)？也有可能
//// 是lamber表达式对象？所以这些都是可调用的类型！如此丰富的类型，可能会导致模板的效率低下！
//// 为什么呢？我们继续往下看
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
//	// 函数名
//	cout << useF(f, 11.11) << endl;
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber表达式
//	cout << useF([](double d)->double{ return d/4; }, 11.11) << endl;
//	return 0;
//}

// 包装器的使用方法：
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
	// 函数名(函数指针)
	std::function<int(int, int)> func1 = f;
	cout << func1(1, 2) << endl;

	// 函数对象
	std::function<int(int, int)> func2 = Functor();
	cout << func2(1, 2) << endl;

	// lambda表达式
	std::function<int(int, int)> func3 = [](const int a, const int b)
	{return a + b; };
	cout << func3(1, 2) << endl;

	// 类的成员函数

	// 静态成员，直接调用就行了
	std::function<int(int, int)> func4 = &Plus::plusi;
	cout << func4(1, 2) << endl;

	// 非静态成员，用function的时候要多加一个参数Plus
	std::function<double(Plus, double, double)> func5 = &Plus::plusd;
	cout << func5(Plus(), 1.1, 2.2) << endl;

	return 0;
}
