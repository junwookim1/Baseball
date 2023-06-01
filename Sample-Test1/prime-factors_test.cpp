#include "pch.h"
#include "../Project3/prime-factors.cpp"

class PrimeFactorTest : public testing::Test
{
public:
	PrimeFactor prime_factor;
	vector<int> expected = {};
};

TEST_F(PrimeFactorTest, Of1)
{
	EXPECT_EQ(expected, prime_factor.of(1));
}

TEST_F(PrimeFactorTest, Of2)
{
	expected = {2};
	EXPECT_EQ(expected, prime_factor.of(2));
}

TEST_F(PrimeFactorTest, Of3)
{
	expected = {3};
	EXPECT_EQ(expected, prime_factor.of(3));
}

TEST_F(PrimeFactorTest, Of4)
{
	expected = {2, 2};
	EXPECT_EQ(expected, prime_factor.of(4));
}
