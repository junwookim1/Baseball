#include "pch.h"
#include "../Project3/prime-factors.cpp"

TEST(PrimeFactorTest, Of1)
{
	PrimeFactor prime_factor;
	vector<int> expected = {};
	EXPECT_EQ(expected, prime_factor.of(1));
}

TEST(PrimeFactorTest, Of2)
{
	PrimeFactor prime_factor;
	vector<int> expected = {2};
	EXPECT_EQ(expected, prime_factor.of(2));
}