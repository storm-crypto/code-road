#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex mtx;

void f(int N)
{
	mtx.lock();
	for (int i = 0; i < N; i++)
	{
		cout << this_thread::get_id() << ":" << i << endl;
	}
	mtx.unlock();
}

int main()
{
	int n;
	cin >> n;

	vector<thread> vthreads;
	vthreads.resize(n);
	for (auto& td : vthreads)
	{
		td = thread(f, 100);
	}

	for (auto& td : vthreads)
	{
		td.join();
	}

	return 0;
}
