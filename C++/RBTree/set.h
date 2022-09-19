//
// Created by Ðñ¸ç on 2022-09-18.
//

#ifndef RBTREE__SET_H
#define RBTREE__SET_H

namespace ljx
{
	template<class K, class V>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		bool insert(const K& k)
		{
			_t.Insert(k);

			return true;
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}

#endif //RBTREE__SET_H
