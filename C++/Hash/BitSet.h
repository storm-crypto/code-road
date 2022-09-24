//
// Created by 旭哥 on 2022-09-24.
//

#ifndef BITSET_H
#define BITSET_H
#include <assert.h>

namespace ljx
{
	// 用非类型模板参数来控制
	template<size_t N>
	class BitSet
	{
	public:
		BitSet()
		{
			_bits.resize(N / 32 + 1, 0);
		}

		// 把x映射的位标记为1
		void Set(size_t x)
		{
			assert(x < N);
			// 算出x映射的位在第几个整数
			// 算出x映射的位在这个整数的第几个位
			size_t i = x / 32;
			size_t j = x % 32;

			// _bits[i]的第j位标记为1
			_bits[i] |= (1 << j);
		}

		// 把第x映射的位为搞成0，并且不影响它的其他位
		void ReSet(size_t x)
		{
			assert(x < N);
			size_t i = x / 32;
			size_t j = x % 32;

			// _bits[i]的第j位标记成0，并且不影响其他位
			_bits[i] &= (~(1 << j));
		}

		bool Test(size_t x)
		{
			assert(x < N);
			size_t i = x / 32;
			size_t j = x % 32;

			// 如果第j位是1，结果是非0，true
			// 如果第j位是0，结果是0，false
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
