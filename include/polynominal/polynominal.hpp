#pragma once

#include <iterator>

namespace algorithm::polynominal
{
template <typename BackwardIterator, typename T>
const auto evaluate_HornerMethod(BackwardIterator beg, BackwardIterator end, T value)
{
	decltype(*beg + value) ret{};

	for (auto i = end; i != beg - 1; --i)
	{
		ret = *i + value * ret;
	}
	return ret;
}
}
