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


    return 0;
}
