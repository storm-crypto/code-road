//
// Created by Ðñ¸ç on 2022-09-08.
//

#ifndef STACK_QUEUE_PRIORITYQUEUE_H
#define STACK_QUEUE_PRIORITYQUEUE_H

namespace ljx
{
	template<class T, class Container = vector<T>>
	class priority_queue
	{
	public:
		void AdjustUp(size_t child)
		{
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				// Ð¡¶Ñ >
				if (_con[parent] > _con[child])
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

		void pop()
		{

		}

		T top()
		{

		}

	private:
		Container _con;
	};
}

#endif //STACK_QUEUE_PRIORITYQUEUE_H
