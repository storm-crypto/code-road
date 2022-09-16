//
// Created by Ðñ¸ç on 2022-09-16.
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

	int _bf; // Æ½ºâÒò×Ó

	pair<K, V> _kv;
};

template<class K, class V>
class AVLTree
{

};

#endif //AVLTREE__AVLTREE_H
