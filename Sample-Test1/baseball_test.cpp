#include "pch.h"
#include "../Project3/baseball.cpp"


TEST(BaseballTest, BaseballException)
{
	Baseball baseball("123");

	EXPECT_THROW(baseball.guess(""), std::invalid_argument);
	EXPECT_THROW(baseball.guess("1543"), std::invalid_argument);
	EXPECT_THROW(baseball.guess("1v3"), std::invalid_argument);
	EXPECT_THROW(baseball.guess("121"), std::invalid_argument);
}

TEST(BaseballTest, PerfectMatch)
{
	Baseball baseball("123");
	Result result = baseball.guess("123");
	EXPECT_EQ(result.solved, true);
	EXPECT_EQ(result.strikes, 3);
	EXPECT_EQ(result.balls, 0);
}

TEST(BaseballTest, MissMatch)
{
	Baseball baseball("123");
	Result result = baseball.guess("789");
	EXPECT_EQ(result.solved, false);
	EXPECT_EQ(result.strikes, 0);
	EXPECT_EQ(result.balls, 0);
}