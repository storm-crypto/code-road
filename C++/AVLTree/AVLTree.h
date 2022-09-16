//
// Created by 旭哥 on 2022-09-16.
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

	int _bf; // 平衡因子

	pair<K, V> _kv;
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
	// 构造函数
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
