//
// Created by ��� on 2022-09-08.
//

#ifndef STACK_QUEUE__STACK_H
#define STACK_QUEUE__STACK_H

#include <vector>
#include <list>
#include <deque>


namespace ljx
{
//	// �����ʵ��stack��˼·
//	template<class T>
//	class stack
//	{
//	public:
//		// ....
//		// ����ӿں���
//
//	private:
//		T* _a;
//		size_t _size;
//		size_t _capacity;
//	};

	// ����������
	template<class T, class Container = std::deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		T top()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};
}

#endif //STACK_QUEUE__STACK_H
