#include <iostream>
#include <string.h>
using namespace std;

//namespace bit
//{
//    class string
//    {
//    public:
//        string(const char* str)
//        {
//            _str = new char[strlen(str) + 1];
//            strcpy(_str, str);
//        }
//
//        char& operator[](size_t i)
//        {
//            return _str[i];
//        }
//
//        size_t size()
//        {
//            return strlen(_str);
//        }
//
//    private:
//        char* _str;
//    };
//}
//
//
//int main()
//{
//    bit::string s("hello world");
//    cout << s[2] << endl;
//    cout << s.operator[](2) << endl;
//
//    // 遍历
//    for (size_t i = 0; i < s.size(); i++)
//    {
//        cout << s[i] << " ";
//    }
//    cout << endl;
//
//    // 修改
//    for (size_t i = 0; i < s.size(); i++)
//    {
//        s[i] += 1;
//        cout << s[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

// 编译器的优化
class A
{
public:
    // 构造
    A()
    {
        cout << "A()" << endl;
    }
    // 析构
    ~A()
    {
        cout << "~A()" << endl;
    }
    // 拷贝构造
    A(const A& a)
    {
        cout << "A(const A& a)" << endl;
    }
    // 赋值重载
    A& operator=(const A& a)
    {
        cout << "operator=(const A& a)" << endl;
        return *this;
    }

    void Print()
    {
        cout << "Print()" << endl;
    }

};

// 测试传参返回
void f1(A aa)
{

}

// 用来测试传值返回
A f2()
{
    static A aa; // 用static的原因，出了作用域，这个变量还在，既可以用引用返回也可以用传值返回
    return aa;
}

int main()
{
//    A a1;
//    f1(a1);

    //A(); // 匿名对象
    //A().Print();

//    f1(A());

    A a4 = f2();

    return 0;
}