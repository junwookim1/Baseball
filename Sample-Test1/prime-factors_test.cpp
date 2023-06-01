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
	PrimeFactor prime_factor;
	vector<int> expected = {2};
	EXPECT_EQ(expected, prime_factor.of(2));
}
