#include <iostream>
#include <assert.h>
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
//
//int main()
//{
//    // 申请一个10个int的数组
//    int* p1 = (int*)malloc(sizeof(int) * 10);
//    int* p2 = new int[10];
//
//    free(p1);
//    delete[] p2;
//
//    // 申请单个int对象
//    int* p3 = (int*)malloc(sizeof(int) * 10);
//    int* p4= new int;
//
//    free(p3);
//    delete p4;
//}

//struct ListNode
//{
//    //struct ListNode* _next; // C语言是这样写的，C++可以按照下面这样写
//    ListNode* _next;
//    ListNode* _prev;
//    int _val;
//
//    // 构造函数
//    ListNode(int val = 0)
//        :_next(nullptr)
//        , _prev(nullptr)
//        , _val(val)
//    {}
//};
//
//int main()
//{
//    // C malloc只是开空间
//    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    free(n1);
//
//    // C++ new 针对自定义类型，开空间+构造函数初始化
//    // delete针对自定义类型，析构函数清理+释放空间
//    ListNode* n2 = new ListNode(5);
//    delete n2;
//
//    struct ListNode* arr3 = (struct ListNode*)malloc(sizeof(struct ListNode) * 4);
//    free(arr3);
//
//    ListNode* arr4 = new ListNode[4]{1, 2, 3, 4};
//    delete[] arr4;
//
//    return 0;
//}


//struct ListNode
//{
//    //struct ListNode* _next; // C语言是这样写的，C++可以按照下面这样写
//    ListNode* _next;
//    ListNode* _prev;
//    int _val;
//
//    // 构造函数
//    ListNode(int val = 0)
//        :_next(nullptr)
//        , _prev(nullptr)
//        , _val(val)
//    {}
//};
//
//int main()
//{
//    ListNode* p1 = (ListNode*)malloc(sizeof(ListNode));
//    free(p1);
//
//    ListNode* p2 = (ListNode*)operator new(sizeof(ListNode));
//    operator delete (p2);
//
//    return 0;
//}

// 定位new
//class A
//{
//public:
//    A(int a = 0)
//        :_data(a)
//    {
//        cout << "A()"<< this << endl;
//    }
//
//    ~A()
//    {
//        cout << "~A()" << this << endl;
//    }
//
//private:
//    int _data;
//};
//
//int main()
//{
//    A* p = (A*)malloc(sizeof(A));
//
//    // 定位new对对象进行赋值
//    new(p) A(1);
//
//    return 0;
//}

// 泛型编程 -- 模板

//// 函数模板
//// template<class T>
//template<typename T> // 定义模板参数T可以用typename，也可以用class，都一样，一般用class
//void Swap(T&x1, T&x2)
//{
//    T tmp = x1;
//    x1 = x2;
//    x2 = tmp;
//}
//
//int main()
//{
//    int a = 1, b = 2;
//    Swap(a, b);
//
//    double c = 1.1, d = 2.2;
//    Swap(c, d);
//
//
//    return 0;
//}

//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//    return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//    return left + right;
//}
//void Test()
//{
//    Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//    Add<int>(1, 2); // 调用编译器特化的Add版本
//}

//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//    return left + right;
//}
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//    return left + right;
//}
//void Test()
//{
//    Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//    Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}

// 类模板
template<class T>
class vector
{
public:
    // 构造函数
    vector()
        : _a(nullptr)
        , _size(0)
        , _capacity(0)
    {}

    // 析构函数
    ~vector()
    {
        delete[] _a;
        _size = _capacity = 0;
    }

    void push_back(const T& x)
    {
        if (_size == _capacity)
        {
            int newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
            T* tmp = new T[newcapacity];
            if (_a)
            {
                memcpy(tmp, _a, sizeof(T) * _size);
                delete[] _a;
            }
            _a = tmp;
            _capacity = newcapacity;
        }

        _a[_size] = x;
    }

    T& operator[](size_t pos)
    {
        assert(pos < _size);
        return _a[pos];
    }

    size_t size()
    {
        return _size;
    }


private:
    T* _a;
    int _size;
    int _capacity;

};

int main()
{
    vector<int> v1; // int
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    vector<double> v2; // double
    v2.push_back(1.1);
    v2.push_back(2.2);
    v2.push_back(3.3);
    v2.push_back(4.4);

    return 0;
}


