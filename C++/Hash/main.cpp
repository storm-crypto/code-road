#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

namespace std
{
	void test_unordered_set1()
	{
		unordered_set<int> us;
		us.insert(2);
		us.insert(1);
		us.insert(2);
		us.insert(3);
		us.insert(5);
		us.insert(6);
		us.insert(8);

		auto it = us.begin();
		while (it != us.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : us)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}

int main()
{
	std::test_unordered_set1();

	return 0;
}
