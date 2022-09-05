#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PrintVector(const vector<int>& v)
{
    vector<int>::const_iterator it1 = v.begin();
    while (it1 != v.end())
    {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;
}

template<class T>
void PrintVector(const vector<T>& v)
{
    auto it1 = v.begin();
    while (it1 != v.end())
    {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;
}

void test_vector1()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    // 遍历1
    for (size_t i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    // 遍历2
    vector<int>::iterator it1 = v1.begin();
    while (it1 != v1.end())
    {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;

    // 遍历3(自动判断结束，自动迭代++)
    // 看起来很牛逼，实际上就是被替换成了迭代器
    for (auto e : v1)
    {
        cout << e << " ";
    }
    cout << endl;

    PrintVector(v1);
}

// 构造函数
void test_vector2()
{
    vector<int> v1;
    vector<int> v2(10, 0);
    // 迭代器初始化
    vector<int> v3(v2.begin(), v2.end());

    string s("hello world");
    vector<char> v4(s.begin(), s.end());

    vector<string> v5;

    // 推荐写法：
    v5.push_back("erase");
    v5.push_back(string("insert"));

    PrintVector(v1);
    PrintVector(v2);
    PrintVector(v3);
    PrintVector(v4);
    PrintVector(v5);

    // 拷贝构造
    vector<string> copy(v5);
    PrintVector(copy);
}

int main()
{
//    test_vector1();
    test_vector2();

    return 0;
}
