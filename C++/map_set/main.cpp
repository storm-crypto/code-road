#include <iostream>
#include <set>

using namespace std;

void test_set()
{
	set<int> s;
	// 插入
	s.insert(1);
	s.insert(3);
	s.insert(25);
	s.insert(49);
	s.insert(10);
	s.insert(10);

	// 排序 + 去重
	// 遍历方式1 :
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// 遍历方式2：
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

}

int main()
{
	test_set();

	return 0;
}
