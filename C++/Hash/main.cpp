#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include "HashTable.h"

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

		// find
		auto pos = us.find(2);
		if (pos != us.end())
		{
			cout << "ÕÒµ½ÁË" << endl;
		}
		else
		{
			cout << "Ã»ÕÒµ½" << endl;
		}
	}

	void test_unordered_map1()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "ÅÅĞò"));
		dict["left"] = "×ó±ß";
		dict["left"] = "Ê£Óà";

		unordered_map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			it++;
		}
		cout << endl;
	}
}

int main()
{
//	std::test_unordered_set1();
//	std::test_unordered_map1();

	CloseHash::TestHashTable();

	return 0;
}
