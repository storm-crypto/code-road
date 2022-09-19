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
	public:
		bool insert(const pair<const K, V>& kv)
		{
			_t.Insert(kv);

			return true;
		}

	private:
		RBTree<K, pair<const K, V>> _t;
	};
}


#endif //RBTREE__MAP_H
