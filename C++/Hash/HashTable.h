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
	enum State
	{
		EMPTY,
		EXITS,
		DELETE,
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY; // ״̬
	};

	template<class K, class V>
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			// �������Ӵ���0.7������
			// ����֮ǰҪ�������ĸ�������
			if (_table.size() == 0)
			{
				_table.resize(10);
			}
		    else if ((double )_n / (double)_table.size() > 0.7)
			{
				// ����
				HashTable<K, V> newHT;
				newHT.resize(_table.size() * 2);
				for (auto& e : _table)
				{
					if (e._state == EXITS)
					{
						newHT.Insert(e._kv);
					}
				}

				_table.swap(newHT._table);
			}

			size_t index = kv.first % _table.size();
			// �����ǰ��λ���ھ���Ҫ����̽������λ�� -- ����̽�� or ����̽��
			size_t i = 1;
			while (_table[index]._state == EXITS)
			{
				index += i;
				index %= _table.size(); // ��ͷ��Ҫ����
			}

			_table[index]._kv = kv;
			_table[index]._state = EXITS;
			++_n;
		}

	private:
		/*HashData* _table;
		size_t _size;	  // ��¼���˶��ٸ�������
		size_t _capacity; // ����*/
		// ��vector���������涨�����������
		vector<HashData> _table;
		size_t _n = 0; // �洢����Ч���ݸ���
	};
}

#endif //HASH__HASHTABLE_H
