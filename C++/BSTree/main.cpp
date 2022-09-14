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

	// ����ɾ��ʱ�������нڵ㶼ɾһ��
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

	// ��������
	K::BSTree<int> copy = t;
	copy.InOrder();
}

// ����KVģ�ͣ����ӣ���Ӣ�ʵ�
void TestBSTree3()
{
	KV::BSTree<string, string> dict;
	dict.InsertR("string", "�ַ���");
	dict.InsertR("tree", "��");
	dict.InsertR("left", "���");
	dict.InsertR("right", "�ұ�");
	// ����ʿ������еĵ���
	string str;
	while (cin >> str)
	{

		KV::BSTreeNode<string, string>* ret = dict.FindR(str);
		if (ret == nullptr)
		{
			cout << "����ƴд���󣬴ʿ���û���������:" << str << endl;
 		}
 		else
		{
 			cout << str << " ���ķ���:" << ret->_value << endl;
		}
	}
}

int main()
{
	TestBSTree3();

	return 0;
}
