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

	// 练习：检查单词是否拼写正确
	// 思路：词库中单词都放进set对象中，把每个写出来的单词
	// 去set里面查一下，看在不在，在就是正确的，不在就是错误的拼写
	set<string> strSet;
	strSet.insert("abc");
	strSet.insert("ljx");

	auto ret = strSet.find("abc");
	if (ret != strSet.end())
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout <<  "没有找到" << endl;
	}


}

int main()
{
	test_set();

	return 0;
}
