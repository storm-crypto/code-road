//
// Created by Ðñ¸ç on 2022-09-12.
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
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;

private:
	Node * _root;
};

#endif //BSTREE__BINARYSEARCHTREE_H
