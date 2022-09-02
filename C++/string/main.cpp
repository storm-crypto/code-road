#include <iostream>
#include <string>
using namespace std;


int main()
{
    // 三种常见的构造函数
    string s1;
    string s2("hello world");

    // 三种遍历方式
    // 1. 下标 + [] 也是最常用的一种遍历方式
    for (size_t i = 0; i < s2.size(); i++)
    {
        // 会转化成s2.operator[](i)
        cout << s2[i] << " ";
    }
    cout << endl;

    // 2. 迭代器
    // [begin(), end()) end()返回的不是最后一个数据位置的迭代器，返回是最后一个位置的下一个位置
    // 也要注意的是：C++凡是给的迭代器，一般是给的左闭右开的区间
    string::iterator it = s2.begin();
    while (it != s2.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    return 0;
}
