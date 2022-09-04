#include <iostream>
#include <string.h>
using namespace std;

//namespace bit
//{
//    class string
//    {
//    public:
//        string(const char* str)
//        {
//            _str = new char[strlen(str) + 1];
//            strcpy(_str, str);
//        }
//
//        char& operator[](size_t i)
//        {
//            return _str[i];
//        }
//
//        size_t size()
//        {
//            return strlen(_str);
//        }
//
//    private:
//        char* _str;
//    };
//}
//
//
//int main()
//{
//    bit::string s("hello world");
//    cout << s[2] << endl;
//    cout << s.operator[](2) << endl;
//
//    // ����
//    for (size_t i = 0; i < s.size(); i++)
//    {
//        cout << s[i] << " ";
//    }
//    cout << endl;
//
//    // �޸�
//    for (size_t i = 0; i < s.size(); i++)
//    {
//        s[i] += 1;
//        cout << s[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

// ���������Ż�
class A
{
public:
    // ����
    A()
    {
        cout << "A()" << endl;
    }
    // ����
    ~A()
    {
        cout << "~A()" << endl;
    }
    // ��������
    A(const A& a)
    {
        cout << "A(const A& a)" << endl;
    }
    // ��ֵ����
    A& operator=(const A& a)
    {
        cout << "operator=(const A& a)" << endl;
        return *this;
    }

    void Print()
    {
        cout << "Print()" << endl;
    }

};

// ���Դ��η���
void f1(A aa)
{

}

// �������Դ�ֵ����
A f2()
{
    static A aa; // ��static��ԭ�򣬳�������������������ڣ��ȿ��������÷���Ҳ�����ô�ֵ����
    return aa;
}

int main()
{
//    A a1;
//    f1(a1);

    //A(); // ��������
    //A().Print();

//    f1(A());

    A a4 = f2();

    return 0;
}