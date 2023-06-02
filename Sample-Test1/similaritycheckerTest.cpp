#include "pch.h"
#include "../Project3/similaritychecker.cpp"


TEST(SimilarityCheckerTest, CheckLengthSame)
{
	SimilarityChecker s;
	string A = "ABC";
	string B = "ABC";
	s.checkLength(A, B);
	EXPECT_EQ(s.getResult(), 60);
}
