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
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::reverse_iterator reverse_iterator;

		reverse_iterator rbegin()
		{
			return _t.rbegin();
		}

		reverse_iterator rend()
		{
			return _t.rend();
		}

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

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
