#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

//// 两个线程对同一个变量++
//int x = 0;
//mutex mtx;
//
//void Func(int n)
//{
//	// 加锁，加在循环里面还是循环外面？为什么？
//	mtx.lock();
//	for (int i = 0; i < n; i++)
//	{
//		cout << this_thread::get_id() << "->" << x << endl; // 看一下是哪个进程在+x
//		++x;
//	}
//	mtx.unlock();
//
//}
//
//int main()
//{
//	thread t1(Func, 10);
//	thread t2(Func, 20);
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}

// 使用原子操作的++
//atomic<int> x = 0;
//
//void Func(int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		++x;
//	}
//
//}

// 使用lambda表达式 + 锁的形式
int main()
{
	int x = 0;
	mutex mtx;
	int N = 10000000;
	int costTime1 = 0;

	thread t1([&]{
		int begin1 = clock();
		mtx.lock();
		for (int i = 0; i < N; i++)
		{
			++x;
		}
		mtx.unlock();
		int end1 = clock();

		costTime1 += (end1 - begin1);
	});

	thread t2([&]{
	  int begin2 = clock();
	  mtx.lock();
	  for (int i = 0; i < N; i++)
	  {
		  ++x;
	  }
	  mtx.unlock();
	  int end2 = clock();
	  costTime1 += (end2 - begin2);

	});

	t1.join();
	t2.join();

	cout << x  << ":" << costTime1 << endl;

	return 0;
}
