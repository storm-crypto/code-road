#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
using namespace std;

//mutex mtx;
//
//void f(int N)
//{
//	mtx.lock();
//	for (int i = 0; i < N; i++)
//	{
//		cout << this_thread::get_id() << ":" << i << endl;
//	}
//	mtx.unlock();
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<thread> vthreads;
//	vthreads.resize(n);
//	for (auto& td : vthreads)
//	{
//		td = thread(f, 100);
//	}
//
//	for (auto& td : vthreads)
//	{
//		td.join();
//	}
//
//	return 0;
//}

// 用lambda表达式来玩，上面那种是函数指针的方式来玩的

//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<thread> vthreads;
//	vthreads.resize(n);
//	mutex mtx;
//	int N = 100;
//	atomic<int> x = 0;
//	for (auto& td : vthreads)
//	{
//		// 串行
//		td = thread([&mtx, &N, &x]
//					{
//						//mtx.lock();
//						for (int i = 0; i < N; i++)
//						{
//							++x;
//						}
//						//mtx.unlock();
//					});
//	}
//
//	for (auto& td : vthreads)
//	{
//		td.join();
//	}
//
//	printf("%d个线程并行对x++了%d次, x:%d", n, N, x);
//
//	return 0;
//}

#include <iostream>
using namespace std;
#include <thread>

void ThreadFunc(int a)
{
	cout << "Thread1" << a << endl;
}

class TF
{
public:
	void operator()()
	{
		cout << "Thread3" << endl;
	}
};
int main()
{
// 线程函数为函数指针
	thread t1(ThreadFunc, 10);
// 线程函数为lambda表达式
	thread t2([]{cout << "Thread2" << endl; });
// 线程函数为函数对象
	TF tf;
	thread t3(tf);
	t1.join();
	t2.join();
	t3.join();
	cout << "Main thread!" << endl;
	return 0;
}