#include "BinarySearchTree.h"
#include <string>

void TestBSTree1()
{
	K::BSTree<int> t;
	int a[] = {5, 3, 4, 1, 7, 8, 2, 6, 0, 9};
	for (auto e : a)
	{
		t.Insert(e);
	}

	t.InOrder();

	t.EraseR(8);
	t.InOrder();

	t.EraseR(5);
	t.InOrder();

	// 测试删除时，把所有节点都删一遍
	for (auto e : a)
	{
		t.EraseR(e);
		t.InOrder();
	}
}

void TestBSTree2()
{
	K::BSTree<int> t;
	int a[] = {5, 3, 4, 1, 7, 8, 2, 6, 0, 9};
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();

	// 拷贝构造
	K::BSTree<int> copy = t;
	copy.InOrder();
}

// 测试KV模型，例子：中英词典
void TestBSTree3()
{
	KV::BSTree<string, string> dict;
	dict.InsertR("string", "字符串");
	dict.InsertR("tree", "树");
	dict.InsertR("left", "左边");
	dict.InsertR("right", "右边");
	// 插入词库中所有的单词
	string str;
	while (cin >> str)
	{

		KV::BSTreeNode<string, string>* ret = dict.FindR(str);
		if (ret == nullptr)
		{
			cout << "单词拼写错误，词库中没有这个单词:" << str << endl;
 		}
 		else
		{
 			cout << str << " 中文翻译:" << ret->_value << endl;
		}
	}
}

int main()
{
	TestBSTree3();

	return 0;
}
