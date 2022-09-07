#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void test_list1()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);

    // 遍历方式1
    list<int>::iterator it = lt.begin();
    while (it != lt.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    // 遍历方式二
    for (auto e : lt)
    {
        cout << e << " ";
    }
    cout << endl;


    int a[] = {16, 2, 77, 29};
    list<int> lt1(a, a + 4);
    for (auto e : lt1)
    {
        cout << e << " ";
    }
    cout << endl;

    // < 升序，如果不写默认是<
    // > 降序
    vector<int> v(a, a + 4);
    sort(v.begin(), v.end());
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(), greater<int>()); // 原理后面讲，先会用, 这个是降序
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;


}

// 通用的打印函数
template<class Con>
void PrintContainer(const Con& c)
{
    auto it = c.begin();
    while (it != c.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

void test_list2()
{
    list<int> lt;
    lt.push_back(10);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);

//    lt.assign(10, 5);

    PrintContainer(lt);

    // insert + find配合使用
    auto pos = find(lt.begin(), lt.end(), 3);
    lt.insert(pos, 30);
    PrintContainer(lt);

}

int main()
{
//    test_list1();
    test_list2();

    return 0;
}
