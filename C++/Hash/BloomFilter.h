//
// Created by 旭哥 on 2022-09-24.
//

#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H
#include "BitSet.h"

struct HashBKDR
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

struct HashAP
{
	size_t operator()(const string& s)
	{
		// 用AP哈希算法
		register size_t hash = 0;
		size_t ch;
		for (long i = 0; i < s.size(); i++)
		{
			ch = s[i];
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct HashDJB
{
	size_t operator()(const string& s)
	{
		register size_t hash = 5381;
		for (auto ch : s)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};



template<size_t N, class K = string,
    class Hash1 = HashBKDR, class Hash2 = HashAP, class Hash3 = HashDJB>
class BloomFilter
{
public:
	void Set(const K& key)
	{
		size_t i1 = Hash1()(key) % N;
		size_t i2 = Hash2()(key) % N;
		size_t i3 = Hash3()(key) % N;

		cout << i1 << " " << i2 << " " << i3 << endl;

		_bitset.Set(i1);
		_bitset.Set(i2);
		_bitset.Set(i3);

	}

	// 判断这三个位置用没用过
	bool Test(const K& key)
	{
		size_t i1 = Hash1()(key) % N;
		if (_bitset.Test(i1) == false)
		{
			return false;
		}

		size_t i2 = Hash2()(key) % N;
		if (_bitset.Test(i2) == false)
		{
			return false;
		}

		size_t i3 = Hash3()(key) % N;
		if (_bitset.Test(i3) == false)
		{
			return false;
		}

		return true; // 这里三个位都在是不准确的，不在才是准确的
	}

private:
	ljx::BitSet<N> _bitset;
};

void TestBloomFilter()
{
	BloomFilter<100> bf;
	bf.Set("张三");
	bf.Set("里斯");

	cout << bf.Test("张三") << endl;
	cout << bf.Test("李四") << endl;

}

#endif //BLOOMFILTER_H
