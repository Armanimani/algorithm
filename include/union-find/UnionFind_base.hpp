#pragma once

#include <type_traits>
#include <vector>

namespace algorithm::unionFind
{
class UnionFind_base
{
public:
	using size_type = std::size_t;

	virtual void connect(const size_type p, const size_type q) = 0;
	virtual const bool isConnected(const size_type p, const size_type q) noexcept = 0;

	void addNode(const size_type n = 1);

	const size_type size() const noexcept;

protected:
	std::vector<size_type> data_{};
};

void UnionFind_base::addNode(const size_type n)
{
	auto size = data_.size();
	for (std::remove_const_t<decltype(n)> i = 0; i != n; ++i)
	{
		data_.push_back(size + i);
	}
}

auto UnionFind_base::size() const noexcept -> const size_type
{
	return data_.size();
}
}
