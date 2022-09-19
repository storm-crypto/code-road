//
// Created by ��� on 2022-09-18.
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
		// ����ʹ����typename�������Ӻ�ȥ������࣬��ֹ��Ϊû��ʵ�������Ҳ��������
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::reverse_iterator reverse_iterator;

		reverse_iterator rbegin()
		{
			return _t.rbegin();
		}

		reverse_iterator rend()
		{
			return _t.rend();
		}

		// ������
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const K& k)
		{
			return _t.Insert(k);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}

#endif //RBTREE__SET_H
