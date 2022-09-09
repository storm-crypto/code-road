//
// Created by 旭哥 on 2022-09-08.
//

#ifndef STACK_QUEUE_PRIORITYQUEUE_H
#define STACK_QUEUE_PRIORITYQUEUE_H

namespace ljx
{
	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		void AdjustUp(size_t child)
		{
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				// 小堆 >
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}

		void AdjustDown(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				// 选出左右孩子中小的那个
				if (child + 1  < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}

				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			AdjustDown(0);
		}

		T top()
		{
			return _con[0];
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

#endif //STACK_QUEUE_PRIORITYQUEUE_H
