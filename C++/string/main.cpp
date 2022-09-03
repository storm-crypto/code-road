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

//int main()
//{
//    string s1;
//    // β�嵥���ַ�
//    s1.push_back('h');
//    s1.push_back('e');
//    s1.push_back('l');
//    s1.push_back('l');
//    s1.push_back('o');
//
//    // �����ַ���
//    s1.append(" world");
//    cout << s1 << endl;
//
//    // ʵ������ϲ����+=
//    s1 += ' ';
//    s1 += "����";
//
//    cout << s1 << endl;
//
//    // ���ַ����м����һ���ַ�����insert
//    // ������ʹ��insert����Ϊ�ײ�ʵ�������飬ͷ�������м������ҪŲ������
//    s1.insert(0, "x");
//    cout << s1 << endl;
//    s1.insert(3, "yyyy");
//    cout << s1 << endl;
//
//    // string��ɾ����erase
//    s1.erase(0, 1);
//    cout << s1 << endl;
//
//    s1.erase(0, 3);
//    cout << s1 << endl;
//
//    s1.erase(3, 10);
//    cout << s1 << endl;
//
//    // ��дĬ�ϣ���3λ�ÿ�ʼ�������ȫ��ɾ��
//    s1.erase(3);
//    cout << s1 << endl;
//
//    // ʲô��������д��Ĭ��ȫ����ɾ��
//    s1.erase();
//    cout << s1 << endl;
//
//
//
//    return 0;
//}

//int main()
//{
//    // max_size
//    string s1;
//    string s2("hello world");
//    cout << s1.max_size() << endl;
//    cout << s2.max_size() << endl;
//
//    // size
//    cout << s1.size() << endl;
//    cout << s2.size() << endl;
//
//    // capacity
//    cout << s1.capacity() << endl;
//    cout << s2.capacity() << endl;
//
//    cout << s1 << endl;
//    cout << s2 << endl;
//
//    // clear
//    s1.clear();
//    s2.clear();
//
//    return 0;
//
//    return 0;
//}

//int main()
//{
//    // resize
//    string s1;
//    cout << "size:" << s1.size() << endl;
//    cout << "capacity" << s1.capacity() << endl;
//    cout << s1 << endl;
//
//    s1.resize(20, 'x');
//    cout << "size:" << s1.size() << endl;
//    cout << "capacity:" <<s1.capacity() << endl;
//    cout << s1 << endl;
//
//    string s2("hello world");
//    s2.resize(20, 'x');
//    cout << s2 << endl;
//    cout << "size:" << s1.size() << endl;
//    cout << "capacity:" << s1.capacity() << endl;
//
//    s2.resize(5);
//    cout << s2 << endl;
//    cout << "size:" << s2.size() << endl;
//    cout << "capacity:" << s2.capacity() << endl;
//    cout << endl;
//
//    // reserve
//    string s3;
//    cout << "size:" << s3.size() << endl;
//    cout << "capacity:" << s3.capacity() << endl;
//
//    s3.reserve(40);
//    cout << "size:" << s3.size() << endl;
//    cout << "capacity:" << s3.capacity() << endl;
//
//
//    return 0;
//}

int main()
{
    // c_str
    string s1("hello world");
    cout << s1 << endl;         // ����operator<<(cout, s1)
    cout << s1.c_str() << endl; // ����operator<<(cout, const char*)

    // ����Ҫ��ȡ���ļ����ĺ�׺
    // find
    string filename = "test.cpp";
    size_t pos = filename.find('.');
    if (pos != string::npos)
    {
        // ����1����������
//        // string suff(filename, pos, filename.size() - pos);
//        string suff(filename, pos);

        // ����2��substr
        string suff = filename.substr(pos);
        cout << suff << endl;
    }

    return 0;
}