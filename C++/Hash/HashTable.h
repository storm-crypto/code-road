//
// Created by 旭哥 on 2022-09-21.
//

#ifndef HASH__HASHTABLE_H
#define HASH__HASHTABLE_H
#include <vector>
#include <iostream>
using namespace std;

// 闭散列
namespace CloseHash
{
	enum State
	{
		EMPTY,
		EXITS,
		DELETE,
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY; // 状态
	};

	template<class K>
	struct Hash
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	// 因为如果key是string类型的，就走这个特化的例子
	// 特化：
	template<>
	struct Hash<string>
	{
		size_t operator()(const string& key)
		{
			// 用BKDR哈希算法
			size_t value = 0;
			for (auto ch : key)
			{
				value += ch;
				value *= 131;
			}
			return value;
		}
	};


	template<class K, class V, class HashFunc = Hash<K>>
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			HashData<K, V>* ret = Find(kv.first);
			if (ret)
			{
				return false;
			}

			// 负载因子大于0.7就增容
			// 插入之前要计算他的负载因子
			if (_table.size() == 0)
			{
				_table.resize(10);
			}
		    else if ((double )_n / (double)_table.size() > 0.7)
			{
				// 增容
				HashTable<K, V, HashFunc> newHT;
				newHT._table.resize(_table.size() * 2);
				for (auto& e : _table)
				{
					if (e._state == EXITS)
					{
						newHT.Insert(e._kv);
					}
				}

				_table.swap(newHT._table);
			}
			HashFunc hf;
			size_t start = hf(kv.first) % _table.size();
		    size_t index = start;
			// 如果当前坑位存在就需要继续探测后面的位置 -- 线性探测 or 二次探测
			size_t i = 1;
			while (_table[index]._state == EXITS)
			{
				index = start + i;
				index %= _table.size(); // 过头了要回来
				i++;
			}

			_table[index]._kv = kv;
			_table[index]._state = EXITS;
			++_n;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			if (_table.size() == 0)
			{
				return nullptr;
			}
			HashFunc hf;
			size_t start = hf(key) % _table.size();
			size_t index = start;
			size_t i = 1;
			// 不等于空就继续找
			while(_table[index]._state != EMPTY)
			{
				if (_table[index]._state == EXITS
				&& _table[index]._kv.first == key)
				{
					return &_table[index];
				}

				index = start + i;
				index %= _table.size();
				i++;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret == nullptr)
			{
				return false;
			}
			else
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
		}

	private:
		/*HashData* _table;
		size_t _size;	  // 记录存了多少个数据了
		size_t _capacity; // 增容*/
		// 用vector来代替上面定义的三个变量
		vector<HashData<K, V>> _table;
		size_t _n = 0; // 存储的有效数据个数
	};

	struct IntHashFunc
	{
		int operator()(int i)
		{
			return i;
		}
	};

	void TestHashTable1()
	{
		int a[] = {1, 5, 10, 100000, 100, 18, 15, 7, 40};
		HashTable<int, int, IntHashFunc> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
	}

	struct stringHashFunc
	{
		// 这个仿函数的基本功能是将字符串转成对应的整型值，因为整型才能取模算映射位置
		// 期望，字符串不同，转出的整型值不同
		size_t operator()(const string& s)
		{
			// 用BKDR哈希算法
			size_t value = 0;
			for (auto ch : s)
			{
				value += ch;
				value *= 131;
			}
			return value;
		}
	};

	void TestHashTable2()
	{
		string a[] = {"苹果", "西瓜", "苹果"};
		HashTable<string, int, stringHashFunc> ht;
		for (auto str : a)
		{
			auto ret = ht.Find(str);
			if (ret)
			{
				ret->_kv.second++;
			}
			else
			{
				ht.Insert(make_pair(str, 1));
			}
		}
	}
}

//namespace OpenHash
//{
//	template<class K, class V>
//	struct HashNode
//	{
//		HashNode<K, V>* _next;
//		pair<K, V> _kv;
//
//		// 构造函数
//		HashNode(const pair<K, V>& kv)
//			:_next(nullptr)
//			, _kv(kv)
//		{}
//	};
//
//	template<class K>
//	struct Hash
//	{
//		size_t operator()(const K& key)
//		{
//			return key;
//		}
//	};
//
//	// 因为如果key是string类型的，就走这个特化的例子
//	// 特化：
//	template<>
//	struct Hash<string>
//	{
//		size_t operator()(const string& key)
//		{
//			// 用BKDR哈希算法
//			size_t value = 0;
//			for (auto ch : key)
//			{
//				value += ch;
//				value *= 131;
//			}
//			return value;
//		}
//	};
//
//	template<class K, class V, class HashFunc = Hash<K>>
//	class HashTable
//	{
//		typedef HashNode<K, V> Node;
//	public:
//
//		size_t GetNextPrime(size_t prime)
//		{
//			const int PRIMECOUNT = 28;
//			static const size_t primeList[PRIMECOUNT] =
//			{
//				53ul, 97ul, 193ul, 389ul, 769ul,
//				1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
//				49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
//				1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
//				50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
//				1610612741ul, 3221225473ul, 4294967291ul
//			};
//
//			size_t i = 0;
//			for(; i < PRIMECOUNT; ++i)
//			{
//				if(primeList[i] > prime)
//					return primeList[i];
//			}
//			return primeList[i];
//		}
//
//
//		bool Insert(const pair<K, V>& kv)
//		{
//			HashFunc hf;
//			if (Find(kv.first))
//				return false;
//
//			// 负载因子到1时，进行增容
//			if (_n == _table.size())
//			{
//
//				vector<Node*> newTable;
//				size_t newSize = _table.size() == 0 ? 8 : _table.size() * 2;
//				// newTable.resize(newSize, nullptr);
//				newTable.resize(GetNextPrime(_table.size()));
//
//
//				// 遍历旧表，取旧表的结点，重新算映射位置，挂到新表中
//				for (size_t i = 0; i < _table.size(); i++)
//				{
//					if (_table[i])
//					{
//						Node* cur = _table[i];
//						while (cur)
//						{
//							Node* next = cur->_next;
//							size_t index = hf(cur->_kv.first) % newTable.size();
//							// 将cur结点头插到newTable中
//							cur->_next = newTable[index];
//							newTable[index] = cur;
//
//							cur = next;
//						}
//
//						// 全部处理完之后，这个坑的链表可以置为空了
//						_table[i] = nullptr;
//					}
//				}
//				// newTable跟_table交换
//				_table.swap(newTable);
//			}
//
//
//			size_t index = hf(kv.first) % _table.size();
//			Node* newnode = new Node(kv);
//
//			// 头插
//			newnode->_next = _table[index];
//			_table[index] = newnode;
//			++_n;
//
//			return true;
//		}
//
//		Node* Find(const K& key)
//		{
//			if (_table.size() == 0)
//				return nullptr;
//
//			HashFunc hf;
//			size_t index = hf(key) % _table.size();
//			Node* cur = _table[index];
//			while (cur)
//			{
//				if (cur->_kv.first == key) return cur;
//				else cur = cur->_next;
//			}
//
//			return nullptr;
//		}
//
//		bool Erase(const K& key)
//		{
//			HashFunc hf;
//			size_t index = hf(key) % _table.size();
//			Node* cur = _table[index];
//			Node* prev = nullptr;
//			while (cur)
//			{
//				if (cur->_kv.first == key)
//				{
//					// cur是第一个结点的情况
//					if (cur == _table[index])
//					{
//						_table[index] = cur->_next;
//					}
//					else
//					{
//						prev->_next = cur->_next;
//					}
//
//					--_n;
//					delete cur;
//					return true;
//				}
//
//				prev = cur;
//				cur = cur->_next;
//			}
//
//			return false;
//		}
//
//	private:
//		vector<Node*> _table;
//		size_t _n = 0; // 有效数据的个数
//	};
//
//	void TestHashTable1()
//	{
//		int a[] = {1, 5, 10, 100000, 100, 18, 15, 7, 40};
//		HashTable<int, int> ht;
//		for (auto e : a)
//		{
//			ht.Insert(make_pair(e, e));
//		}
//	}
//
//	void TestHashTable2()
//	{
//		string a[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "橘子", "苹果" };
//		HashTable<string, int> ht;
//		for (auto str : a)
//		{
//			auto ret = ht.Find(str);
//			if (ret)
//			{
//				ret->_kv.second++;
//			}
//			else
//			{
//				ht.Insert(make_pair(str, 1));
//			}
//		}
//	}
//
//}

namespace OpenHash
{
	template<class T>
	struct HashNode
	{
		HashNode<T>* _next;
		T _data;

		// 构造函数
		HashNode(const T& data)
			:_next(nullptr)
			, _data(data)
		{}
	};

	template<class K>
	struct Hash
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	// 因为如果key是string类型的，就走这个特化的例子
	// 特化：
	template<>
	struct Hash<string>
	{
		size_t operator()(const string& key)
		{
			// 用BKDR哈希算法
			size_t value = 0;
			for (auto ch : key)
			{
				value += ch;
				value *= 131;
			}
			return value;
		}
	};

	// 前置声明
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;

	// 迭代器
	template<class K, class T, class KeyOfT, class HashFunc = Hash<K>>
	struct __HTIterator
	{
		typedef HashNode<T> Node;
		typedef __HTIterator<K, T, KeyOfT, HashFunc> Self;
		typedef HashTable<K, T, KeyOfT, HashFunc> HT;
		Node* _node;
		HT* _pht;

		// 构造函数
		__HTIterator(Node* node, HT* pht)
			:_node(node)
			, _pht(pht)
		{}


		// 重难点
		Self& operator++()
		{
			// 1、当前桶中还有数据，那么就在当前桶往后走
			// 2、当前桶走完了，需要往下一个桶去走
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				// 获取当前桶所在的位置
				KeyOfT kot;
				HashFunc hf;
				size_t index = hf(kot(_node->_data)) % _pht->_table.size();
				++index;
				// 如果下一个桶的位置不为空，那么就找到下一个桶了
				while (index < _pht->_table.size())
				{
					if (_pht->_table[index]) // 找到下一个桶的位置了
					{
						_node = _pht->_table[index];
						return *this;
					}
					else
					{
						++index;
					}

				}
				_node = nullptr;
			}
			return *this;
		}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		bool operator != (const Self& s) const
		{
			return _node != s._node;
		}

		bool operator == (const Self& s) const
		{
			return _node == s._node;
		}

	};

	template<class K, class T, class KeyOfT, class HashFunc = Hash<K>>
	class HashTable
	{
		typedef HashNode<T> Node;

		template<class K1, class T1, class KeyOfT1, class HashFunc1>
		friend struct __HTIterator;
	public:
		typedef __HTIterator<K, T, KeyOfT, HashFunc> iterator;
		//

		iterator begin()
		{
			size_t i = 0;
			while (i < _table.size())
			{
				if (_table[i])
				{
					// 找到第一个桶的位置了,返回迭代器
					return iterator(_table[i], this);
				}
				i++;
			}

			// 如果没找到，说明哈希桶是空的，返回end()
			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		size_t GetNextPrime(size_t prime)
		{
			const int PRIMECOUNT = 28;
			static const size_t primeList[PRIMECOUNT] =
				{
					53ul, 97ul, 193ul, 389ul, 769ul,
					1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
					49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
					1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
					50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
					1610612741ul, 3221225473ul, 4294967291ul
				};

			size_t i = 0;
			for(; i < PRIMECOUNT; ++i)
			{
				if(primeList[i] > prime)
					return primeList[i];
			}
			return primeList[i];
		}


		bool Insert(const T& data)
		{
			HashFunc hf;
			KeyOfT kot;
			if (Find(kot(data)))
				return false;

			// 负载因子到1时，进行增容
			if (_n == _table.size())
			{

				vector<Node*> newTable;
				//size_t newSize = _table.size() == 0 ? 8 : _table.size() * 2;
				// newTable.resize(newSize, nullptr);
				newTable.resize(GetNextPrime(_table.size()));


				// 遍历旧表，取旧表的结点，重新算映射位置，挂到新表中
				for (size_t i = 0; i < _table.size(); i++)
				{
					if (_table[i])
					{
						Node* cur = _table[i];
						while (cur)
						{
							Node* next = cur->_next;
							size_t index = hf(kot(data)) % newTable.size();
							// 将cur结点头插到newTable中
							cur->_next = newTable[index];
							newTable[index] = cur;

							cur = next;
						}

						// 全部处理完之后，这个坑的链表可以置为空了
						_table[i] = nullptr;
					}
				}
				// newTable跟_table交换
				_table.swap(newTable);
			}


			size_t index = hf(kot(data)) % _table.size();
			Node* newnode = new Node(data);

			// 头插
			newnode->_next = _table[index];
			_table[index] = newnode;
			++_n;

			return true;
		}

		Node* Find(const K& key)
		{
			if (_table.size() == 0)
				return nullptr;

			KeyOfT kot;
			HashFunc hf;
			size_t index = hf(key) % _table.size();
			Node* cur = _table[index];
			while (cur)
			{
				if (kot(cur->_data) == key) return cur;
				else cur = cur->_next;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashFunc hf;
			size_t index = hf(key) % _table.size();
			Node* cur = _table[index];
			Node* prev = nullptr;
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					// cur是第一个结点的情况
					if (cur == _table[index])
					{
						_table[index] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					--_n;
					delete cur;
					return true;
				}

				prev = cur;
				cur = cur->_next;
			}

			return false;
		}

	private:
		vector<Node*> _table;
		size_t _n = 0; // 有效数据的个数
	};


}



#endif //HASH__HASHTABLE_H
