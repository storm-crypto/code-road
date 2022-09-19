//
// Created by Ðñ¸ç on 2022-09-18.
//

#ifndef RBTREE__MAP_H
#define RBTREE__MAP_H
#include "RBTree.h"

namespace ljx
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		bool insert(const pair<const K, V>& kv)
		{
			_t.Insert(kv);

			return true;
		}

	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}


#endif //RBTREE__MAP_H
