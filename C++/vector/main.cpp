#include <iostream>
#include <vector>

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

int main()
{
    test_vector1();

    return 0;
}
