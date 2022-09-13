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
		if (root == NULL) // ����
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
		else  // ˵���Ѿ�����
		{
			return false;
		}
	}


public:
	// ���캯��
	BSTree()
		:_root(nullptr)
	{}

	// �漰��ǳ��������Ҫʵ�ֿ������� operator=��

	// ����ĵݹ�汾��
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

	// ����
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

	// ɾ��
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
				// �ҵ��ˣ�׼����ʼɾ��
				// 1. 	������ӻ����Һ���Ϊ�գ�����һ�����ǽ������׹���ɾ���Լ�
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

				else // ������������Ϊ��
				{
					// ��Ϊ�����滻��ʱ���ǰ�������2�����ַ�ʽ����ɾ���ģ�����Ҫ����parent
					Node* minRightParent = cur;
					// �ҵ�����������С�ڵ�(Ҳ����������������ߵĽڵ�)ȥ�滻
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						minRightParent = minRight;
						minRight = minRight->_left;
					}

					// �����滻�ڵ��ֵ
					cur->_key = minRight->_key;

					// ɾ���滻�ڵ�
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
