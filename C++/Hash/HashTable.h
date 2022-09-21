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
	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
	};

	template<class K, class V>
	class HashTable
	{

	private:
		/*HashData* _table;
		size_t _size;	  // 记录存了多少个数据了
		size_t _capacity; // 增容*/
		// 用vector来代替上面定义的三个变量
		vector<HashData> _table;
		size_t _n; // 存储的有效数据个数
	};
}

#endif //HASH__HASHTABLE_H
