//
// Created by 旭哥 on 2022-09-12.
//

#ifndef BSTREE__BINARYSEARCHTREE_H
#define BSTREE__BINARYSEARCHTREE_H

#include <iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode<K> *_left;
	BSTreeNode<K> *_right;

	K _key;
	// 构造函数
	BSTreeNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
private:
	Node* _FindR(Node* root, const K& key)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		if (root->_key < key)
		{
			return _FindR(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _FindR(root->_left, key);
		}
		else
		{
			return root;
		}
	}

	bool _InsertR(Node*& root, const K& key)
	{
		if (root == NULL) // 插入
		{
			root = new Node(key);
			return true;
		}

		if (root->_key < key)
		{
			return _InsertR(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _InsertR(root->_left, key);
		}
		else  // 说明已经有了
		{
			return false;
		}
	}


public:
	// 构造函数
	BSTree()
		:_root(nullptr)
	{}

	// 涉及深浅拷贝，需要实现拷贝构造 operator=等

	// 插入的递归版本呢
	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}


	Node* findR(const K& key)
	{
		return _FindR(_root, key);
	}

	bool EraseR(const K& key);

	bool Insert(const K& key)
	{
		// 如果树为空，那么key就是第一个节点
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		// 不为空就开始找
		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				// 说明相等，相等就说明key已经存在了，return false
				return false;
			}
		}

		cur = new Node(key);
		if (parent->_key > key)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		return true;
	}

	// 查找
	Node* find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return NULL;
	}

	// 删除
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				// 找到了，准备开始删除
				// 1. 	如果左孩子或者右孩子为空，把另一个还是交给父亲管理，删除自己
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}

					delete cur;
				}

				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}


					delete cur;
				}

				else // 左右子树都不为空
				{
					// 因为后面替换的时候是按照特征2的那种方式进行删除的，所以要保存parent
					Node* minRightParent = cur;
					// 找到右子树的最小节点(也就是右子树的最左边的节点)去替换
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						minRightParent = minRight;
						minRight = minRight->_left;
					}

					// 保存替换节点的值
					cur->_key = minRight->_key;

					// 删除替换节点
					if (minRightParent->_left == minRight)
					{
						minRightParent->_left = minRight->_right;
					}
					else
					{
						minRightParent->_right = minRight->_right;
					}

					delete minRight;


				}

				return true;
			}
		}

		return false;
	}

	// 中序遍历
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	Node * _root;
};

#endif //BSTREE__BINARYSEARCHTREE_H
