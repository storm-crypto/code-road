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
		bool Insert(const K& k)
		{
			_ht.Insert(k);

			return true;
		}

	private:
		OpenHash::HashTable<K, K, SetKeyOfT> _hs;
	};
}

#endif //HASH__UNORDEREDSET_H
