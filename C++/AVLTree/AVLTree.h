//
// Created by ��� on 2022-09-16.
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

	int _bf; // ƽ������

	pair<K, V> _kv;

	// ���캯��
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
	// ���캯��
	AVLTree()
		:_root(nullptr)
	{}

	// ��������͸�ֵ��Ҫʵ�������������˵
	~AVLTree()
	{
		//
	}

	// ʵ�ֲ���
	bool Insert(const pair<K, V>& kv)
	{
		// ������������ǿյĻ�����ֱ�Ӳ���
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		// �ҵ��洢��λ�ã���Ԫ�ز��ȥ
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
			else // ˵��key�Ѿ�������
			{
				return false;
			}
		}

		// �ҵ������λ���ˣ�����Ҳ��Ҫ������������ۣ�
		// �����뵽parent����߻����ұ�
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

	// ʵ��Find
	Node* Find(const K& key)
	{
		return nullptr;
	}

	// ɾ��key���ڵĽڵ�
	bool Erase(const K& key)
	{
		return false;
	}
private:
	Node* _root;
};

#endif //AVLTREE__AVLTREE_H
