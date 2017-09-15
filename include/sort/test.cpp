#include "sort.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <algorithm>

int main()
{
	// std::vector<int> v {10, 2, 5, 3 , 2, 9, 4};
	// std::vector<int> v{10, 2, 5, 3};

	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<int> dist(0, std::numeric_limits<int>::max());

	std::size_t size = 100000;
	std::vector<int> v(size);
	for (int i = 0; i != size; ++i)
	{
		v[i] = dist(eng);
	}

	auto temp = v;
	std::sort(temp.begin(), temp.end());

	// for (auto& i : v)
	// {
	// 	std::cout << i << " ";
	// }
	// std::cout << std::endl;

	algorithm::sort::merge_sort(v.begin(), v.end());

	// for (auto& i : v)
	// {
	// 	std::cout << i << " ";
	// }
	// std::cout << std::endl;

	std::cout << std::boolalpha << (v == temp) << std::endl;
}
