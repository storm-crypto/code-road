//
// Created by 旭哥 on 2022-09-04.
//

#ifndef STRING_09_04_STRING_H
#define STRING_09_04_STRING_H

#include <cstring>
#include <iostream>
#include <assert.h>

using namespace std;

namespace ljx {
    // 管理字符串的数组，可以增删查改
    // 字符串数组的结尾有\0
    class string {
    public:
        typedef char *iterator;

        iterator begin() {
            return _str;
        }

        iterator end() {
            return _str + _size;
        }


        string(char *str = "")
            : _str(new char[strlen(str) + 1]) {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];// 多一个是给\0的

            strcpy(_str, str);
        }

        // 传统写法：拷贝构造和赋值重载

        // 拷贝构造
        //        string(const string& s)
        //            :_str(new char[strlen(s._str) + 1])
        //        {
        //            strcpy(_str, s._str);
        //        }
        //
        //        // 赋值重载
        //        // s1 = s3
        //        // s1 = s1
        //        string& operator=(const string& s)
        //        {
        //            // 防止自己给自己赋值 s1 = s1
        //            if (this != &s)
        //            {
        //                delete[] _str;
        //                _str = new char[strlen(s._str) + 1];
        //                strcpy(_str, s._str);
        //            }
        //            return *this;
        //        }

        void swap(string &s) {
            // 如果左边没有给命名空间，说明它修饰的是全局的，用的是全局的swap
            ::swap(_str, s._str);
            ::swap(_size, s._size);
            ::swap(_capacity, s._capacity);
        }

        // 现代写法
        string(const string &s)
            : _str(nullptr), _size(0), _capacity(0) {
            string tmp(s._str);
            //            swap(_str, tmp._str);
            //            swap(_size, tmp._size);
            //            swap(_capacity, tmp._capacity);
            //this->swap(tmp);
            swap(tmp);
        }

        string &operator=(string s) {
            //            swap(_str, s._str);
            //            swap(_size, s._size);
            //            swap(_capacity, s._capacity);
            swap(s);

            return *this;
        }

        ~string() {
            delete[] _str;
            _str = nullptr;
            _size = 0;
            _capacity = 0;
        }

        // 遍历
        // const版本 只读
        const char &operator[](size_t i) const {
            assert(i < _size);

            return _str[i];
        }

        // 非const版本 可读可写
        char &operator[](size_t i) {
            assert(i < _size);

            return _str[i];
        }

        // 开capacity
        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char *tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;

                _str = tmp;
                _capacity = n;
            }
        }

        // 开空间 + 初始化， 改变size
        void resize(size_t n, char val = '\0')
        {
            if (n < _size)
            {
                _size = 3;
                _str[_size] = '\0';
            }
            else
            {
                if (n > _capacity)
                {
                    reserve(n);
                }

                for (size_t i = _size; i < n; i++)
                {
                    _str[i] = val;
                }
                _str[n] = '\0';
                _size = n;
            }
        }

        void push_back(char ch)
        {
            if (_size == _capacity)
            {
                reserve(_capacity * 2);
            }
            _str[_size] = ch;
            _str[_size + 1] = '\0';
            ++_size;
        }

        void append(const char *str)
        {
            // 先计算以用需要多少空间
            size_t len = _size + strlen(str);
            if (len > _capacity)
            {
                reserve(len);
            }

            strcpy(_str + _size, str);
            _size = len;
        }

        // += 字符
        string &operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }

        // +=字符串
        string &operator+=(const char *str)
        {
            append(str);
            return *this;
        }


        // pos位置之前插入字符串
        string& insert(size_t pos, char* str)
        {

        }

        // pos位置之前插入一个字符
        string& insert(size_t pos, char ch)
        {
            assert(pos <= _size);

            if (_size == _capacity)
            {
                reserve(2 * _capacity);
            }

            size_t end =  _size;
            while (end >= pos)
            {
                _str[end + 1] = _str[end];
                --end;
            }
            _str[pos] = ch;
            _size++;

            return *this;
        }

        size_t size() const
        {
            return _size;
        }

        // 打印
        const char *c_str() const
        {
            return _str;
        }


    private:
        char *_str;
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

        for (size_t i = 0; i < s1.size(); i++) {
            cout << s1[i] << " ";
        }
        cout << endl;
    }

    void test_string3()
    {
        string s1("hello world");
        string::iterator it = s1.begin();
        while (it != s1.end()) {
            cout << *it << " ";
            it++;
        }
        cout << endl;

        // 看起来很神奇，原理很简单，范围for会被编译器替换成迭代器的形式
        // 也就是说范围for是由迭代器支持的
        for (auto ch : s1) {
            cout << ch << " ";
        }
        cout << endl;
    }

    void test_string4()
    {
        string s1("hello");
        s1 += '!';

        s1.resize(8, 'x');
        cout << s1.c_str() << endl;

        s1.resize(15, 'y');
        cout << s1.c_str() << endl;

        s1.resize(3);
        cout << s1.c_str() << endl;


    }


}
#endif//STRING_09_04_STRING_H
