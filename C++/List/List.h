//
// Created by ��� on 2022-09-07.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iostream>

using namespace std;

namespace ljx
{
    // ����ͷ�ڵ�
    // ��struct����Ϊstruct���εĽṹ�嶼Ĭ����public���͵�
    template<class T>
    struct _list_node
    {
        T _val;
        _list_node<T>* _next;
        _list_node<T>* _prev;

        // ���캯��
        _list_node(const T val = T())
            :_val(val)
            , _prev(nullptr)
            , _next(nullptr)
        {}
    };

    // ���������
    template<class T>
    struct _list_iterator
    {
        typedef _list_node<T> node;
        typedef _list_iterator<T> self;

        node* _pnode; // ��Ա����
        // ���캯��
        _list_iterator(node* pnode)
                :_pnode(pnode)
        {}

        // �������졢operator=���������ǲ�д��������Ĭ�����ɵľͿ�����

        // ����operator*
        T& operator*()
        {
            return _pnode->_val;
        }

        bool operator!=(const self& s) const
        {
            return _pnode != s._pnode;
        }

        bool operator==(const self& s) const
        {
            return _pnode == s._pnode;
        }

        self& operator++()
        {
            _pnode = _pnode->_next;
            return *this;
        }

        // ����++
        self operator++(int)
        {
            self tmp(*this);
            _pnode = _pnode->_next;
            return tmp;
        }

        self& operator--()
        {
            _pnode = _pnode->_prev;
            return *this;
        }

        self operator--(int)
        {
            self tmp(*this);
            _pnode = _pnode->_prev;
            return tmp;
        }

    };

    template<class T>
    class list
    {
        typedef _list_node<T> node;
    public:
        typedef _list_iterator<T> iterator;
        typedef _list_iterator<T> const_iterator;

        iterator begin()
        {
            // ����һ���������󷵻�
            // ����ķ���ֵ��һ��iterator����
            return iterator(_head->_next);
        }

        iterator end()
        {
            return iterator(_head);
        }

        // ���캯��
        list()
        {
            // ����һ���������󴫹�ȥ
            _head = new node;
            _head->_next = _head;
            _head->_prev = _head;
        }

        // β��
        void push_back(const T& x)
        {
            node* newnode = new node(x);
            node* tail = _head->_prev;
            // head tail newnode
            tail->_next = newnode;
            newnode->_prev = tail;
            newnode->_next = _head;
            _head->_prev = newnode;
        }


    private:
        node* _head;
    };

    // ����
    void test_list1()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);

        // ����������
        list<int>::iterator it = lt.begin();
        while (it != lt.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        // ��Χfor
        for (auto e : lt)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}

#endif//LIST_LIST_H
