//
// Created by ��� on 2022-09-24.
//

#ifndef BITSET_H
#define BITSET_H
#include <assert.h>

namespace ljx
{
	// �÷�����ģ�����������
	template<size_t N>
	class BitSet
	{
	public:
		BitSet()
		{
			_bits.resize(N / 32 + 1, 0);
		}

		// ��xӳ���λ���Ϊ1
		void Set(size_t x)
		{
			assert(x < N);
			// ���xӳ���λ�ڵڼ�������
			// ���xӳ���λ����������ĵڼ���λ
			size_t i = x / 32;
			size_t j = x % 32;

			// _bits[i]�ĵ�jλ���Ϊ1
			_bits[i] |= (1 << j);
		}

		// �ѵ�xӳ���λΪ���0�����Ҳ�Ӱ����������λ
		void ReSet(size_t x)
		{
			assert(x < N);
			size_t i = x / 32;
			size_t j = x % 32;

			// _bits[i]�ĵ�jλ��ǳ�0�����Ҳ�Ӱ������λ
			_bits[i] &= (~(1 << j));
		}

		bool Test(size_t x)
		{
			assert(x < N);
			size_t i = x / 32;
			size_t j = x % 32;

			// �����jλ��1������Ƿ�0��true
			// �����jλ��0�������0��false
			return _bits[i] & (1 << j);
		}
	private:
		vector<int> _bits;
	};

	void TestBitSet()
	{
		BitSet<-1> bs;

	}
}

#endif //BITSET_H
