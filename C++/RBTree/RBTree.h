//
// Created by 旭哥 on 2022-09-17.
//

#ifndef RBTREE__RBTREE_H
#define RBTREE__RBTREE_H
#include <iostream>
using namespace std;

enum Colour
{
	Red,
	Black,
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Colour _col; // 颜色

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_col(Red)
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(nullptr)
	{}

	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = Black;
			return make_pair(_root, true);
		}

		// 插入操作：
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(cur, false);
			}
		}
		// 如果走到这里，说明找到了要进行插入的位置了
		Node* newnode = new Node(kv);
		newnode->_col = Red;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = newnode;
			newnode->_parent = parent;
		}
		else
		{
			parent->_left = newnode;
			newnode->_parent = parent;
		}
		cur = newnode;

		// 红黑树的控制逻辑

		return make_pair(newnode, true);
	}
private:
	Node* _root;
};
#endif //RBTREE__RBTREE_H
