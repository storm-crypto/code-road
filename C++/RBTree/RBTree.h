//
// Created by ��� on 2022-09-17.
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

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Colour _col; // ��ɫ

	RBTreeNode(const T& x)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(x)
		,_col(Red)
	{}
};

template<class K, class T, class KeyOfT>
class RBTree
{
	// T�����˺�����Ľ���ʲô
	typedef RBTreeNode<T> Node;
public:
	RBTree()
		:_root(nullptr)
	{}

	// ���������operator��ֵ

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
		KeyOfT kot; // �º���
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
			else // �ҵ���
			{
				return cur;
			}
		}

		return nullptr; // û�ҵ�
	}

	pair<Node*, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = Black;
			return make_pair(_root, true);
		}

		KeyOfT kot;

		// ���������
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
				return make_pair(cur, false);
			}
		}
		// ����ߵ����˵���ҵ���Ҫ���в����λ����
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

		// ������Ŀ����߼�
		// ��Ҫ����ʱ�����������״��ڣ�����ɫΪ��ɫ��Ҫ��������
		while (parent && parent->_col == Red)
		{
			Node* grandfather = parent->_parent;
			// �ؼ�������
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				// ���1��uncle������Ϊ��
				if (uncle && uncle->_col == Red)
				{
					// ��parent��uncle��ڣ��游���
					parent->_col = uncle->_col = Black;
					grandfather->_col = Red;

					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else // ���2 + 3:uncle�����ڣ�����uncle������Ϊ��
				{
					// cur�Ǹ��׵���ߣ����2������
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						grandfather->_col = Red;
						parent->_col = Black;
					}
					else // cur�Ǹ��׵��ұߣ����3��˫��
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = Black;
						grandfather->_col = Red;
					}
					break;
				}
			}
			else // parent == grandfather->_right ��������Ƿ������
			{
				// ...
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == Red) // ���һ
				{
					uncle->_col = parent->_col = Black;
					grandfather->_col = Red;

					// �������ϵ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else  // ���2 + 3:uncle�����ڣ�����uncle������Ϊ��
				{
					// ���2������������ֱ��
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = Black;
						grandfather->_col = Red;
					}
					else // cur == parent->_left
					{
						// ���3��
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = Black;
						grandfather->_col = Red;

					}

					break;
				}
			}
		}

		// ���������һ�������Ѹ�����ɫ��ɺ�
		_root->_col = Black;

		return make_pair(newnode, true);
	}

	// ����
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
	// �ҵ���
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		// ע��Ϊ�յ����
		if (subLR)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;
		// ��¼һ��parent��parent��λ��
		Node* parentParent = parent->_parent;
		parent->_parent = subL;

		// ����Ƕ�������������ת��
		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else // ��ת�Ĳ��������������
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
				cout << "��ɫ�ڵ�����������" << endl;
				return false;
			}
			return true;
		}

		// ��鸸�ף�����麢�ӣ���麢�ӱȽ��鷳
		if (root->_col == Red && root->_parent->_col == Red)
		{
			cout << "���������ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		if (root->_col == Black)
		{
			count++;
		}

		return _CheckBalance(root->_left, blackNum, count)
			&& _CheckBalance(root->_right, blackNum, count);
	}

	// ������ļ���
	bool CheckBalance()
	{
		if (_root == nullptr)
		{
			return true;
		}

		// 1. ���ڵ�����Ǻ�ɫ��
		if (_root->_col == Red)
		{
			cout << "���ڵ��Ǻ�ɫ��" << endl;
			return false;
		}

		// ������·������ɫ�ڵ������Ĳο�ֵ
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
