//
// Created by 旭哥 on 2022-09-08.
//

#ifndef STACK_QUEUE__STACK_H
#define STACK_QUEUE__STACK_H

#include <vector>
#include <list>
#include <deque>


namespace ljx
{
//	// 常规的实现stack的思路
//	template<class T>
//	class stack
//	{
//	public:
//		// ....
//		// 定义接口函数
//
//	private:
//		T* _a;
//		size_t _size;
//		size_t _capacity;
//	};

	// 容器适配器
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
