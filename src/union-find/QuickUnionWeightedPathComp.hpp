#pragma once

#include "union-find/QuickUnion.hpp"

namespace algorithm::unionFind
{
class QuickUnionWeightedPathComp : public QuickUnion
{
public:
	explicit QuickUnionWeightedPathComp(const size_type n);

	void connect(const size_type p, const size_type q) noexcept override;

protected:
	const size_type root(const size_type n) noexcept override;

private:
	std::vector<size_type> size_{};
};

QuickUnionWeightedPathComp::QuickUnionWeightedPathComp(const size_type n) : QuickUnion(n)
{
	size_.resize(n, 1);
}

void QuickUnionWeightedPathComp::connect(const size_type p, const size_type q) noexcept
{
	auto root_p = root(p);
	auto root_q = root(q);
	if (size_[root_p] < size_[root_q])
	{
		data_[root_p] = data_[root_q];
		size_[root_q] += size_[root_p];
	}
	else
	{
		data_[root_q] = data_[root_p];
		size_[root_p] += size_[root_q];
	}
}

auto QuickUnionWeightedPathComp::root(const size_type n) noexcept -> const size_type
{
	auto temp = n;
	while (data_[temp] != temp)
	{
		data_[temp] = data_[data_[temp]];
		temp = data_[temp];
	}
	return temp;
}
}
