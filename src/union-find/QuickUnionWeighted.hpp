#pragma once

#include "union-find/QuickUnion.hpp"

namespace algorithm::unionFind
{
class QuickUnionWeighted : public QuickUnion
{
public:
	explicit QuickUnionWeighted(const size_type n);

	void connect(const size_type p, const size_type q) noexcept override;

protected:
	std::vector<size_type> size_{};
};

QuickUnionWeighted::QuickUnionWeighted(const size_type n) : QuickUnion(n)
{
	size_.resize(n, 1);
}

void QuickUnionWeighted::connect(const size_type p, const size_type q) noexcept
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
}
