//
// Created by Ðñ¸ç on 2022-09-22.
//

#ifndef HASH__UNORDEREDSET_H
#define HASH__UNORDEREDSET_H
#include "HashTable.h"

namespace ljx
{
	template<class K>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};

	public:
		typedef typename OpenHash::HashTable<K, K, SetKeyOfT >::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const K k)
		{
			return _ht.Insert(k);
		}

	private:
		OpenHash::HashTable<K, K, SetKeyOfT> _ht;
	};

	void test_unordered_set1()
	{
		unordered_set<int> us;
		us.insert(200);
		us.insert(1);
		us.insert(2);
		us.insert(33);
		us.insert(50);
		us.insert(60);
		us.insert(243);
		us.insert(6);

		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			cout << *it << " ";
			++it;
		}
	}
}

#endif //HASH__UNORDEREDSET_H
