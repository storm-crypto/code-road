//
// Created by ��� on 2022-09-07.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

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

        // ����operator*
        T operator*()
        {
            return _pnode->_val;
        }

        bool operator!=(const self& s)
        {
            return _pnode != s._pnode;
        }

        operator++()
        {
            _pnode = _pnode->_next;
        }

    };

    template<class T>
    class list
    {
        typedef _list_node<T> node;
    public:
        typedef _list_iterator<T> iterator;

        // ���캯��
        list()
        {
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
}

#endif//LIST_LIST_H
