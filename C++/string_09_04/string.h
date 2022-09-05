//
// Created by ��� on 2022-09-04.
//

#ifndef STRING_09_04_STRING_H
#define STRING_09_04_STRING_H

#include <cstring>
#include <iostream>
#include <assert.h>

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
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1]; // ��һ���Ǹ�\0��

            strcpy(_str, str);
        }

        // ��ͳд������������͸�ֵ����

        // ��������
//        string(const string& s)
//            :_str(new char[strlen(s._str) + 1])
//        {
//            strcpy(_str, s._str);
//        }
//
//        // ��ֵ����
//        // s1 = s3
//        // s1 = s1
//        string& operator=(const string& s)
//        {
//            // ��ֹ�Լ����Լ���ֵ s1 = s1
//            if (this != &s)
//            {
//                delete[] _str;
//                _str = new char[strlen(s._str) + 1];
//                strcpy(_str, s._str);
//            }
//            return *this;
//        }

        void swap(string& s)
        {
            // ������û�и������ռ䣬˵�������ε���ȫ�ֵģ��õ���ȫ�ֵ�swap
            ::swap(_str, s._str);
            ::swap(_size, s._size);
            ::swap(_capacity, s._capacity);
        }

        // �ִ�д��
        string(const string& s)
            :_str(nullptr)
            , _size(0)
            , _capacity(0)
        {
            string tmp(s._str);
//            swap(_str, tmp._str);
//            swap(_size, tmp._size);
//            swap(_capacity, tmp._capacity);
            //this->swap(tmp);
            swap(tmp);
        }

        string& operator=(string s)
        {
//            swap(_str, s._str);
//            swap(_size, s._size);
//            swap(_capacity, s._capacity);
            swap(s);

            return *this;
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _size = 0;
            _capacity = 0;
        }

        // ����
        // const�汾 ֻ��
        const char& operator[](size_t i) const
        {
            assert(i < _size);

            return _str[i];
        }

        // ��const�汾 �ɶ���д
         char& operator[](size_t i)
        {
            assert(i < _size);

            return _str[i];
        }

        size_t size() const
        {
            return _size;
        }

        // ��ӡ
        const char* c_str() const
        {
            return _str;
        }


    private:
        char* _str;
        size_t _size;
        size_t _capacity;
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

    void test_string2()
    {
        string s1("hello world");
        s1[0] = 'x';
        cout << s1[1] << endl;

        cout << s1.c_str() << endl;

        for (size_t i = 0; i < s1.size(); i++)
        {
            cout << s1[i] << " " ;
        }
        cout << endl;
    }

    void test_string3()
    {
        string s1("hello world");
        string::iterator it = s1.begin();
        while (it != s1.end())
        {
            cout << *it << " ";
            it++;
    }
}


#endif//STRING_09_04_STRING_H
