//
// Created by 旭哥 on 2022-09-07.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iostream>
#include <cassert>

using namespace std;

namespace ljx
{
    // 定义头节点
    // 用struct，因为struct修饰的结构体都默认是public类型的
    template<class T>
    struct _list_node
    {
        T _val;
        _list_node<T>* _next;
        _list_node<T>* _prev;

        // 构造函数
        _list_node(const T val = T())
            :_val(val)
            , _prev(nullptr)
            , _next(nullptr)
        {}
    };

    // 定义迭代器
    // typedef _list_iterartor<T, T&, T*> iterator;
    // typedef _list_iterartor<T, const T&, const T*> const_iterator;
    template<class T, class Ref, class Ptr>
    struct _list_iterator
    {
        typedef _list_node<T> node;
        typedef _list_iterator<T, Ref, Ptr> self;

        node* _pnode; // 成员变量
        // 构造函数
        _list_iterator(node* pnode)
            :_pnode(pnode)
        {}

        // 拷贝构造、operator=、析构我们不写，编译器默认生成的就可以用

        // 重载operator*

        // T&operator*() iterator 可读可写
        // const T& operator*() const_iterator 只可以读
        // 为什么这里的返回值是Ref的原因
        // 用了class Ref，方面后面实例化出不同的类，有只读的那种const_itrator
        // 也有可读可写那种iterator
       Ref operator*()
        {
            return _pnode->_val;
        }

        Ptr operator->()
		{
          return &_pnode->_val;
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

        // 后置++
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
        typedef _list_iterator<T, T&, T*> iterator;
        typedef _list_iterator<T, const T&, const T*> const_iterator;

        iterator begin()
        {
            // 构造一个匿名对象返回
            // 这里的返回值是一个iterator对象
            return iterator(_head->_next);
        }

        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }

        iterator end()
        {
            return iterator(_head);
        }

        const_iterator end() const
        {
            return const_iterator(_head);
        }

        // 构造函数
        list()
        {
            // 构造一个匿名对象传过去
            _head = new node;
            _head->_next = _head;
            _head->_prev = _head;
        }

        // 尾插
        void push_back(const T &x)
        {
//            node *newnode = new node(x);
//            node *tail = _head->_prev;
//            // head tail newnode
//            tail->_next = newnode;
//            newnode->_prev = tail;
//            newnode->_next = _head;
//            _head->_prev = newnode;
			insert(end(), x);
        }

        // 头插
        void push_front(const T& x)
		{
        	insert(begin(), x);
		}

		void pop_back()
		{
        	erase(--end());
		}

		void pop_front()
		{
        	erase(begin());
		}

        void insert(iterator pos, const T& x)
		{
        	assert(pos._pnode);

			node* cur = pos._pnode;
			node* prev = cur->_prev;
			node* newnode = new node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		iterator erase(iterator pos)
		{
        	assert(pos._pnode);
        	assert(pos != end());
			node* prev = pos->_pnode->_prev;
			node* next = pos->_pnode->_next;

			delete pos._pnode;
			prev->_next = next;
			next->_prev = prev;

			return iterator(next);
		}

		bool empty()
		{
        	return begin() == end();
		}

		size_t size()
		{
        	size_t sz = 0;
        	iterator it = begin();
        	while (it != end())
			{
        		++sz;
        		++it;
			}
			return sz;
		}

    private:
        node* _head;
    };

    void PrintList(const list<int> &lt)
    {
        list<int>::const_iterator it = lt.begin();
        while (it != lt.end())
        {
            //*it += 1; // 因为只读，所以改变it的值会出错
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }

    class Date
	{
	public:
		int _year = 0;
		int _month = 1;
		int _day = 1;
	};

    // 测试
    void test_list1()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);

        // 迭代器遍历
        list<int>::iterator it = lt.begin();
        while (it != lt.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        // 范围for
        for (auto e : lt)
        {
            cout << e << " ";
        }
        cout << endl;

        PrintList(lt);
    }

    void test_list2()
	{
    	list<Date> lt;
    	lt.push_back(Date());
		lt.push_back(Date());
		lt.push_back(Date());

		list<Date>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << it->_year << " " << it->_month << " " << it->_day << endl;
			++it;
		}
		cout << endl;

	}
}

#endif//LIST_LIST_H
