#include <iostream>
#include <string>
using namespace std;


//int main()
//{
//    // ���ֳ����Ĺ��캯��
//    string s1;
//    string s2("hello world");
//
//    // ���ֱ�����ʽ
//    // 1. �±� + [] Ҳ����õ�һ�ֱ�����ʽ
//    for (size_t i = 0; i < s2.size(); i++)
//    {
//        // ��ת����s2.operator[](i)
//        cout << s2[i] << " ";
//    }
//    cout << endl;
//
//    // 2. ������
//    // [begin(), end()) end()���صĲ������һ������λ�õĵ����������������һ��λ�õ���һ��λ��
//    // ҲҪע����ǣ�C++���Ǹ��ĵ�������һ���Ǹ�������ҿ�������
//    string::iterator it = s2.begin();
//    while (it != s2.end())
//    {
//        cout << *it << " ";
//        ++it;
//    }
//    cout << endl;
//
//    // ���������
//    string s3("123456");
//    string::reverse_iterator rit = s3.rbegin();
//    while (rit != s3.rend())
//    {
//        cout << *rit << " ";
//        ++rit;
//    }
//    cout << endl;
//
//    // �����֣���Χfor
//    for (auto& e : s3)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

int main()
{
    string s1;
    // β�嵥���ַ�
    s1.push_back('h');
    s1.push_back('e');
    s1.push_back('l');
    s1.push_back('l');
    s1.push_back('o');

    // �����ַ���
    s1.append(" world");
    cout << s1 << endl;

    // ʵ������ϲ����+=
    s1 += ' ';
    s1 += "����";

    cout << s1 << endl;

    // ���ַ����м����һ���ַ�����insert
    // ������ʹ��insert����Ϊ�ײ�ʵ�������飬ͷ�������м������ҪŲ������
    s1.insert(0, "x");
    cout << s1 << endl;
    s1.insert(3, "yyyy");
    cout << s1 << endl;

    // string��ɾ����erase
    s1.erase(0, 1);
    cout << s1 << endl;

    s1.erase(0, 3);
    cout << s1 << endl;

    s1.erase(3, 10);
    cout << s1 << endl;

    // ��дĬ�ϣ���3λ�ÿ�ʼ�������ȫ��ɾ��
    s1.erase(3);
    cout << s1 << endl;

    // ʲô��������д��Ĭ��ȫ����ɾ��
    s1.erase();
    cout << s1 << endl;



    return 0;
}
