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
