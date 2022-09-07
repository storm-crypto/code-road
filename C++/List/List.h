//
// Created by 旭哥 on 2022-09-07.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

namespace ljx
{
    // 定义头节点
    template<class T>
    // struct和class的区别
    struct _list_node
    {
        T _val;
        _list_node<T>* _next;
        _list_node<T>* _prev;
    };

    template<class T>
    class list
    {
        typedef _list_node<T> node;
    public:
        // 构造函数
        list()
        {
            _head = new node;
            _head->_next = _head;
            _head->_prev = _head;
        }

        // 尾插
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
