#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

    // ����1
    for (size_t i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    // ����2
    vector<int>::iterator it1 = v1.begin();
    while (it1 != v1.end())
    {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;

    // ����3(�Զ��жϽ������Զ�����++)
    // ��������ţ�ƣ�ʵ���Ͼ��Ǳ��滻���˵�����
    for (auto e : v1)
    {
        cout << e << " ";
    }
    cout << endl;

    PrintVector(v1);
}

// ���캯��
void test_vector2()
{
    vector<int> v1;
    vector<int> v2(10, 0);
    // ��������ʼ��
    vector<int> v3(v2.begin(), v2.end());

    string s("hello world");
    vector<char> v4(s.begin(), s.end());

    vector<string> v5;

    // �Ƽ�д����
    v5.push_back("erase");
    v5.push_back(string("insert"));

    PrintVector(v1);
    PrintVector(v2);
    PrintVector(v3);
    PrintVector(v4);
    PrintVector(v5);

    // ��������
    vector<string> copy(v5);
    PrintVector(copy);

    auto rit = copy.rbegin();
    while (rit != copy.rend())
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
}

void test_vector3()
{
    // ��֤vector�����ݷ�ʽ
    size_t sz;
    std::vector<int> foo;
    sz = foo.capacity();
    cout << "making foo grow:\n";
    for (int i = 0; i < 100; i++)
    {
        foo.push_back(i);
        if (sz != foo.capacity())
        {
            sz = foo.capacity();
            cout << "capacity changed: " << sz << '\n';
        }
    }

    vector<int> v1;
    v1.reserve(10);

    vector<int> v2;
    v2.resize(10, 2);
}

void test_vector5()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    // ͷ��
    v.insert(v.begin(), 0);

    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    // ͷɾ
    v.erase(v.begin());
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    // find��ʹ��
    // ��3��ǰ�����30
    auto pos = find(v.begin(), v.end(), 3);
    if (pos != v.end())
    {
        v.insert(pos, 30);
    }
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    // ɾ��3
    // pos��insert֮���ʧЧ�ˣ��������ǲ�Ҫ����
    pos = find(v.begin(), v.end(), 3);
    v.erase(pos);
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

}

void test_vector6()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    // Ҫ��ɾ��vector�����е�ż��
    auto it = v.begin();
    while (it != v.end())
    {
        if (*it % 2 == 0)
        {
            // erase(it)�Ժ�itʧЧ������++
            // erase�᷵��ɾ��λ��it����һ��λ��
            v.erase(it);
        }
        else
        {
            ++it;
        }

    }

    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

}

void test_vector7()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);

    // C++98�Ƽ��ڶ���
    // ��Ϊ��һ��Ҫ����������������ۺܴ�
    swap(v1, v2);
    v1.swap(v2);

    // C++11�ж�һ��


}

int main()
{
//    test_vector1();
//    test_vector2();
//    test_vector3();
//    test_vector5();
    test_vector6();

    return 0;
}
