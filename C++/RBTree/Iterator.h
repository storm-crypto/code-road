//
// Created by 旭哥 on 2022-09-19.
//

#ifndef RBTREE__ITERATOR_H
#define RBTREE__ITERATOR_H

// 实现一个反向迭代器 -- 实际上它是一个迭代器适配器
template<class Iterator>
struct ReverseIterator
{
	// Iterator::reference需要到模板中去取，所以要typename一下
	typedef typename Iterator::reference Ref;
	typedef typename Iterator::pointer Ptr;
	typedef ReverseIterator<Iterator> Self;

	// 用正向迭代器来构造反向迭代器
	ReverseIterator(Iterator it)
		:_it(it)
	{

	}

	Ref operator*()
	{
		return *_it;
	}

	Ptr operator->()
	{
		return _it.operator->();
	}

	Self& operator++()
	{
		--_it;
		return *this;
	}

	Self& operator--()
	{
		++_it;
		return *this;
	}

	bool operator!=(const Self& s) const
	{
		// 拿他的正向迭代器去比较
		return _it != s._it;
	}

	bool operator==(const Self& s) const
	{
		// 拿他的正向迭代器去比较
		return _it == s._it;
	}

	Iterator _it;
};
#endif //RBTREE__ITERATOR_H
