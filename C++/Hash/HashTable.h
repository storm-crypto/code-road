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

//namespace OpenHash
//{
//	template<class K, class V>
//	struct HashNode
//	{
//		HashNode<K, V>* _next;
//		pair<K, V> _kv;
//
//		// ���캯��
//		HashNode(const pair<K, V>& kv)
//			:_next(nullptr)
//			, _kv(kv)
//		{}
//	};
//
//	template<class K>
//	struct Hash
//	{
//		size_t operator()(const K& key)
//		{
//			return key;
//		}
//	};
//
//	// ��Ϊ���key��string���͵ģ���������ػ�������
//	// �ػ���
//	template<>
//	struct Hash<string>
//	{
//		size_t operator()(const string& key)
//		{
//			// ��BKDR��ϣ�㷨
//			size_t value = 0;
//			for (auto ch : key)
//			{
//				value += ch;
//				value *= 131;
//			}
//			return value;
//		}
//	};
//
//	template<class K, class V, class HashFunc = Hash<K>>
//	class HashTable
//	{
//		typedef HashNode<K, V> Node;
//	public:
//
//		size_t GetNextPrime(size_t prime)
//		{
//			const int PRIMECOUNT = 28;
//			static const size_t primeList[PRIMECOUNT] =
//			{
//				53ul, 97ul, 193ul, 389ul, 769ul,
//				1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
//				49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
//				1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
//				50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
//				1610612741ul, 3221225473ul, 4294967291ul
//			};
//
//			size_t i = 0;
//			for(; i < PRIMECOUNT; ++i)
//			{
//				if(primeList[i] > prime)
//					return primeList[i];
//			}
//			return primeList[i];
//		}
//
//
//		bool Insert(const pair<K, V>& kv)
//		{
//			HashFunc hf;
//			if (Find(kv.first))
//				return false;
//
//			// �������ӵ�1ʱ����������
//			if (_n == _table.size())
//			{
//
//				vector<Node*> newTable;
//				size_t newSize = _table.size() == 0 ? 8 : _table.size() * 2;
//				// newTable.resize(newSize, nullptr);
//				newTable.resize(GetNextPrime(_table.size()));
//
//
//				// �����ɱ�ȡ�ɱ�Ľ�㣬������ӳ��λ�ã��ҵ��±���
//				for (size_t i = 0; i < _table.size(); i++)
//				{
//					if (_table[i])
//					{
//						Node* cur = _table[i];
//						while (cur)
//						{
//							Node* next = cur->_next;
//							size_t index = hf(cur->_kv.first) % newTable.size();
//							// ��cur���ͷ�嵽newTable��
//							cur->_next = newTable[index];
//							newTable[index] = cur;
//
//							cur = next;
//						}
//
//						// ȫ��������֮������ӵ����������Ϊ����
//						_table[i] = nullptr;
//					}
//				}
//				// newTable��_table����
//				_table.swap(newTable);
//			}
//
//
//			size_t index = hf(kv.first) % _table.size();
//			Node* newnode = new Node(kv);
//
//			// ͷ��
//			newnode->_next = _table[index];
//			_table[index] = newnode;
//			++_n;
//
//			return true;
//		}
//
//		Node* Find(const K& key)
//		{
//			if (_table.size() == 0)
//				return nullptr;
//
//			HashFunc hf;
//			size_t index = hf(key) % _table.size();
//			Node* cur = _table[index];
//			while (cur)
//			{
//				if (cur->_kv.first == key) return cur;
//				else cur = cur->_next;
//			}
//
//			return nullptr;
//		}
//
//		bool Erase(const K& key)
//		{
//			HashFunc hf;
//			size_t index = hf(key) % _table.size();
//			Node* cur = _table[index];
//			Node* prev = nullptr;
//			while (cur)
//			{
//				if (cur->_kv.first == key)
//				{
//					// cur�ǵ�һ���������
//					if (cur == _table[index])
//					{
//						_table[index] = cur->_next;
//					}
//					else
//					{
//						prev->_next = cur->_next;
//					}
//
//					--_n;
//					delete cur;
//					return true;
//				}
//
//				prev = cur;
//				cur = cur->_next;
//			}
//
//			return false;
//		}
//
//	private:
//		vector<Node*> _table;
//		size_t _n = 0; // ��Ч���ݵĸ���
//	};
//
//	void TestHashTable1()
//	{
//		int a[] = {1, 5, 10, 100000, 100, 18, 15, 7, 40};
//		HashTable<int, int> ht;
//		for (auto e : a)
//		{
//			ht.Insert(make_pair(e, e));
//		}
//	}
//
//	void TestHashTable2()
//	{
//		string a[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "����", "ƻ��" };
//		HashTable<string, int> ht;
//		for (auto str : a)
//		{
//			auto ret = ht.Find(str);
//			if (ret)
//			{
//				ret->_kv.second++;
//			}
//			else
//			{
//				ht.Insert(make_pair(str, 1));
//			}
//		}
//	}
//
//}

namespace OpenHash
{
	template<class T>
	struct HashNode
	{
		HashNode<T>* _next;
		T _data;

		// ���캯��
		HashNode(const T& data)
			:_next(nullptr)
			, _data(data)
		{}
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

	// ǰ������
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;

	// ������
	template<class K, class T, class KeyOfT, class HashFunc = Hash<K>>
	struct __HTIterator
	{
		typedef HashNode<T> Node;
		typedef __HTIterator<K, T, KeyOfT, HashFunc> Self;
		typedef HashTable<K, T, KeyOfT, HashFunc> HT;
		Node* _node;
		HT* _pht;

		// ���캯��
		__HTIterator(Node* node, HT* pht)
			:_node(node)
			, _pht(pht)
		{}


		// ���ѵ�
		Self& operator++()
		{
			// 1����ǰͰ�л������ݣ���ô���ڵ�ǰͰ������
			// 2����ǰͰ�����ˣ���Ҫ����һ��Ͱȥ��
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				// ��ȡ��ǰͰ���ڵ�λ��
				KeyOfT kot;
				HashFunc hf;
				size_t index = hf(kot(_node->_data)) % _pht->_table.size();
				++index;
				// �����һ��Ͱ��λ�ò�Ϊ�գ���ô���ҵ���һ��Ͱ��
				while (index < _pht->_table.size())
				{
					if (_pht->_table[index]) // �ҵ���һ��Ͱ��λ����
					{
						_node = _pht->_table[index];
						return *this;
					}
					else
					{
						++index;
					}

				}
				_node = nullptr;
			}
			return *this;
		}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		bool operator != (const Self& s) const
		{
			return _node != s._node;
		}

		bool operator == (const Self& s) const
		{
			return _node == s._node;
		}

	};

	template<class K, class T, class KeyOfT, class HashFunc = Hash<K>>
	class HashTable
	{
		typedef HashNode<T> Node;

		template<class K1, class T1, class KeyOfT1, class HashFunc1>
		friend struct __HTIterator;
	public:
		typedef __HTIterator<K, T, KeyOfT, HashFunc> iterator;
		//

		iterator begin()
		{
			size_t i = 0;
			while (i < _table.size())
			{
				if (_table[i])
				{
					// �ҵ���һ��Ͱ��λ����,���ص�����
					return iterator(_table[i], this);
				}
				i++;
			}

			// ���û�ҵ���˵����ϣͰ�ǿյģ�����end()
			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		size_t GetNextPrime(size_t prime)
		{
			const int PRIMECOUNT = 28;
			static const size_t primeList[PRIMECOUNT] =
				{
					53ul, 97ul, 193ul, 389ul, 769ul,
					1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
					49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
					1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
					50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
					1610612741ul, 3221225473ul, 4294967291ul
				};

			size_t i = 0;
			for(; i < PRIMECOUNT; ++i)
			{
				if(primeList[i] > prime)
					return primeList[i];
			}
			return primeList[i];
		}


		bool Insert(const T& data)
		{
			HashFunc hf;
			KeyOfT kot;
			if (Find(kot(data)))
				return false;

			// �������ӵ�1ʱ����������
			if (_n == _table.size())
			{

				vector<Node*> newTable;
				//size_t newSize = _table.size() == 0 ? 8 : _table.size() * 2;
				// newTable.resize(newSize, nullptr);
				newTable.resize(GetNextPrime(_table.size()));


				// �����ɱ�ȡ�ɱ�Ľ�㣬������ӳ��λ�ã��ҵ��±���
				for (size_t i = 0; i < _table.size(); i++)
				{
					if (_table[i])
					{
						Node* cur = _table[i];
						while (cur)
						{
							Node* next = cur->_next;
							size_t index = hf(kot(data)) % newTable.size();
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


			size_t index = hf(kot(data)) % _table.size();
			Node* newnode = new Node(data);

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

			KeyOfT kot;
			HashFunc hf;
			size_t index = hf(key) % _table.size();
			Node* cur = _table[index];
			while (cur)
			{
				if (kot(cur->_data) == key) return cur;
				else cur = cur->_next;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashFunc hf;
			size_t index = hf(key) % _table.size();
			Node* cur = _table[index];
			Node* prev = nullptr;
			while (cur)
			{
				if (kot(cur->_data) == key)
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


}



#endif //HASH__HASHTABLE_H
