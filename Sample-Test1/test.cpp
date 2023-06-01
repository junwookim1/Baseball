#include "pch.h"
#include "../Project3/account.cpp"

TEST(TestCaseName, TestName) {
	Account account(10000);
	EXPECT_EQ(10000, account.getBalance());
}