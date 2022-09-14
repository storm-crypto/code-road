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

void TestBSTree4()
{
	// ͳ��ˮ�����ֵĴ���
	string arr[] = {"ƻ��", "ƻ��", "����", "����"};
	KV::BSTree<string, int> countTree;
	for (const auto& str : arr)
	{
		// �Ȳ������ˮ���ڲ�����������
		auto ret = countTree.FindR(str);
		if (ret == NULL)
		{
			countTree.InsertR(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}

	countTree.InOrder();
}

int main()
{
	TestBSTree4();

	return 0;
}
