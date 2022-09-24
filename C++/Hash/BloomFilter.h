//
// Created by ��� on 2022-09-24.
//

#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H
#include "BitSet.h"

struct HashBKDR
{
	size_t operator()(const string& key)
	{
		// ��BKDR��ϣ�㷨
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
		// ��AP��ϣ�㷨
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

	// �ж�������λ����û�ù�
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

		return true; // ��������λ�����ǲ�׼ȷ�ģ����ڲ���׼ȷ��
	}

private:
	ljx::BitSet<N> _bitset;
};

void TestBloomFilter()
{
	BloomFilter<100> bf;
	bf.Set("����");
	bf.Set("��˹");

	cout << bf.Test("����") << endl;
	cout << bf.Test("����") << endl;

}

#endif //BLOOMFILTER_H
