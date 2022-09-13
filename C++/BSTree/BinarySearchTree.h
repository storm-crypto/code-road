//
// Created by ��� on 2022-09-12.
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
	// ���캯��
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
public:
	// ���캯��
	BSTree()
		:_root(nullptr)
	{}

	// �漰��ǳ��������Ҫʵ�ֿ������� operator=��

	bool Insert(const K& key)
	{
		// �����Ϊ�գ���ôkey���ǵ�һ���ڵ�
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		// ��Ϊ�վͿ�ʼ��
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
				// ˵����ȣ���Ⱦ�˵��key�Ѿ������ˣ�return false
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

	// �������
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
