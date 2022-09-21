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

	template<class K>
	struct Hash
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	// ��Ϊ���key��string���͵ģ���������ػ�������
	// �ػ���
	template<>
	struct Hash<string>
	{
		size_t operator()(const string& key)
		{
			// ��BKDR��ϣ�㷨
			size_t value = 0;
			for (auto ch : key)
			{
				value += ch;
				value *= 131;
			}
			return value;
		}
	};


	template<class K, class V, class HashFunc = Hash<K>>
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			HashData<K, V>* ret = Find(kv.first);
			if (ret)
			{
				return false;
			}

			// �������Ӵ���0.7������
			// ����֮ǰҪ�������ĸ�������
			if (_table.size() == 0)
			{
				_table.resize(10);
			}
		    else if ((double )_n / (double)_table.size() > 0.7)
			{
				// ����
				HashTable<K, V, HashFunc> newHT;
				newHT._table.resize(_table.size() * 2);
				for (auto& e : _table)
				{
					if (e._state == EXITS)
					{
						newHT.Insert(e._kv);
					}
				}

				_table.swap(newHT._table);
			}
			HashFunc hf;
			size_t start = hf(kv.first) % _table.size();
		    size_t index = start;
			// �����ǰ��λ���ھ���Ҫ����̽������λ�� -- ����̽�� or ����̽��
			size_t i = 1;
			while (_table[index]._state == EXITS)
			{
				index = start + i;
				index %= _table.size(); // ��ͷ��Ҫ����
				i++;
			}

			_table[index]._kv = kv;
			_table[index]._state = EXITS;
			++_n;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			if (_table.size() == 0)
			{
				return nullptr;
			}
			HashFunc hf;
			size_t start = hf(key) % _table.size();
			size_t index = start;
			size_t i = 1;
			// �����ڿվͼ�����
			while(_table[index]._state != EMPTY)
			{
				if (_table[index]._state == EXITS
				&& _table[index]._kv.first == key)
				{
					return &_table[index];
				}

				index = start + i;
				index %= _table.size();
				i++;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret == nullptr)
			{
				return false;
			}
			else
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
		}

	private:
		/*HashData* _table;
		size_t _size;	  // ��¼���˶��ٸ�������
		size_t _capacity; // ����*/
		// ��vector���������涨�����������
		vector<HashData<K, V>> _table;
		size_t _n = 0; // �洢����Ч���ݸ���
	};

	struct IntHashFunc
	{
		int operator()(int i)
		{
			return i;
		}
	};

	void TestHashTable1()
	{
		int a[] = {1, 5, 10, 100000, 100, 18, 15, 7, 40};
		HashTable<int, int, IntHashFunc> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
	}

	struct stringHashFunc
	{
		// ����º����Ļ��������ǽ��ַ���ת�ɶ�Ӧ������ֵ����Ϊ���Ͳ���ȡģ��ӳ��λ��
		// �������ַ�����ͬ��ת��������ֵ��ͬ
		size_t operator()(const string& s)
		{
			// ��BKDR��ϣ�㷨
			size_t value = 0;
			for (auto ch : s)
			{
				value += ch;
				value *= 131;
			}
			return value;
		}
	};

	void TestHashTable2()
	{
		string a[] = {"ƻ��", "����", "ƻ��"};
		HashTable<string, int, stringHashFunc> ht;
		for (auto str : a)
		{
			auto ret = ht.Find(str);
			if (ret)
			{
				ret->_kv.second++;
			}
			else
			{
				ht.Insert(make_pair(str, 1));
			}
		}
	}
}

namespace OpenHash
{
	template<class K, class V>
	struct HashNode
	{
		HashNode<K, V>* _next;
		pair<K, V> _kv;

		// ���캯��
		HashNode(const pair<K, V>& kv)
			:_next(nullptr)
			, _kv(kv)
		{}
	};

	template<class K, class V>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

			// �������ӵ�1ʱ����������
			if (_n == _table.size())
			{
				vector<Node*> newTable;
				size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
				newTable.resize(newSize);

				// �����ɱ�ȡ�ɱ�Ľ�㣬������ӳ��λ�ã��ҵ��±���
				for (size_t i = 0; i < _table.size(); i++)
				{
					if (_table[i])
					{
						Node* cur = _table[i];
						while (cur)
						{
							Node* next = cur->_next;
							size_t index = cur->_kv.first % newTable.size();
							// ��cur���ͷ�嵽newTable��
							cur->_next = newTable[index];
							newTable[index] = cur;

							cur = next;
						}

						// ȫ��������֮������ӵ����������Ϊ����
						_table[i] = nullptr;
					}
				}
				// newTable��_table����
				_table.swap(newTable);
			}

			size_t index = kv.first % _table.size();
			Node* newnode = new Node(kv);

			// ͷ��
			newnode->_next = _table[index];
			_table[index] = newnode;
			++_n;

			return true;
		}

		Node* Find(const K& key)
		{
			if (_table.size() == 0)
				return nullptr;

			size_t index = key % _table.size();
			Node* cur = _table[index];
			while (cur)
			{
				if (cur->_kv.first == key) return cur;
				else cur = cur->_next;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			size_t index = key % _table.size();
			Node* cur = _table[index];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					// cur�ǵ�һ���������
					if (cur == _table[index])
					{
						_table[index] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					--_n;
					delete cur;
					return true;
				}

				prev = cur;
				cur = cur->_next;
			}

			return false;
		}

	private:
		vector<Node*> _table;
		size_t _n = 0; // ��Ч���ݵĸ���
	};

	void TestHashTable1()
	{
		int a[] = {1, 5, 10, 100000, 100, 18, 15, 7, 40};
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
	}

}

#endif //HASH__HASHTABLE_H
