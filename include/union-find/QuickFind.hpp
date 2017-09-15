#pragma once

#include <algorithm>
#include <numeric>

#include "union-find/UnionFind_base.hpp"

namespace algorithm::unionFind
{
class QuickFind : public UnionFind_base
{
public:
	explicit QuickFind(const size_type n);

	void connect(const size_type p, const size_type q) noexcept override;
	const bool isConnected(const size_type p, const size_type q) noexcept override;

	const size_type partitionCount() const noexcept;
};

QuickFind::QuickFind(const size_type n)
{
	data_.resize(n);
	std::iota(data_.begin(), data_.end(), 0);
}

void QuickFind::connect(const size_type p, const size_type q) noexcept
{
	auto ids = std::minmax(data_[p] , data_[q]);
	auto newId = ids.first;
	auto oldId = ids.second;
	if (oldId != newId )
	std::replace_if(data_.begin(), data_.end(), [oldId](size_type v){ return (v == oldId) ? true : false; }, newId);
}

const bool QuickFind::isConnected(const size_type p, const size_type q) noexcept
{
	return (data_[p] == data_[q]) ? true : false;
}

auto QuickFind::partitionCount() const noexcept -> const size_type
{
	auto temp = data_;
    std::sort(temp.begin(), temp.end());
    return std::distance(temp.begin(), (std::unique(temp.begin(), temp.end())));
}
}
