#pragma once

#include "union-find/QuickUnion.hpp"

namespace algorithm::unionFind
{
class QuickUnion_pathComp : public QuickUnion
{
public:
	explicit QuickUnion_pathComp(const size_type n);

protected:
	std::vector<size_type> size_{};

	const size_type root(const size_type n) noexcept override;
};

QuickUnion_pathComp::QuickUnion_pathComp(const size_type n) : QuickUnion(n)
{
	size_.resize(n, 1);
}

auto QuickUnion_pathComp::root(const size_type n) noexcept -> const size_type
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
