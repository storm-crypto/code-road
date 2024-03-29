//
// Created by 旭哥 on 2022-09-06.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <cassert>
#include <iostream>

using namespace std;

namespace ljx
{
    template <class T>
    class vector
    {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;

        vector()
            :_start(nullptr)
            , _finish(nullptr)
            , _endofstorage(nullptr)
        {}

        // swap函数
        // v1.swap(v2)
        void swap(vector<T> v)
        {
            ::swap(_start, v._start);
            ::swap(_finish, v._finish);
            ::swap(_endofstorage, v._endofstorage);
        }

        // 现代写法：
        // v1 = v3;
        vector<T>& operator=(const vector<T>& v)
        {
            swap(v);

            return *this;
        }

        ~vector()
        {
            if (_start)
            {
                delete[] _start;
            }

            _start = _finish = _endofstorage = nullptr;
        }

        size_t capacity() const
        {
            return _endofstorage - _start;
        }

        size_t size() const
        {
            return _finish - _start;
        }

        // 拷贝构造
        vector(const vector<T>& v)
            :_start(nullptr)
            , _finish(nullptr)
            , _endofstorage(nullptr)
        {
            _start = new T[v.capacity()];
            //memcpy(_start, v._start, sizeof(T) * v.size());
            // memcpy对于深拷贝的自定义类型会出bug
            // memcpy(tmp, _start, sz * sizeof(T));
            // 改进如下：
            for (size_t i = 0; i < v.size(); i++)
            {
                _start[i] = v._start[i];
            }
            _endofstorage = _start + v.capacity();
            _finish = _start + v.size();
        }

        // 赋值重载
        // v1 = v3
        // 传统写法
//        vector<T>& operator=(const vector<T>& v)
//        {
//            // 先判断自己给自己赋值
//            if (this != &v)
//            {
//                delete[] _start; // 释放旧空间
//                _start = new T[v.capacity()];
//                memcpy(_start, v._start, sizeof(T) * v.size());
//                _finish = _start + v.size();
//                _endofstorage = _start + v.capacity();
//            }
//
//            return *this;
//        }


        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator begin() const
        {
            return _start;
        }

        const_iterator end() const
        {
            return _finish;
        }


        bool empty()
        {
            return _finish == _start;
        }

        T& operator[] (size_t i)
        {
            assert(i < size());

            return _start[i];
        }

        void resize(size_t n, T val = T())
        {
            if (n < size())
            {
                _finish = _start + n;
            }
            else
            {
                if (n > capacity())
                {
                    reserve(n);
                }

                while (_finish < _start + n)
                {
                    *_finish = val;
                    ++_finish;
                }
            }
        }

        void reserve(size_t n)
        {
            if (n > capacity())
            {
                // 这里要提前保存一份才行
                size_t sz = size();
                T* tmp = new T[n];
                if (_start)
                {
                    // 拷贝旧数据到新空间
                    // memcpy对于深拷贝的自定义类型会出bug
                    // memcpy(tmp, _start, sz * sizeof(T));
                    // 改进如下：
                    for (size_t i = 0; i < sz; i++)
                    {
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
                }

                // 再让旧空间指向新空间
                _start = tmp;
                _finish = _start + sz;
                _endofstorage = _start + n;
            }
        }

        // 尾插
        void push_back(const T& x)
        {
            // 满了就要增容
            if (_finish == _endofstorage)
            {
                size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
                reserve(newcapacity);
            }
            *_finish = x;
            ++_finish;
        }

        // 尾删
        void pop_back()
        {
            assert(!empty());
            --_finish;
        }

        void insert(iterator& pos, const T& x)
        {
            if(_finish == _endofstorage)
            {
                size_t len = pos - _start;

                size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
                reserve(newcapacity);

                // 更新pos，解决增容后pos失效的问题
                pos = _start + len;
            }
            auto end = _finish - 1;
            while (end >= pos)
            {
                *(end + 1) = *(end);
                --end;
            }
            *pos = x;
            ++_finish;

            pos = pos + 1;
        }

        iterator erase(iterator pos)
        {
            auto it = pos + 1;
            while (it != _finish)
            {
                *(it - 1) = *it;
                ++it;
            }

            --_finish;

            return pos;
        }

    private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage;
    };

    // 打印，const修饰的那种
    // 只能读不能写
    template<class T>
    void PrintVector(const vector<T>& v)
    {
        auto it = v.begin();
        while (it != v.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }

    void test_vector1()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);

        auto it = v.begin();
        while (it != v.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        for (size_t i = 0; i < v.size(); ++i)
        {
            cout << v[i] << " ";
        }
        cout << endl;

        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;

    }

    void test_vector2()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);

        v.push_back(5);
        PrintVector(v);

        v.resize(3);
        PrintVector(v);

        v.resize(6, 1);
        PrintVector(v);

        v.resize(10, 2);
        PrintVector(v);
    }

    void test_vector3()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        PrintVector(v);

        vector<int>::iterator pos = find(v.begin(), v.end(), 3);
        // 在pos的前面插入
        v.insert(pos, 30);
        // insert以后pos就失效了
        // 1. pos指向位置的意义变了，pos不是指向3
        // 2. pos成了野指针
        PrintVector(v);

        // cout << *pos << endl;

        // 删除掉所有的偶数
        auto it = v.begin();
        while (it != v.end())
        {
            if (*it % 2 == 0)
            {
                v.erase(it);
            }
            ++it;
        }

    }

    void test_vector4()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        PrintVector(v);

        vector<int>::iterator pos = find(v.begin(), v.end(), 3);
        // 在pos的前面插入
        v.insert(pos, 30);
        // insert以后pos就失效了
        // 1. pos指向位置的意义变了，pos不是指向3
        // 2. pos成了野指针
        PrintVector(v);

        // cout << *pos << endl;

        // 删除掉所有的偶数
        auto it = v.begin();
        while (it != v.end())
        {
            if (*it % 2 == 0)
            {
                it = v.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    void test_vector5()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);

        vector<int> v2(v1);
        PrintVector(v1);
        PrintVector(v2);

        vector<int> v3;
        v3.push_back(10);
        v3.push_back(20);

        v1 = v3;

        PrintVector(v1);
        PrintVector(v3);

    }

    void test_vector6()
    {
        vector<string> v;
        v.push_back("11111");
        v.push_back("22222");
        v.push_back("33333");

        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}

#endif//VECTOR_VECTOR_H
