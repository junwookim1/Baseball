#include "pch.h"
#include "../Project3/similaritychecker.cpp"

TEST(SimilarityCheckerTest, CheckEmpty)
{
	SimilarityChecker s;
	string A = "";
	string B = "";
	s.checkLength(A, B);
	EXPECT_EQ(s.getResult(), 0);
}

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

TEST(SimilarityCheckerTest, CheckLengthDifferent)
{
	SimilarityChecker s;
	string A = "AAABB";
	string B = "BAA";
	s.checkLength(A, B);
	EXPECT_EQ(s.getResult(), 20);
}

TEST(SimilarityCheckerTest, CheckLengthDifferent2)
{
	SimilarityChecker s;
	string A = "AA";
	string B = "AAA";
	s.checkLength(A, B);
	EXPECT_EQ(s.getResult(), 30);
}

TEST(SimilarityCheckerTest, CheckLengthDifferentLong)
{
	SimilarityChecker s;
	string A = "AAAAA";
	string B = "AAAAAAAAA";
	s.checkLength(A, B);
	EXPECT_EQ(s.getResult(), 12);
}