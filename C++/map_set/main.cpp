#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void test_set()
{
	set<int> s;
	// ����
	s.insert(1);
	s.insert(3);
	s.insert(25);
	s.insert(49);
	s.insert(10);
	s.insert(10);

	// ���� + ȥ��
	// ������ʽ1 :
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// ������ʽ2��
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// ��ϰ����鵥���Ƿ�ƴд��ȷ
	// ˼·���ʿ��е��ʶ��Ž�set�����У���ÿ��д�����ĵ���
	// ȥset�����һ�£����ڲ��ڣ��ھ�����ȷ�ģ����ھ��Ǵ����ƴд
	set<string> strSet;
	strSet.insert("abc");
	strSet.insert("ljx");

	auto ret = strSet.find("abc");
	if (ret != strSet.end())
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout <<  "û���ҵ�" << endl;
	}


}

// ɾ��
void test_set2()
{
	set<int> s;
	// ����
	s.insert(1);
	s.insert(3);
	s.insert(25);
	s.insert(49);
	s.insert(10);
	s.insert(10);
	// ɾ����ʽ1���Ȳ��ң��ҵ�����ɾ��û�ҵ���ɾ���ͻᱨ��
	auto pos = s.find(3);
	s.erase(pos);

	// ɾ����ʽ2�������֣����ھͲ�����Ҳ������
	s.erase(25);


	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set3()
{
	multiset<int> s;
	// ����
	s.insert(1);
	s.insert(3);
	s.insert(25);
	s.insert(49);
	s.insert(10);
	s.insert(10);

	// ����
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_map1()
{
	map<int, double> m;
	// ����,����pair�Ĺ��캯��������һ�������������
	m.insert(pair<int, double>(1, 1.1));
	m.insert(pair<int, double>(5, 5.5));
	m.insert(pair<int, double>(2, 2.2));

	// ���ú���ģ�壬�������,�ô��ǲ���Ҫȥ����pair�Ĳ������ú���ģ���Լ����ݣ�����������Щ
	m.insert(make_pair(2, 2.2));

	auto it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << ":" << (*it).second << " ";
		it++;
	}
	cout << endl;
}

void test_map3()
{
	// 1��ͳ�ƴ��� 2���ҳ������ϲ��������ˮ��
	string arr[] = {"�㽶", "ƻ��", "�㽶", "��ݮ"};
//	// ͳ�ƴ����ķ�ʽ1
//	map<string, int> countMap;
//	for (const auto& str : arr)
//	{
//		// ˼·����һ�γ��֣�����<str, 1>�������ٳ���++����ret->second
//		auto ret = countMap.find(str);
//		if (ret != countMap.end())
//		{
//			ret->second++;
//		}
//		else
//		{
//			countMap.insert(make_pair(str, 1));
//		}
//	}
//
//	for (const auto& e : countMap)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}

//	// ͳ�ƴ����ķ�ʽ2
//	map<string, int> countMap;
//	for (const auto& str : arr)
//	{
//		// �Ȳ��룬���str�Ѿ���map�У�insert�᷵��str���ڽڵ�ĵ�����������++��������
//		auto ret = countMap.insert(make_pair(str, 1));
//		if (ret.second == false)
//		{
//			// ����ʧ��
//			ret.first->second++;
//		}
//	}
//
//	for (const auto& e : countMap)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}

	// ͳ�ƴ����ķ�ʽ3
	map<string, int> countMap;
	for (const auto& str : arr)
	{
		countMap[str]++;
	}

	for (const auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

struct MapItCompare
{
	bool operator()(map<string, int>::iterator x, map<string, int>::iterator y)
	{
		return x->second > y->second;
	}
};

void test_map4()
{
	// 1��ͳ�ƴ��� 2���ҳ������ϲ��������ˮ��
	string arr[] = {"�㽶", "ƻ��", "�㽶", "��ݮ"};
	map<string, int> countMap;
	for (const auto& str : arr)
	{
		countMap[str]++;
	}

	// ������ˮ����������

	// ˼·һ����vector������vector�����map�ĵ�����
	vector<map<string, int>::iterator> v;
	auto coutMapIt = countMap.begin();
	while (coutMapIt != countMap.end())
	{
		v.push_back(coutMapIt);
		coutMapIt++;
	}
	// ��vector�����Ԫ�ؽ�������
	sort(v.begin(), v.end(), MapItCompare());

	// ����map����
	map<int, string> sortMap;
	for (auto e : countMap)
	{
		sortMap.insert(make_pair(e.second, e.first));
	}

}

int main()
{
//	test_set2();
//	test_set3();
	test_map3();

	return 0;
}
