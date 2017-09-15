#include <vector>

#include <gtest/gtest.h>

#include "array/array.hpp"

TEST(array_find_maximum_subArray, positive)
{
	std::vector<int> v1 {1, 2, 3, 4, 5};
	EXPECT_EQ(*std::get<0>(algorithm::array::find_maximum_subArray(v1.begin(), v1.end())), 1);
	EXPECT_EQ(*(std::get<1>(algorithm::array::find_maximum_subArray(v1.begin(), v1.end())) - 1), 5);
	EXPECT_EQ(std::get<2>(algorithm::array::find_maximum_subArray(v1.begin(), v1.end())), 15);
}

TEST(array_find_maximum_subArray, negetive)
{
	std::vector<int> v {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	EXPECT_EQ(*std::get<0>(algorithm::array::find_maximum_subArray(v.begin(), v.end())), 18);
	EXPECT_EQ(*(std::get<1>(algorithm::array::find_maximum_subArray(v.begin(), v.end())) - 1), 12);
	EXPECT_EQ(std::get<2>(algorithm::array::find_maximum_subArray(v.begin(), v.end())), 43);
}

TEST(array_find_minimum_subArray, positive)
{
	std::vector<int> v1 {1, 2, 3, 4, 5};
	EXPECT_EQ(*std::get<0>(algorithm::array::find_minimum_subArray(v1.begin(), v1.end())), 1);
	EXPECT_EQ(*(std::get<1>(algorithm::array::find_minimum_subArray(v1.begin(), v1.end())) - 1), 1);
	EXPECT_EQ(std::get<2>(algorithm::array::find_minimum_subArray(v1.begin(), v1.end())), 1);
}

TEST(array_find_minimum_subArray, negetive)
{
	std::vector<int> v {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	EXPECT_EQ(*std::get<0>(algorithm::array::find_minimum_subArray(v.begin(), v.end())), -3);
	EXPECT_EQ(*(std::get<1>(algorithm::array::find_minimum_subArray(v.begin(), v.end())) - 1), -23);
	EXPECT_EQ(std::get<2>(algorithm::array::find_minimum_subArray(v.begin(), v.end())), -50);
}
