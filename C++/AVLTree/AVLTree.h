//
// Created by 旭哥 on 2022-09-16.
//

#ifndef AVLTREE__AVLTREE_H
#define AVLTREE__AVLTREE_H

#include <iostream>
using namespace std;

template<class K, class V>
class AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf; // 平衡因子

	pair<K, V> _kv;

	// 构造函数
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
	// 构造函数
	AVLTree()
		:_root(nullptr)
	{}

	// 拷贝构造和赋值需要实现深拷贝，后面再说
	~AVLTree()
	{
		//
	}

	// 实现插入
	bool Insert(const pair<K, V>& kv)
	{
		// 如果树本来就是空的话，就直接插入
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		// 找到存储的位置，将元素插进去
		Node* parent = _root, *cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else // 说明key已经存在了
			{
				return false;
			}
		}

		// 找到插入的位置了，这里也是要继续分情况讨论：
		// 看插入到parent的左边还是右边
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		return true;
	}

	// 实现Find
	Node* Find(const K& key)
	{
		return nullptr;
	}

	// 删除key所在的节点
	bool Erase(const K& key)
	{
		return false;
	}
private:
	Node* _root;
};

#endif //AVLTREE__AVLTREE_H
