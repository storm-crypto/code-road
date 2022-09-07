//
// Created by ��� on 2022-09-07.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

namespace ljx
{
    // ����ͷ�ڵ�
    template<class T>
    // struct��class������
    struct _list_node
    {
        _val;
        _list_node<T>* _next;
        _list_node<T>* _prev;
    };

    template<class T>
    class list
    {
        typedef _list_node<T> node;
    public:
        list()
        {
            _head = new node;
            _head->_next = _head;
            _head->_prev = _head;
        }
    private:
        node* _head;

    };
}

#endif//LIST_LIST_H
