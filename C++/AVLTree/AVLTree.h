//
// Created by 旭哥 on 2022-09-16.
//

#ifndef AVLTREE__AVLTREE_H
#define AVLTREE__AVLTREE_H

#include <iostream>
#include <cassert>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf; // 平衡因子 balanced factor

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
public:
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

		// 控制平衡
		// 1. 控制平衡因子
		while(parent)
		{
			if (parent->_left == cur)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// 继续往上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 旋转处理：
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						// 右单旋
						RotateR(parent);
					}
				}
			}
			else
			{
				// 说明插入节点之前，树已经不平衡了
				assert(false);
			}
		}

		return true;
	}

	void RotateL(Node* parent);
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

		subL->_bf = parent->_bf = 0;
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
