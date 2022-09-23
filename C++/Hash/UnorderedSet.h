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
	public:
		struct SetKeyOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
		typedef typename OpenHash::HashTable<K, K, SetKeyOfT>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}


		bool insert(const K& k)
		{
			_ht.Insert(k);

			return true;
		}

	private:
		OpenHash::HashTable<K, K, SetKeyOfT> _ht;
	};

	void test_unordered_set()
	{

	}
}

#endif //HASH__UNORDEREDSET_H
