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

		}

	private:
		/*HashData* _table;
		size_t _size;	  // 记录存了多少个数据了
		size_t _capacity; // 增容*/
		// 用vector来代替上面定义的三个变量
		vector<HashData> _table;
		size_t _n = 0; // 存储的有效数据个数
	};
}

#endif //HASH__HASHTABLE_H
