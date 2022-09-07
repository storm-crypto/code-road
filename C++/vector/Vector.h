//
// Created by ��� on 2022-09-06.
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

        // swap����
        // v1.swap(v2)
        void swap(vector<T> v)
        {
            ::swap(_start, v._start);
            ::swap(_finish, v._finish);
            ::swap(_endofstorage, v._endofstorage);
        }

        // �ִ�д����
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

        // ��������
        vector(const vector<T>& v)
            :_start(nullptr)
            , _finish(nullptr)
            , _endofstorage(nullptr)
        {
            _start = new T[v.capacity()];
            //memcpy(_start, v._start, sizeof(T) * v.size());
            // memcpy����������Զ������ͻ��bug
            // memcpy(tmp, _start, sz * sizeof(T));
            // �Ľ����£�
            for (size_t i = 0; i < v.size(); i++)
            {
                _start[i] = v._start[i];
            }
            _endofstorage = _start + v.capacity();
            _finish = _start + v.size();
        }

        // ��ֵ����
        // v1 = v3
        // ��ͳд��
//        vector<T>& operator=(const vector<T>& v)
//        {
//            // ���ж��Լ����Լ���ֵ
//            if (this != &v)
//            {
//                delete[] _start; // �ͷžɿռ�
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
                // ����Ҫ��ǰ����һ�ݲ���
                size_t sz = size();
                T* tmp = new T[n];
                if (_start)
                {
                    // ���������ݵ��¿ռ�
                    // memcpy����������Զ������ͻ��bug
                    // memcpy(tmp, _start, sz * sizeof(T));
                    // �Ľ����£�
                    for (size_t i = 0; i < sz; i++)
                    {
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
                }

                // ���þɿռ�ָ���¿ռ�
                _start = tmp;
                _finish = _start + sz;
                _endofstorage = _start + n;
            }
        }

        // β��
        void push_back(const T& x)
        {
            // ���˾�Ҫ����
            if (_finish == _endofstorage)
            {
                size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
                reserve(newcapacity);
            }
            *_finish = x;
            ++_finish;
        }

        // βɾ
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

                // ����pos��������ݺ�posʧЧ������
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

    // ��ӡ��const���ε�����
    // ֻ�ܶ�����д
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
        // ��pos��ǰ�����
        v.insert(pos, 30);
        // insert�Ժ�pos��ʧЧ��
        // 1. posָ��λ�õ�������ˣ�pos����ָ��3
        // 2. pos����Ұָ��
        PrintVector(v);

        // cout << *pos << endl;

        // ɾ�������е�ż��
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
        // ��pos��ǰ�����
        v.insert(pos, 30);
        // insert�Ժ�pos��ʧЧ��
        // 1. posָ��λ�õ�������ˣ�pos����ָ��3
        // 2. pos����Ұָ��
        PrintVector(v);

        // cout << *pos << endl;

        // ɾ�������е�ż��
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