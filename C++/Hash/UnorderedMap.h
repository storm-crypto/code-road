//
// Created by Ðñ¸ç on 2022-09-22.
//

#ifndef HASH__UNORDEREDMAP_H
#define HASH__UNORDEREDMAP_H
#include "HashTable.h"

namespace ljx
{
	template<class K, class V>
	class unordered_map
	{
	public:
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
		bool Insert(const pair<K, V>& kv)
		{
			_ht.Insert(kv);

			return true;
		}

	private:
		OpenHash::HashTable<K, pair<K, V>, MapKeyOfT> _ht;
	};
}


#endif //HASH__UNORDEREDMAP_H
