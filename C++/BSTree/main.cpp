#include "BinarySearchTree.h"

int main()
{
	BSTree<int> t;
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

	return 0;
}
