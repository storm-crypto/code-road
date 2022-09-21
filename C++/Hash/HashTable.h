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

namespace OpenHash
{
	template<class K, class V>
	struct HashNode
	{
		HashNode<K, V>* _next;
		pair<K, V> _kv;

		// 构造函数
		HashNode(const pair<K, V>& kv)
			:_next(nullptr)
			, _kv(kv)
		{}
	};

	template<class K, class V>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

			// 负载因子到1时，进行增容
			if (_n == _table.size())
			{
				vector<Node*> newTable;
				size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
				newTable.resize(newSize);

				// 遍历旧表，取旧表的结点，重新算映射位置，挂到新表中
				for (size_t i = 0; i < _table.size(); i++)
				{
					if (_table[i])
					{
						Node* cur = _table[i];
						while (cur)
						{
							Node* next = cur->_next;
							size_t index = cur->_kv.first % newTable.size();
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

			size_t index = kv.first % _table.size();
			Node* newnode = new Node(kv);

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

			size_t index = key % _table.size();
			Node* cur = _table[index];
			while (cur)
			{
				if (cur->_kv.first == key) return cur;
				else cur = cur->_next;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			size_t index = key % _table.size();
			Node* cur = _table[index];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_kv.first == key)
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

	void TestHashTable1()
	{
		int a[] = {1, 5, 10, 100000, 100, 18, 15, 7, 40};
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
	}

}

#endif //HASH__HASHTABLE_H
