//
// Created by ��� on 2022-09-24.
//

#ifndef BITSET_H
#define BITSET_H

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
			size_t i = x / 32;
			size_t j = x % 32;

			// _bits[i]�ĵ�jλ��ǳ�0�����Ҳ�Ӱ������λ
			_bits[i] &= (~(1 << j));
		}
	private:
		vector<int> _bits;
	};
}

#endif //BITSET_H
