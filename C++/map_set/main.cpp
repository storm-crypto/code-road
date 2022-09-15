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

	auto it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << ":" << (*it).second << " ";
		it++;
	}
	cout << endl;
}

void test_map3()
{
	// 1、统计次数 2、找出大家最喜欢的三种水果
	string arr[] = {"香蕉", "苹果", "香蕉", "草莓"};
//	// 统计次数的方式1
//	map<string, int> countMap;
//	for (const auto& str : arr)
//	{
//		// 思路：第一次出现，插入<str, 1>，后续再出现++次数ret->second
//		auto ret = countMap.find(str);
//		if (ret != countMap.end())
//		{
//			ret->second++;
//		}
//		else
//		{
//			countMap.insert(make_pair(str, 1));
//		}
//	}
//
//	for (const auto& e : countMap)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}

	// 统计次数的方式2
	map<string, int> countMap;
	for (const auto& str : arr)
	{
		// 先插入，如果str已经在map中，insert会返回str所在节点的迭代器，我们++次数即可
		auto ret = countMap.insert(make_pair(str, 1));
		if (ret.second == false)
		{
			// 插入失败
			ret.first->second++;
		}
	}

	for (const auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}
int main()
{
//	test_set2();
//	test_set3();
	test_map3();

	return 0;
}
