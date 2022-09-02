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


    return 0;
}
