#include <iostream>
#include <stack>
#include <queue>
#include "Stack.h"
#include "Queue.h"

using namespace std;

#include "PriorityQueue.h"


void test_stack()
{
	ljx::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

void test_queue()
{
//	queue<int> q;
	ljx::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void test_priority_queue()
{
	// 默认是大堆，默认大的优先级优先，less
//	priority_queue<int> pq;
	// 变成小堆，小的优先级高，怎么处理 greater
//	priority_queue<int, vector<int>, greater<int>> pq;
	ljx::priority_queue<int> pq;
	pq.push(3);
	pq.push(5);
	pq.push(6);
	pq.push(1);
	pq.push(4);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
};

// 仿函数 -- 函数对象 	类的对象可以像函数一样去使用
struct LessInt
{
	bool operator()(int l, int r)
	{
		return l < r;
	}
};

// 函数跟上面实现的东西一样，对比学习一下：
bool LessFunc1(int l, int r)
{
	return l < r;
}

int main()
{
//	test_stack();
//	test_queue();
//	test_priority_queue();
	cout << LessFunc1(1, 2) << endl;

	LessInt LessFunc2;
	cout << LessFunc2(1, 2) << endl;

	return 0;
}


