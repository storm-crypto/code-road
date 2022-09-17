#include "AVLTree.h"

void TestAVLTree()
{
	int a[] = {1, 3, 5, 7, 6};
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
}

int main()
{
	TestAVLTree();


	return 0;
}
