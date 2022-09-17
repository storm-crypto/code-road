//
// Created by ��� on 2022-09-16.
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

	int _bf; // ƽ������ balanced factor

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
public:
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

		// ����ƽ��
		// 1. ����ƽ������
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
				// �������ϸ���
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ��ת����
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						// �ҵ���
						RotateR(parent);
					}
					else // cur->_bf == 1
					{
						// ����˫��
						RotateLR(parent);
					}
				}
				else // parent->_bf == 2
				{
					if (cur->_bf == 1)
					{
						//����
						RotateL(parent);
					}
					else
					{
						// ����˫��
						RotateRL(parent);
					}
				}

				break;
			}
			else
			{
				// ˵������ڵ�֮ǰ�����Ѿ���ƽ����
				assert(false);
			}
		}

		return true;
	}
	// ����˫��
	void RotateLR(Node* parent)
	{
		Node *subL = parent->_left;
		Node *subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(subL);
		RotateR(parent);

		// ƽ�����ӵĵ���
		// ��b����
		if (bf == -1)
		{
			subL->_bf = 0;
			parent->_bf = 1;
			subLR->_bf = 0;
		}
		else if (bf == 1) // ��c����
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
	// ����˫��
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(subR);
		RotateL(parent);

		// ���ݲ�ͬ���������ƽ�����ӽ����޸�
		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0; // ���������������¶���0
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

		// ����ƽ�����ӣ�
		parent->_bf = subR->_bf = 0;
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

		subL->_bf = parent->_bf = 0;
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

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	// ���������
	void InOrder()
	{
		_InOrder(_root);
	}
private:
	Node* _root;
};

#endif //AVLTREE__AVLTREE_H
