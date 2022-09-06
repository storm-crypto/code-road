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
        {

        }

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

        size_t capacity()
        {
            return _endofstorage - _start;
        }

        size_t size()
        {
            return _finish - _start;
        }

        T& operator[] (size_t i)
        {
            assert(i < size());

            return _start[i];
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
                    memcpy(tmp, _start, sz);
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

        }

    private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage;
    };

    // 打印，const修饰的那种
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
}

#endif//VECTOR_VECTOR_H
