#pragma once

#include <iterator>
#include <memory>
#include <vector>
#include <array>
#include <limits>
#include <tuple>

namespace algorithm::array::impl
{
template <typename RandomAcessIterator>
std::size_t get_inversions_merge_(RandomAcessIterator beg, RandomAcessIterator mid, RandomAcessIterator end)
{
	std::size_t ret{0};

	using Value_t = std::decay_t<decltype(*beg)>;
	std::unique_ptr<Value_t[]> buffer(new Value_t[std::distance(beg, end)]);

	auto keyL = beg;
	auto keyR = mid + 1;
	std::size_t key = 0;

	while (key != std::distance(beg, end))
	{
		if (keyL != mid + 1 && keyR != end)
		{
			if (*keyL < *keyR)
			{
				buffer[key] = *keyL;
				std::advance(keyL, 1);
			}
			else
			{
				buffer[key] = *keyR;
				if (*keyR != *keyL)
					ret += std::distance(keyL, mid + 1);
				std::advance(keyR, 1);
			}
		}
		else if (keyL != mid + 1)
		{
			buffer[key] = *keyL;
			std::advance(keyL, 1);
		}
		else if (keyR != end)
		{
			buffer[key] = *keyR;
			std::advance(keyR, 1);
		}
		++key;
	}
	for (std::size_t i = 0, sz = std::distance(beg, end); i != sz; ++i)
	{
		*beg = buffer[i];
		std::advance(beg, 1);
	}
	return ret;
}

template <typename RandomAcessIterator>
std::size_t get_inversions_(RandomAcessIterator beg, RandomAcessIterator end)
{
	if (std::distance(beg, end) < 2) return 0;

	auto mid = beg + std::distance(beg, end) / 2 - 1;
	auto inv1 = get_inversions_(beg, mid + 1);
	auto inv2 = get_inversions_(mid + 1, end);
	return impl::get_inversions_merge_(std::forward<RandomAcessIterator>(beg), std::forward<RandomAcessIterator>(mid), std::forward<RandomAcessIterator>(end)) + inv1 + inv2;
}

template <typename RandomAcessIterator>
const auto find_max_crossing_subArray_(RandomAcessIterator beg, RandomAcessIterator mid, RandomAcessIterator end)
{
	using Value_t = std::decay_t<decltype(*beg)>;

	RandomAcessIterator left;
	Value_t sumLeft {std::numeric_limits<Value_t>::min()};
	Value_t sum {};
	for (auto i = mid; i >= beg; --i)
	{
		sum += *i;
		if (sum > sumLeft)
		{
			sumLeft = sum;
			left = i;
		}
		if (i == beg)
			break;
	}

	RandomAcessIterator right;
	Value_t sumRight {std::numeric_limits<Value_t>::min()};
	sum = 0;
	for (auto i = mid + 1; i != end; ++i)
	{
		sum += *i;
		if (sum > sumRight)
		{
			sumRight = sum;
			right = i + 1;
		}
	}
	return std::make_tuple(left, right, sumLeft + sumRight);
}

template <typename RandomAcessIterator>
const auto find_min_crossing_subArray_(RandomAcessIterator beg, RandomAcessIterator mid, RandomAcessIterator end)
{
	using Value_t = std::decay_t<decltype(*beg)>;

	RandomAcessIterator left;
	Value_t sumLeft {std::numeric_limits<Value_t>::max()};
	Value_t sum {};
	for (auto i = mid; i >= beg; --i)
	{
		sum += *i;
		if (sum < sumLeft)
		{
			sumLeft = sum;
			left = i;
		}
		if (i == beg)
			break;
	}

	RandomAcessIterator right;
	Value_t sumRight {std::numeric_limits<Value_t>::max()};
	sum = 0;
	for (auto i = mid + 1; i != end; ++i)
	{
		sum += *i;
		if (sum < sumRight)
		{
			sumRight = sum;
			right = i + 1;
		}
	}
	return std::make_tuple(left, right, sumLeft + sumRight);
}
}

namespace algorithm::array
{
template <typename RandomAcessIterator>
std::size_t get_inversions(RandomAcessIterator beg, RandomAcessIterator end)
{
	using Value_t = std::decay_t<decltype(*beg)>;
	std::vector<Value_t> buffer(beg, end);

	return impl::get_inversions_(buffer.begin(), buffer.end());
}

template <typename RandomAcessIterator>
std::size_t get_inversions_modify(RandomAcessIterator beg, RandomAcessIterator end)
{
	return impl::get_inversions_(std::forward<RandomAcessIterator>(beg), std::forward<RandomAcessIterator>(end));
}

template <typename RandomAcessIterator>
const auto find_maximum_subArray(RandomAcessIterator beg, RandomAcessIterator end)
{
	if (std::distance(beg ,end) < 2)
	{
		return std::make_tuple(beg, end, *beg);
	}

	auto mid = beg + std::distance(beg, end) / 2 - 1;
	auto leftResult = find_maximum_subArray(beg, mid);
	auto rightResult = find_maximum_subArray(mid + 1, end);
	auto midResult = impl::find_max_crossing_subArray_(beg, mid, end);

	if (std::get<2>(leftResult) >= std::get<2>(rightResult) && std::get<2>(leftResult) >= std::get<2>(midResult))
		return leftResult;
	else if (std::get<2>(rightResult) >= std::get<2>(leftResult) && std::get<2>(rightResult) >= std::get<2>(midResult))
		return rightResult;
	return midResult;
}

template <typename RandomAcessIterator>
const auto find_minimum_subArray(RandomAcessIterator beg, RandomAcessIterator end)
{
	if (std::distance(beg ,end) < 2)
	{
		return std::make_tuple(beg, end, *beg);
	}

	auto mid = beg + std::distance(beg, end) / 2 - 1;
	auto leftResult = find_minimum_subArray(beg, mid);
	auto rightResult = find_minimum_subArray(mid + 1, end);
	auto midResult = impl::find_min_crossing_subArray_(beg, mid, end);

	if (std::get<2>(leftResult) <= std::get<2>(rightResult) && std::get<2>(leftResult) <= std::get<2>(midResult))
		return leftResult;
	else if (std::get<2>(rightResult) <= std::get<2>(leftResult) && std::get<2>(rightResult) <= std::get<2>(midResult))
		return rightResult;
	return midResult;
}
}
