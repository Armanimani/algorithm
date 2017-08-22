#pragma once

#include <algorithm>
#include <numeric>

#include "union-find/Interface.hpp"

namespace algorithm::unionFind
{
class QuickUnion : public Interface
{
public:
	explicit QuickUnion(const size_type n);

	void connect(const size_type p, const size_type q) noexcept override;
	const bool isConnected(const size_type p, const size_type q) noexcept override;

protected:
	virtual const size_type root(const size_type n) noexcept;
};

QuickUnion::QuickUnion(const size_type n)
{
	data_.resize(n);
	std::iota(data_.begin(), data_.end(), 0);
}

void QuickUnion::connect(const size_type p, const size_type q) noexcept
{
	auto root_p = root(p);
	auto root_q = root(q);
	data_[root_p] = data_[root_q];
}

const bool QuickUnion::isConnected(const size_type p, const size_type q) noexcept
{
	return (root(p) == root(q)) ? true : false;
}

auto QuickUnion::root(const size_type n) noexcept -> const size_type
{
	auto temp = n;
	while (data_[temp] != temp)
	{
		temp = data_[temp];
	}
	return temp;
}
}
