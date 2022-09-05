//
// Created by 旭哥 on 2022-09-04.
//

#ifndef STRING_09_04_STRING_H
#define STRING_09_04_STRING_H

#include <cstring>
#include <iostream>

using namespace std;

namespace ljx
{
    // 管理字符串的数组，可以增删查改
    // 字符串数组的结尾有\0
    class string
    {
    public:
        string(char* str = "")
            :_str(new char[strlen(str) + 1])
        {
            strcpy(_str, str);
        }

        // 传统写法：拷贝构造和赋值重载

        // 拷贝构造
        string(const string& s)
            :_str(new char[strlen(s._str) + 1])
        {
            strcpy(_str, s._str);
        }

        // 赋值重载
        // s1 = s3
        // s1 = s1
        string& operator=(const string& s)
        {
            // 防止自己给自己赋值 s1 = s1
            if (this != &s)
            {
                delete[] _str;
                _str = new char[strlen(s._str) + 1];
                strcpy(_str, s._str);
            }
            return *this;
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
        }

        // 打印
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

        string s3("hello ljx");
        s1 = s3;
        cout << s1.c_str() << endl;
        cout << s3.c_str() << endl;
    }
}


#endif//STRING_09_04_STRING_H
