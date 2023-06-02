#include "pch.h"
#include "../Project3/similaritychecker.cpp"


TEST(SimilarityCheckerTest, CheckSame)
{
	SimilarityChecker s;
	string A = "ABC";
	string B = "ABC";
	s.checkLength(A, B);
	EXPECT_EQ(s.getResult(), 60);
}

TEST(SimilarityCheckerTest, CheckLengthSame)
{
	SimilarityChecker s;
	string A = "ABC";
	string B = "DEF";
	s.checkLength(A, B);
	EXPECT_EQ(s.getResult(), 60);
}

TEST(SimilarityCheckerTest, CheckLengthZeroPoint)
{
	SimilarityChecker s;
	string A = "A";
	string B = "BB";
	s.checkLength(A, B);
	EXPECT_EQ(s.getResult(), 0);
}

TEST(SimilarityCheckerTest, CheckLengthZeroPoint2)
{
	SimilarityChecker s;
	string A = "AA";
	string B = "BBBB";
	s.checkLength(A, B);
	EXPECT_EQ(s.getResult(), 0);
}

TEST(SimilarityCheckerTest, CheckLengthZeroPoint3)
{
	SimilarityChecker s;
	string A = "BBBB";
	string B = "AA";
	s.checkLength(A, B);
	EXPECT_EQ(s.getResult(), 0);
}