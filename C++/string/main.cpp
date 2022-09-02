#include <iostream>
#include <string>
using namespace std;


int main()
{
    // 三种常见的构造函数
    string s1;
    string s2("hello world");
    string s3(s2);
    string s4 = "hello world"; // 这种方式跟s2的那种构造方法是一样的

    // 拷贝已存在字符串的部分子串
    string s5(s4, 0, 5);
    cout << s5 << endl;

    string s6("123456", 3);
    cout << s6 << endl;

    string s7(10, 'x');
    cout << s7 << endl;

    s7 = s2;
    cout << s7 << endl;

    return 0;
}
