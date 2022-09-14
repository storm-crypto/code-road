//
// Created by 旭哥 on 2022-09-12.
//

#ifndef BSTREE__BINARYSEARCHTREE_H
#define BSTREE__BINARYSEARCHTREE_H

#include <iostream>
using namespace std;


namespace K
{
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

		// 如果树中已经存在key，返回false
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

		// 如果树中不存在key，返回false
		// 存在，删除后，返回true
		bool _EraseR(Node*& root, const K& key)
		{
			if (root == NULL)
				return false;
			if (root->_key < key)
			{
				_EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				_EraseR(root->_left, key);
			}
			else
			{
				// 找到了，root就是要删除的节点
				// 分情况讨论：
				if (root->_left == nullptr)
				{
					Node* del = root;
					root = root->_right;
					delete del;
				}
				else if (root->_right == nullptr)
				{
					Node* del = root;
					root = root->_left;
					delete del;
				}
				else
				{
					// 左右都不为nullptr
					Node* minRightParent = root;
					// 找到右子树的最小节点(也就是右子树的最左边的节点)去替换
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRightParent = minRight;
						minRight = minRight->_left;
					}

					// 保存替换节点的值
					root->_key = minRight->_key;

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
			}
			return true;
		}

		void _Destroy(Node* root)
		{
			if (root == NULL)
				return;

			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
		}

		Node* _Copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			Node* copyNode = new Node(root->_key);
			copyNode->_left = _Copy(root->_left);
			copyNode->_right = _Copy(root->_right);

			return copyNode;
		}

	public:
		// 构造函数
		BSTree()
			:_root(nullptr)
		{}

		BSTree(const BSTree<K>& t)
		{
			_root = _Copy(t._root);
		}

		// t1 = t2
		BSTree<K>& operator=(BSTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}

		~BSTree()
		{
			_Destroy(_root);
			_root = nullptr;
		}



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

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

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

}

namespace KV
{
	template<class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V> *_left;
		BSTreeNode<K, V> *_right;

		K _key;
		V _value;
		// 构造函数
		BSTreeNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};

	template<class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
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

		// 如果树中已经存在key，返回false
		bool _InsertR(Node*& root, const K& key, const V& value)
		{
			if (root == NULL) // 插入
			{
				root = new Node(key, value);
				return true;
			}

			if (root->_key < key)
			{
				return _InsertR(root->_right, key, value);
			}
			else if (root->_key > key)
			{
				return _InsertR(root->_left, key, value);
			}
			else  // 说明已经有了
			{
				return false;
			}
		}

		// 如果树中不存在key，返回false
		// 存在，删除后，返回true
		bool _EraseR(Node*& root, const K& key)
		{
			if (root == NULL)
				return false;
			if (root->_key < key)
			{
				_EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				_EraseR(root->_left, key);
			}
			else
			{
				// 找到了，root就是要删除的节点
				// 分情况讨论：
				if (root->_left == nullptr)
				{
					Node* del = root;
					root = root->_right;
					delete del;
				}
				else if (root->_right == nullptr)
				{
					Node* del = root;
					root = root->_left;
					delete del;
				}
				else
				{
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					K kmin = minRight->_key;
					V vmin = minRight->_value;

					// 转换成在root的右子树删除min
					_EraseR(root->_right, kmin);
					root->_key = kmin;
					root->_value = vmin;
				}
			}
			return true;
		}

		void _Destroy(Node* root)
		{
			if (root == NULL)
				return;

			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
		}

		Node* _Copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			Node* copyNode = new Node(root->_key, root->_value);
			copyNode->_left = _Copy(root->_left);
			copyNode->_right = _Copy(root->_right);

			return copyNode;
		}

	public:
		// 构造函数
		BSTree()
			:_root(nullptr)
		{}

		BSTree(const BSTree<K, V>& t)
		{
			_root = _Copy(t._root);
		}

		// t1 = t2
		BSTree<K, V>& operator=(BSTree<K, V> t)
		{
			swap(_root, t._root);
			return *this;
		}

		~BSTree()
		{
			_Destroy(_root);
			_root = nullptr;
		}



		// 涉及深浅拷贝，需要实现拷贝构造 operator=等

		// 插入的递归版本呢
		bool InsertR(const K& key, const V& value)
		{
			return _InsertR(_root, key, value);
		}


		Node* FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}


		// 中序遍历
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_key << ":" << root->_value << endl;
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
}


#endif //BSTREE__BINARYSEARCHTREE_H
