#include <iostream>
#include <set>
#include <map>

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

// 删除
void test_set2()
{
	set<int> s;
	// 插入
	s.insert(1);
	s.insert(3);
	s.insert(25);
	s.insert(49);
	s.insert(10);
	s.insert(10);
	// 删除方式1：先查找，找到了再删，没找到就会报错
	auto pos = s.find(3);
	s.erase(pos);

	// 删除方式2：传数字，不在就不处理也不报错
	s.erase(25);


	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set3()
{
	multiset<int> s;
	// 插入
	s.insert(1);
	s.insert(3);
	s.insert(25);
	s.insert(49);
	s.insert(10);
	s.insert(10);

	// 排序
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_map1()
{
	map<int, double> m;
	// 插入,调用pair的构造函数，构造一个匿名对象插入
	m.insert(pair<int, double>(1, 1.1));
	m.insert(pair<int, double>(5, 5.5));
	m.insert(pair<int, double>(2, 2.2));

	// 调用函数模板，构造对象,好处是不需要去声明pair的参数，让函数模板自己推演，用起来方便些
	m.insert(make_pair(2, 2.2));


}

int main()
{
//	test_set2();
	test_set3();

	return 0;
}
