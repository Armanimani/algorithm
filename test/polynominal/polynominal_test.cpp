#include <vector>

#include <gtest/gtest.h>

#include "polynominal/polynominal.hpp"

std::vector<int> v {2, -5, 3};
std::vector<double> v1 {1, 2.1};
TEST(polynominal_evaluate_HornerMethod, value)
{
	EXPECT_EQ(algorithm::polynominal::evaluate_HornerMethod(v.begin(), v.end(), -2), 24);
	EXPECT_EQ(algorithm::polynominal::evaluate_HornerMethod(v.begin(), v.end(), +2), 4);
	EXPECT_EQ(algorithm::polynominal::evaluate_HornerMethod(v1.begin(), v1.end(), 2), 5.2);
}
