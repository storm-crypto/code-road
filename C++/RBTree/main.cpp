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
	m.insert(make_pair(3, 3));
	m.insert(make_pair(9, 9));
	m.insert(make_pair(0, 0));

	ljx::map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << ":" << (*it).second << endl;
		++it;
	}

	ljx::set<int, int> s;
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(1);

	ljx::set<int, int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	ljx::set<int, int>::reverse_iterator rsit = s.rbegin();
	while (rsit != s.rend())
	{
		cout << *rsit << " ";
		++rsit;
	}
	cout << endl;

	return 0;
}

