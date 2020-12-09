#pragma once

#include <gtest/gtest.h>
#include <vector>
#include <functional>
#include <iterator>
#include <ostream>

namespace UnitTests
{
	template <typename T>
	std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
		out << '[';
		if (!v.empty()) {
			std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
			out << "\b\b";
		}
		out << ']';
		return out;
	}

	struct SortingAlgorithmTest : testing::Test
	{
		std::function<void(int *, int)> sorting_alg;
		std::vector<int> input_array;
	};

	struct TestSortParam
	{
		const std::function<void(int *, int)> sorting_alg;
		const std::string name;
		const std::vector<int> test_array;
		const std::vector<int> expected_result;

		friend std::ostream& operator<<(std::ostream& os, const TestSortParam& obj)
		{
			return os << std::endl << "\t[" << std::endl
				<< "\t\ttest_array: " << obj.test_array << std::endl
				<< "\t\tsorting_alg: " << obj.name << std::endl
				<< "\t]" << std::endl;
		}
	};

	struct TestSortFunctions : SortingAlgorithmTest, testing::WithParamInterface<TestSortParam>
	{
		TestSortFunctions()
		{
			sorting_alg = GetParam().sorting_alg;
			input_array = GetParam().test_array;
		}
	};

	struct Suite_1 : public TestSortFunctions {};
	struct Suite_2 : public TestSortFunctions {};
	struct Suite_3 : public TestSortFunctions {};
	struct Suite_4 : public TestSortFunctions {};
	struct Suite_5 : public TestSortFunctions {};
	struct Suite_6 : public TestSortFunctions {};
}
