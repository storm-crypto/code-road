//
// Created by ��� on 2022-09-19.
//

#ifndef RBTREE__ITERATOR_H
#define RBTREE__ITERATOR_H

// ʵ��һ����������� -- ʵ��������һ��������������
template<class Iterator>
struct ReverseIterator
{
	// Iterator::reference��Ҫ��ģ����ȥȡ������Ҫtypenameһ��
	typedef typename Iterator::reference Ref;
	typedef typename Iterator::pointer Ptr;
	typedef ReverseIterator<Iterator> Self;

	// ����������������췴�������
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
		// ���������������ȥ�Ƚ�
		return _it != s._it;
	}

	bool operator==(const Self& s) const
	{
		// ���������������ȥ�Ƚ�
		return _it == s._it;
	}

	Iterator _it;
};
#endif //RBTREE__ITERATOR_H
