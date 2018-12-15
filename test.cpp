#include "ip_filter.cpp"
#include "gtest/gtest.h"

TEST(TestSplit, SplitIsEmpty) {
	std::vector<std::string> Res = { " " };
	std::vector<std::string> testSplit = split(" ", '.');
	ASSERT_EQ(testSplit.size(), 1);
	ASSERT_EQ(testSplit, Res);
}

TEST(TestSplit, SplitByPoint) {
	std::vector<std::string> res{ "23","45","123","198" };
	std::vector<std::string> testSplit = split("23.45.123.198", '.');
	ASSERT_EQ(testSplit.size(), 4);
	ASSERT_EQ(testSplit, res);
}

TEST(TestSplit, SplitByTab) {
	std::vector<std::string> Res = { "23.45.123.198",  "1", "23" };
	std::vector<std::string> testSplit = split("23.45.123.198	1	23", '\t');
	ASSERT_EQ(testSplit.size(), 3);
	ASSERT_EQ(testSplit, Res);
}

TEST(TestLexSort, reverseSorting) {
	IpList result
	{			
		{123,123,123,1},
		{1,123,23,67},
		{1,123,23,2},
		{1,2,3,4},
		{0,123,32,51}
	};
	IpList input
	{	{1,2,3,4},
		{1,123,23,67},
		{0,123,32,51},
		{123,123,123,1},
		{1,123,23,2} 
	};
	lexSortRev(input);
	ASSERT_EQ(input, result);
}

TEST(TestFilter, First) {
	IpList model
	{
		{5,89,212,67},
		{5,5,23,2},
		{5,2,3,4},
	};
	IpList input
	{
		{12,32,2,67},
		{5,89,212,67},
		{5,5,23,2},
		{5,2,3,4},
		{0,0,0,0}
	};
	IpList res = filterFirst(input, 5);
	ASSERT_EQ(res, model);

}

TEST(TestFilter, Second) {
	IpList model
	{
		{1,46,0,0},
		{1,46,3,4}
	};
	IpList input
	{
		{1,213,2,67},
		{1,123,212,67},
		{1,46,0,0},
		{1,46,3,4},
		{0,0,0,0}
	};
	IpList res = filterFirstAndSecond(input, 1, 46);
	ASSERT_EQ(res, model);
}

TEST(TestFilter, Any) {
	IpList model
	{
		{12,32,2,1},
		{0,1,23,2},
		{5,2,1,4},
		{1,0,1,0}
	};
	IpList input
	{
		{12,32,2,1},
		{0,1,23,2},
		{5,2,1,4},
		{1,0,1,0},
		{-1,89,212,67}
	};
	IpList res = filterAnyOf(input, 1);
	ASSERT_EQ(res, model);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
