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

	template<class K, class V>
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
				HashTable<K, V> newHT;
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

			size_t start = kv.first % _table.size();
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

			size_t start = key % _table.size();
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

	void TestHashTable()
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
