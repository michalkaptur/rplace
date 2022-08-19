#include <gtest/gtest.h>

unsigned fib(unsigned n){
	if (n==0) return 0;
	if (n==1) return 1;
	return fib(n-1)+fib(n-2);
}

TEST(fib, _){
	EXPECT_EQ(fib(0), 0);
	EXPECT_EQ(fib(1), 1);
	EXPECT_EQ(fib(2), 1);
	EXPECT_EQ(fib(3), 2);
	EXPECT_EQ(fib(4), 3);
	EXPECT_EQ(fib(5), 5);
	EXPECT_EQ(fib(6), 8);
}
