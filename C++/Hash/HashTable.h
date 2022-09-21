//
// Created by ��� on 2022-09-21.
//

#ifndef HASH__HASHTABLE_H
#define HASH__HASHTABLE_H
#include <vector>
#include <iostream>
using namespace std;
// ��ɢ��
namespace CloseHash
{
	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
	};

	template<class K, class V>
	class HashTable
	{

	private:
		/*HashData* _table;
		size_t _size;	  // ��¼���˶��ٸ�������
		size_t _capacity; // ����*/
		// ��vector���������涨�����������
		vector<HashData> _table;
		size_t _n; // �洢����Ч���ݸ���
	};
}

#endif //HASH__HASHTABLE_H
