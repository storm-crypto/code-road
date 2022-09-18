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
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
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

		return make_pair(newnode, true);
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
