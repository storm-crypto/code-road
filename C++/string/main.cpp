#include <iostream>
#include <string>
using namespace std;


int main()
{
    // ���ֳ����Ĺ��캯��
    string s1;
    string s2("hello world");

    // ���ֱ�����ʽ
    // 1. �±� + [] Ҳ����õ�һ�ֱ�����ʽ
    for (size_t i = 0; i < s2.size(); i++)
    {
        // ��ת����s2.operator[](i)
        cout << s2[i] << " ";
    }
    cout << endl;

    // 2. ������
    // [begin(), end()) end()���صĲ������һ������λ�õĵ����������������һ��λ�õ���һ��λ��
    // ҲҪע����ǣ�C++���Ǹ��ĵ�������һ���Ǹ�������ҿ�������
    string::iterator it = s2.begin();
    while (it != s2.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    return 0;
}
