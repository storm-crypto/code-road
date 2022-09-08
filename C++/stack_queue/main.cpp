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
	// Ĭ���Ǵ�ѣ�Ĭ�ϴ�����ȼ����ȣ�less
//	priority_queue<int> pq;
	// ���С�ѣ�С�����ȼ��ߣ���ô���� greater
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

// �º��� -- �������� 	��Ķ����������һ��ȥʹ��
struct LessInt
{
	bool operator()(int l, int r)
	{
		return l < r;
	}
};

// ����������ʵ�ֵĶ���һ�����Ա�ѧϰһ�£�
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


