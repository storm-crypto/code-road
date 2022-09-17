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
					else // cur->_bf == 1
					{
						// 左右双旋
						RotateLR(parent);
					}
				}
				else // parent->_bf == 2
				{
					if (cur->_bf == 1)
					{
						//左单旋
						RotateL(parent);
					}
					else
					{
						// 右左双旋
						RotateRL(parent);
					}
				}

				break;
			}
			else
			{
				// 说明插入节点之前，树已经不平衡了
				assert(false);
			}
		}

		return true;
	}
	// 左右双旋
	void RotateLR(Node* parent)
	{
		Node *subL = parent->_left;
		Node *subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(subL);
		RotateR(parent);

		// 平衡因子的调整
		// 在b插入
		if (bf == -1)
		{
			subL->_bf = 0;
			parent->_bf = 1;
			subLR->_bf = 0;
		}
		else if (bf == 1) // 在c插入
		{
			subL->_bf = -1;
			parent->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 0)
		{
			subL->_bf = 0;
			parent->_bf = 0;
			subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	// 右左双旋
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(subR);
		RotateL(parent);

		// 根据不同的情况，对平衡因子进行修改
		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0; // 这个无论哪种情况下都是0
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
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

		// 更新平衡因子：
		parent->_bf = subR->_bf = 0;
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

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	// 中序遍历：
	void InOrder()
	{
		_InOrder(_root);
	}
private:
	Node* _root;
};

#endif //AVLTREE__AVLTREE_H
