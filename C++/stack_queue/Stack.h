//
// Created by 旭哥 on 2022-09-08.
//

#ifndef STACK_QUEUE__STACK_H
#define STACK_QUEUE__STACK_H

namespace ljx
{
	// 常规的实现stack的思路
	template<class T>
	class stack
	{
	public:
		// ....

	private:
		T* _a;
		size_t _size;
		size_t _capacity;
	};
}

#endif //STACK_QUEUE__STACK_H
