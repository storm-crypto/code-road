#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
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

// ��lambda���ʽ���棬���������Ǻ���ָ��ķ�ʽ�����

int main()
{
	int n;
	cin >> n;

	vector<thread> vthreads;
	vthreads.resize(n);
	mutex mtx;
	int N = 100;
	int x = 0;
	for (auto& td : vthreads)
	{
		// ����
		td = thread([&mtx, &N, &x]
					{
						mtx.lock();
						for (int i = 0; i < N; i++)
						{
							++x;
						}
						mtx.unlock();
					});
	}

	for (auto& td : vthreads)
	{
		td.join();
	}

	printf("%d���̲߳��ж�x++��%d��, x:%d", n, N, x);

	return 0;
}
