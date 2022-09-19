//
// Created by 旭哥 on 2022-09-17.
//

#ifndef RBTREE__RBTREE_H
#define RBTREE__RBTREE_H

#include <iostream>
using namespace std;

#include "Iterator.h"

enum Colour
{
	Red,
	Black,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Colour _col; // 颜色

	RBTreeNode(const T& x)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(x)
		,_col(Red)
	{}
};

template<class T, class Ref, class Ptr>
struct _TreeIterator
{
	typedef Ref reference;
	typedef Ptr pointer;

	typedef RBTreeNode<T> Node;
	typedef _TreeIterator<T, Ref, Ptr> Self;

	Node* _node;

	_TreeIterator(Node* node)
		:_node(node)
	{}


	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator != (const Self& s) const
	{
		return _node != s._node;
	}

	bool operator == (const Self& s) const
	{
		return _node == s._node;
	}

	// 难点
	Self operator++()
	{
		if (_node->_right)
		{
			// 下一个访问的就是右树中，中序遍历的第一个结点
			Node* left = _node->_right;
			while (left->_left)
			{
				left = left->_left;
			}

			_node = left; // 找到最左结点，并把最左结点放到node里面
		}
		else // 说明右为空
		{
			// 找祖先里面孩子不是父亲的右的那个
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	// 难点
	Self& operator--()
	{
		if (_node->_left) // 左子树不为空
		{
			// 找左子树的最右结点
			Node* right = _node->_left;
			while (right->_right)
			{
				right = right->_right;
			}

			_node = right;
		}
		else // 说明左子树为空
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}
};


template<class K, class T, class KeyOfT>
class RBTree
{
	// T决定了红黑树的结点存什么
	typedef RBTreeNode<T> Node;
public:
	typedef _TreeIterator<T, T&, T*> iterator;
	typedef _TreeIterator<T, const T&, const T*> const_iterator;
	typedef ReverseIterator<iterator> reverse_iterator; // 反向迭代器

	reverse_iterator rbegin()
	{
		// 最右结点就是反向迭代器的begin
		Node* right = _root;
		while (right && right->_right)
		{
			right = right->_right;
		}
		// 用正向迭代器来构造反向迭代器
		return reverse_iterator(iterator(right));
	}

	reverse_iterator rend()
	{
		// end指向的是空
		return reverse_iterator(iterator(nullptr));
	}

	// 最左结点
	iterator begin()
	{
		Node* left = _root;
		while (left && left->_left)
		{
			left = left->_left;
		}
		return iterator(left);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	RBTree()
		:_root(nullptr)
	{}

	// 拷贝构造和operator赋值

	void Destroy(Node* root)
	{
		if (root == nullptr)
			return;
		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
	}

	~RBTree()
	{
		Destroy(_root);
		_root = nullptr;
	}

	Node* Find(const K& key)
	{
		KeyOfT kot; // 仿函数
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else // 找到了
			{
				return cur;
			}
		}

		return nullptr; // 没找到
	}

	pair<iterator, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = Black;
			return make_pair(iterator(_root), true);
		}

		KeyOfT kot;

		// 插入操作：
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}
		// 如果走到这里，说明找到了要进行插入的位置了
		Node* newnode = new Node(data);
		newnode->_col = Red;
		if (kot(parent->_data) < kot(data))
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
		// 需要处理时候的情况：父亲存在，且颜色为红色需要持续处理
		while (parent && parent->_col == Red)
		{
			Node* grandfather = parent->_parent;
			// 关键看叔叔
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				// 情况1：uncle存在且为红
				if (uncle && uncle->_col == Red)
				{
					// 把parent和uncle变黑，祖父变红
					parent->_col = uncle->_col = Black;
					grandfather->_col = Red;

					// 继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else // 情况2 + 3:uncle不存在，或者uncle存在且为黑
				{
					// cur是父亲的左边：情况2：单旋
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						grandfather->_col = Red;
						parent->_col = Black;
					}
					else // cur是父亲的右边：情况3：双旋
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = Black;
						grandfather->_col = Red;
					}
					break;
				}
			}
			else // parent == grandfather->_right 跟上面的是反方向的
			{
				// ...
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == Red) // 情况一
				{
					uncle->_col = parent->_col = Black;
					grandfather->_col = Red;

					// 继续往上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				else  // 情况2 + 3:uncle不存在，或者uncle存在且为黑
				{
					// 情况2：祖孙三代是直线
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = Black;
						grandfather->_col = Red;
					}
					else // cur == parent->_left
					{
						// 情况3：
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = Black;
						grandfather->_col = Red;

					}

					break;
				}
			}
		}

		// 最后这里做一个处理：把根的颜色变成黑
		_root->_col = Black;

		return make_pair(iterator(newnode), true);
	}

	// 左单旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}

	}
	// 右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		// 注意为空的情况
		if (subLR)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;
		// 记录一下parent的parent的位置
		Node* parentParent = parent->_parent;
		parent->_parent = subL;

		// 如果是独立的树进行旋转：
		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else // 旋转的部分是子树的情况
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}

			subL->_parent = parentParent;
		}

	}

	bool _CheckBalance(Node* root, int blackNum, int count)
	{
		if (root == nullptr)
		{
			if (count != blackNum)
			{
				cout << "黑色节点的数量不相等" << endl;
				return false;
			}
			return true;
		}

		// 检查父亲，不检查孩子，检查孩子比较麻烦
		if (root->_col == Red && root->_parent->_col == Red)
		{
			cout << "存在连续的红色节点" << endl;
			return false;
		}

		if (root->_col == Black)
		{
			count++;
		}

		return _CheckBalance(root->_left, blackNum, count)
			&& _CheckBalance(root->_right, blackNum, count);
	}

	// 红黑树的检验
	bool CheckBalance()
	{
		if (_root == nullptr)
		{
			return true;
		}

		// 1. 根节点必须是黑色的
		if (_root->_col == Red)
		{
			cout << "根节点是红色的" << endl;
			return false;
		}

		// 找最左路径做黑色节点数量的参考值
		int blackNum = 0;
		Node* left = _root;
		while (left)
		{
			if (left->_col == Black)
			{
				blackNum++;
			}

			left = left->_left;
		}

		int num = 0;
		return _CheckBalance(_root, blackNum, num);
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	Node* _root;
};
#endif //RBTREE__RBTREE_H
