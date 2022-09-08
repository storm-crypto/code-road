//
// Created by Ðñ¸ç on 2022-09-08.
//

#ifndef STACK_QUEUE_QUEUE_H
#define STACK_QUEUE_QUEUE_H

#include <deque>

namespace ljx
{
	template<class T, class Container = std::deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		T front()
		{
			return _con.front();
		}

		T back()
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


#endif //STACK_QUEUE_QUEUE_H
