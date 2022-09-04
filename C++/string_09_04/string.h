//
// Created by ��� on 2022-09-04.
//

#ifndef STRING_09_04_STRING_H
#define STRING_09_04_STRING_H

#include <cstring>
#include <iostream>

using namespace std;

namespace ljx
{
    // �����ַ��������飬������ɾ���
    // �ַ�������Ľ�β��\0
    class string
    {
    public:
        string(char* str = "")
            :_str(new char[strlen(str) + 1])
        {
            strcpy(_str, str);
        }

        // ��������
        string(const string& s)
            :_str(new char[strlen(s._str) + 1])
        {
            strcpy(_str, s._str);
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
        }

        // ��ӡ
        const char* c_str()
        {
            return _str;
        }


    private:
        char* _str;
    };

    void test_string1()
    {
        string s1("hello world");
        string s2(s1);

        cout << s1.c_str() << endl;
        cout << s2.c_str() << endl;
    }
}


#endif//STRING_09_04_STRING_H
