#include <iostream>
#include <string>
using namespace std;


//int main()
//{
//    // 三种常见的构造函数
//    string s1;
//    string s2("hello world");
//
//    // 三种遍历方式
//    // 1. 下标 + [] 也是最常用的一种遍历方式
//    for (size_t i = 0; i < s2.size(); i++)
//    {
//        // 会转化成s2.operator[](i)
//        cout << s2[i] << " ";
//    }
//    cout << endl;
//
//    // 2. 迭代器
//    // [begin(), end()) end()返回的不是最后一个数据位置的迭代器，返回是最后一个位置的下一个位置
//    // 也要注意的是：C++凡是给的迭代器，一般是给的左闭右开的区间
//    string::iterator it = s2.begin();
//    while (it != s2.end())
//    {
//        cout << *it << " ";
//        ++it;
//    }
//    cout << endl;
//
//    // 反向迭代器
//    string s3("123456");
//    string::reverse_iterator rit = s3.rbegin();
//    while (rit != s3.rend())
//    {
//        cout << *rit << " ";
//        ++rit;
//    }
//    cout << endl;
//
//    // 第三种：范围for
//    for (auto& e : s3)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

//int main()
//{
//    string s1;
//    // 尾插单个字符
//    s1.push_back('h');
//    s1.push_back('e');
//    s1.push_back('l');
//    s1.push_back('l');
//    s1.push_back('o');
//
//    // 插入字符串
//    s1.append(" world");
//    cout << s1 << endl;
//
//    // 实际中最喜欢用+=
//    s1 += ' ';
//    s1 += "比特";
//
//    cout << s1 << endl;
//
//    // 在字符串中间插入一个字符串，insert
//    // 尽量少使用insert，因为底层实现是数组，头部或者中间插入需要挪动数据
//    s1.insert(0, "x");
//    cout << s1 << endl;
//    s1.insert(3, "yyyy");
//    cout << s1 << endl;
//
//    // string的删除：erase
//    s1.erase(0, 1);
//    cout << s1 << endl;
//
//    s1.erase(0, 3);
//    cout << s1 << endl;
//
//    s1.erase(3, 10);
//    cout << s1 << endl;
//
//    // 不写默认，从3位置开始，后面的全部删完
//    s1.erase(3);
//    cout << s1 << endl;
//
//    // 什么参数都不写，默认全部都删完
//    s1.erase();
//    cout << s1 << endl;
//
//
//
//    return 0;
//}

//int main()
//{
//    // max_size
//    string s1;
//    string s2("hello world");
//    cout << s1.max_size() << endl;
//    cout << s2.max_size() << endl;
//
//    // size
//    cout << s1.size() << endl;
//    cout << s2.size() << endl;
//
//    // capacity
//    cout << s1.capacity() << endl;
//    cout << s2.capacity() << endl;
//
//    cout << s1 << endl;
//    cout << s2 << endl;
//
//    // clear
//    s1.clear();
//    s2.clear();
//
//    return 0;
//
//    return 0;
//}

//int main()
//{
//    // resize
//    string s1;
//    cout << "size:" << s1.size() << endl;
//    cout << "capacity" << s1.capacity() << endl;
//    cout << s1 << endl;
//
//    s1.resize(20, 'x');
//    cout << "size:" << s1.size() << endl;
//    cout << "capacity:" <<s1.capacity() << endl;
//    cout << s1 << endl;
//
//    string s2("hello world");
//    s2.resize(20, 'x');
//    cout << s2 << endl;
//    cout << "size:" << s1.size() << endl;
//    cout << "capacity:" << s1.capacity() << endl;
//
//    s2.resize(5);
//    cout << s2 << endl;
//    cout << "size:" << s2.size() << endl;
//    cout << "capacity:" << s2.capacity() << endl;
//    cout << endl;
//
//    // reserve
//    string s3;
//    cout << "size:" << s3.size() << endl;
//    cout << "capacity:" << s3.capacity() << endl;
//
//    s3.reserve(40);
//    cout << "size:" << s3.size() << endl;
//    cout << "capacity:" << s3.capacity() << endl;
//
//
//    return 0;
//}

int main()
{
    // c_str
    string s1("hello world");
    cout << s1 << endl;         // 调用operator<<(cout, s1)
    cout << s1.c_str() << endl; // 调用operator<<(cout, const char*)

    // 假设要求取出文件名的后缀
    // find
    string filename = "test.cpp";
    size_t pos = filename.find('.');
    if (pos != string::npos)
    {
        // 方法1：拷贝构造
//        // string suff(filename, pos, filename.size() - pos);
//        string suff(filename, pos);

        // 方法2：substr
        string suff = filename.substr(pos);
        cout << suff << endl;
    }

    return 0;
}