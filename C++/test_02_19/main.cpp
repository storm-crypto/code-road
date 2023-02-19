#include <iostream>
#include <functional>
#include <thread>
#include <mutex>

using namespace std;

// 两个线程对同一个变量++
int x = 0;
mutex mtx;

void Func(int n)
{
	// 加锁，加在循环里面还是循环外面？为什么？
	mtx.lock();
	for (int i = 0; i < n; i++)
	{
		cout << this_thread::get_id() << "->" << x << endl; // 看一下是哪个进程在+x
		++x;
	}
	mtx.unlock();

}

int main()
{
	thread t1(Func, 10);
	thread t2(Func, 20);

	t1.join();
	t2.join();

	cout << x << endl;

	return 0;
}
