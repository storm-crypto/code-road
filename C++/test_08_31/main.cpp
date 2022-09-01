#include <iostream>
using namespace std;

//class Date
//{
//public:
//    Date(int year = 0, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    bool operator==(const Date& d) const
//    {
//        return _year == d._year
//        && _month == d._month
//        && _day == d._day;
//    }
//
//    void Print() const
//    {
//        cout << _year << "年" << _month << "月" << _day << "日" << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//int main()
//{
//    Date d1(2021, 5, 27);
//    Date d2(2021, 5, 27);
//
//
//    return 0;
//}


//class Date
//{
//public:
//    Date(int year = 0, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    // 了解一下
//    // 他们基本没有被自己实现的价值
//    // 可以不自己写，编译器默认生成的就够用了
//    Date* operator&()
//    {
//        return this;
//    }
//
//    const Date* operator&() const
//    {
//        return this;
//    }
//
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//int main()
//{
//    Date d1(2021, 5, 27);
//    Date d2(2021, 5, 27);
//
//
//    return 0;
//}

//class Date
//{
//    // 友元函数的声明
//    friend ostream& operator<<(ostream& out, const Date& d);
//    friend istream& operator>>(istream& in, Date& d);
//
//public:
//    Date(int year = 0, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//// cout << d1;
//ostream& operator<<(ostream& out, const Date& d)
//{
//    out << d._year << "-" << d._month << "-" << d._day << endl;
//    return out;
//}
//
//// cin >> d1
//istream& operator>>(istream& in,  Date& d)
//{
//    in >> d._year >> d._month >> d._day;
//    return in;
//}
//
//
//int main()
//{
//    Date d1;
//    //cin >> d1;
//    cout << d1;
//
//    return 0;
//}

//class A
//{
//public:
//    A(int a)
//        :_a(a)
//    {}
//
//private:
//    int _a;
//};
//
//int main()
//{
//    A aa1(1); // 拷贝构造
//    // 单参数的构造函数，支持这样的隐式类型转换
//    A aa2 = 2;
//    // 用了explicit就不能用上面那种隐式类型转换了
//
//
//    return 0;
//}
//
//int main()
//{
//    A aa1(1);  // 标准的构造函数调用，定义有名对象
//    A aa2 = 2; // 隐式类型转换，编译器优化后，也是直接调的构造
//    A(3);      // 构造匿名对象,这个对象没有名字， 声明周期只在这一行，这行后就要调析构函数了
//}

// 静态成员

// 面试题：计算一个程序中定义了多少个对象出来
//class A
//{
//public:
//    A()
//    {
//        ++_n;
//    }
//
//    // 拷贝构造
//    A(const A& a)
//    {
//        ++_n;
//    }
//
//    // 跟普通成员的区别：没有this指针，不能访问非静态成员
//    static int GetN()
//    {
//        return _n;
//    }
//
//private:
//    // 这里是声明，不是在构造函数初始化,要在类外面全局位置初始化
//    static int _n;  // n存在静态区，属于整个类，也属于类的所有对象
//};
//
//// 静态成员变量的初始化，规定是在类外面这样初始化的
//int A::_n = 0;
//
//int main()
//{
//    A a1;
//    A a2(a1);
//    //cout << sizeof(A) << endl;
//
//    cout << a1.GetN() << endl;
//
//    return 0;
//}

//
//class Add {
//    friend class Solution;
//public:
//    Add()
//    {
//        _ret += _i;
//        _i++;
//    }
//
//    static void Init()
//    {
//        _i = 1;
//        _ret = 0;
//    }
//
//private:
//    static int _i;
//    static int _ret;
//};
//
//int Add::_i = 1;
//int Add::_ret = 0;
//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        // 初始化
//        Add::_ret = 0;
//        Add::_i = 1;
//
//        Add arr[n];
//
//        return Add::_ret;
//    }
//};

//class B
//{
//public:
//    B()
//        :_x(0)
//    {
//        cout << "B()" << endl;
//    }
//
//private:
//    int _x;
//
//};
//
//class A {
//public:
//    //
//    A(int a = 1, int* p = nullptr)
////        : _a(a)
////    , _p(p)
//    {
//
//    }
//private:
//    // 这里是声明 如果没有构造函数那里没有初始化，就用这里的缺省值
//    int _a = 0;
//    int* _p = nullptr;
//
//    B _b;
//};
//
//int main()
//{
//    A aa; // 默认构造函数
//
//
//    return 0;
//}

// 用C语言定义一个栈
// 用C++定义一个栈对比感受一下

//struct StackC
//{
//    int* a;
//    int _top;
//    int _capacity;
//};
//
//void StackInit(struct StackC* ps, int n);
//void StackDestroy(struct StackC* ps);
//void StackPush(struct StackC* ps, int x);
//
//void TestStackC()
//{
//    struct StackC st;
//    StackInit(&st, 4);
//    StackPush(&st, 1);
//    StackPush(&st, 2);
//    StackPush(&st, 3);
//    StackPush(&st, 4);
//
//    StackDestroy(&st);
//
//}
//
//// C++实现一个栈
//class StackCPP
//{
//public:
//    StackCPP(int n = 4)
//    {
//
//    }
//
//    ~StackCPP()
//    {
//
//    }
//
//    void Push(int x)
//    {
//
//    }
//
//private:
//    int* _a;
//    int _top;
//    int _capacity;
//};
//
//void TestStackCPP()
//{
//    // 自动调用构造函数，用完后自动析构
//    StackCPP st;
//
//    st.Push(1);
//    st.Push(2);
//    st.Push(3);
//    st.Push(4);
//}

int main()
{
    // 申请一个10个int的数组
    int* p1 = (int*)malloc(sizeof(int) * 10);
    int* p2 = new int[10];

    free(p1);
    delete[] p2;

    // 申请单个int对象
    int* p3 = (int*)malloc(sizeof(int) * 10);
    int* p4= new int;

    free(p3);
    delete p4;
}