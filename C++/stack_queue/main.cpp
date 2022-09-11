#include <iostream>
#include <stack>
#include <queue>
#include "Stack.h"
#include "Queue.h"
#include <deque>
#include <cstring>

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

// 大堆
//	ljx::priority_queue<int> pq;

	// 变成小堆
	ljx::priority_queue<int , vector<int>, ljx::greater<int>> pq;
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

template<class T>
struct Less
{
	bool operator()(const T& l, const T& r)
	{
		return l < r;
	}
};

// 函数跟上面实现的东西一样，对比学习一下：
bool LessFunc1(int l, int r)
{
	return l < r;
}

void test_deque()
{
	deque<int> dq;
	// 尾插头插
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	dq.push_back(4);
	dq.push_front(1);
	dq.push_front(2);
	dq.push_front(3);
	dq.push_front(4);

	// 遍历
	for (size_t i = 0; i < dq.size(); i++)
	{
		cout << dq[i] << " ";
	}
	cout << endl;

	deque<int>::iterator it = dq.begin();
	while (it != dq.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}

//int main()
//{
////	test_stack();
////	test_queue();
////	test_priority_queue();
////	cout << LessFunc1(1, 2) << endl;
////
////	LessInt LessFunc2;
////	cout << LessFunc2(1, 2) << endl;
////
////	Less<double> less;
////	cout << less(3.3, 2.3) << endl;
//
//	test_deque();
//
//	// 今天摆烂了，没有学习，但是github不能断啊，所以就来个commit吧
//
//	return 0;
//}

//#define N 100

// 定义一个静态的数组
//template<class T = int, size_t N = 8>
//class Array
//{
//private:
//	T _a[N];
//};
//
//int main()
//{
//	Array<int, 100> arr1;
//	Array<int, 1000> arr2;
//
//	return 0;
//}

// 模板的特化
template<class T>
bool IsEqual(const T& left, const T& right)
{
	return left == right;
}

// 针对字符串类型要特殊化处理 -- 写一份函数模板的特殊出来
bool IsEqual(const char* left, const char* right)
{
	return strcmp(left, right) == 0;
}

int main()
{
	cout << IsEqual(1, 2) << endl;
	cout << IsEqual(1.1, 1.1) << endl;

	char p1[] = "hello";
	char p2[] = "hello";
	cout << IsEqual(p1, p2) << endl;

	const char* p3 = "hello";
	const char* p4 = "hello";
	cout << IsEqual(p3, p4) << endl;

	return 0;
}


