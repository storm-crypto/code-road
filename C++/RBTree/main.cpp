#include "RBTree.h"

void TestRBTree()
{
	int a[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
	RBTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}


}

int main()
{

	return 0;
}
