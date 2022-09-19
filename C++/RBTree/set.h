//
// Created by 旭哥 on 2022-09-18.
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
		// 这里使用了typename，让他延后去找这个类，防止因为没有实例化，找不到这个类
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;

		// 最左结点
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

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
