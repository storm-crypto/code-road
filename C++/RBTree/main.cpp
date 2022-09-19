#include "RBTree.h"
#include "map.h"
#include "set.h"

//void TestRBTree()
//{
//	int a[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//	}
//
//	t.InOrder();
//	cout << t.CheckBalance() << endl;
//
//
//}
//
//int main()
//{
//	TestRBTree();
//
//	return 0;
//}

int main()
{
	ljx::map<int, int> m;
	m.insert(make_pair(1, 1));

	ljx::set<int, int> s;
	s.insert(1);

	return 0;
}

