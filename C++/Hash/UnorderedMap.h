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
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename OpenHash::HashTable<K, pair<K, V>, MapKeyOfT >::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}
		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		OpenHash::HashTable<K, pair<K, V>, MapKeyOfT> _ht;
	};

	void test_unordered_map1()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "ÅÅÐò"));
		dict["left"] = "×ó±ß";
		dict["left"] = "Ê£Óà";

		unordered_map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}
}


#endif //HASH__UNORDEREDMAP_H
