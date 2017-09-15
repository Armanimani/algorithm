#pragma once

#include <functional>
#include <iterator>
#include <memory>

namespace algorithm::sort::impl
{
template <typename RandomAcessIterator, typename Comparator = std::less<typename std::iterator_traits<RandomAcessIterator>::value_type>>
void merge_sort_merge_(RandomAcessIterator beg, RandomAcessIterator mid, RandomAcessIterator end, Comparator comp = Comparator())
{
	using Value_t = std::decay_t<decltype(*beg)>;
	std::unique_ptr<Value_t[]> buffer(new Value_t[std::distance(beg, end)]);

	auto keyL = beg;
	auto keyR = mid + 1;
	std::size_t key = 0;

	while (key != std::distance(beg, end))
	{
		if (keyL != mid + 1 && keyR != end)
		{
			if (comp(*keyL, *keyR))
			{
				buffer[key] = *keyL;
				std::advance(keyL, 1);
			}
			else
			{
				buffer[key] = *keyR;
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
}
}

namespace algorithm::sort
{
template <typename RandomAcessIterator, typename Comparator = std::less<typename std::iterator_traits<RandomAcessIterator>::value_type>>
void insertation_sort(RandomAcessIterator beg, RandomAcessIterator end, Comparator comp = Comparator())
{
	if (std::distance(beg, end) < 2) return;

	for (auto i = beg + 1; i != end; std::advance(i, 1))
	{
		auto key = *i;
		auto j = i;
		while (j > beg && comp(key, *(j - 1)))
		{
			*j = *(j - 1);
			std::advance(j, -1);
		}
		*j = key;
	}
}

template <typename RandomAcessIterator, typename Comparator = std::less<typename std::iterator_traits<RandomAcessIterator>::value_type>>
void merge_sort(RandomAcessIterator beg, RandomAcessIterator end, Comparator comp = Comparator())
{
	if (std::distance(beg, end) < 2) return;

	auto mid = beg + std::distance(beg, end) / 2 - 1;
	merge_sort(beg, mid + 1, comp);
	merge_sort(mid + 1, end, comp);
	impl::merge_sort_merge_(std::forward<RandomAcessIterator>(beg), std::forward<RandomAcessIterator>(mid), std::forward<RandomAcessIterator>(end), comp);
}

template <typename RandomAcessIterator, typename Comparator = std::less<typename std::iterator_traits<RandomAcessIterator>::value_type>, typename Threshold = std::size_t>
void merge_sort_with_insertation(RandomAcessIterator beg, RandomAcessIterator end, Threshold threshold = 10, Comparator comp = Comparator())
{
	if (std::distance(beg, end) < 2) return;

	auto mid = beg + std::distance(beg, end) / 2 - 1;

	if (std::distance(beg, mid + 1) < threshold)
	{
		insertation_sort(beg, mid + 1, comp);
	}
	else
	{
		merge_sort(beg, mid + 1, comp);
	}

	if (std::distance(mid + 1, end) < threshold)
	{
		insertation_sort(mid + 1, end, comp);
	}
	else
	{
		merge_sort(mid + 1, end, comp);
	}
	impl::merge_sort_merge_(std::forward<RandomAcessIterator>(beg), std::forward<RandomAcessIterator>(mid), std::forward<RandomAcessIterator>(end), comp);
}

template <typename RandomAcessIterator, typename Comparator = std::less<typename std::iterator_traits<RandomAcessIterator>::value_type>>
void bubble_sort(RandomAcessIterator beg, RandomAcessIterator end, Comparator comp = Comparator())
{
	if (std::distance(beg, end) < 2) return;

	for (auto i = beg; i != end; ++i)
	{
		for (auto j = end - 1; j != i; --j)
		{
			if (comp((*j), *(j - 1)))
				std::swap(*j, *(j - 1));
		}
	}
}
}
