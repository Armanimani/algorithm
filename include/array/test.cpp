#include "array.hpp"
#include <vector>
#include <iostream>


int main()
{
	std::vector<int> v {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	// std::vector<int> v {1, 2, 3, 4, 5};
	// std::vector<int> v {1, 2};

	auto ret = algorithm::array::find_maximum_subArray(v.begin(), v.end());
	std::cout << *std::get<0>(ret) << " " << *std::get<1>(ret) << " " << std::get<2>(ret) << std::endl;
	std::cout << std::endl;
}
