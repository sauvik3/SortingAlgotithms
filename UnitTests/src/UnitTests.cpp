#include <gtest/gtest.h>
#include <algorithm>
#include <array>
#include <vector>
#include <random>
#include <cctype>
#include <limits>
#include "UnitTests.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"

namespace UnitTestData
{
	template <int n>
	const std::array<int, n> create_random_data(const int range_from = 0, const int range_to = 100) {
		std::random_device rand_dev;
		std::mt19937 generator(rand_dev());
		std::uniform_int_distribution<int> distr(range_from, range_to);
		std::array<int, n> data_gen;

		std::generate(data_gen.begin(), data_gen.end(), std::bind(distr, generator));
		return  data_gen;
	}

	const auto bigArray = create_random_data<256>(std::numeric_limits<int>::min(),
		std::numeric_limits<int>::max());
	const std::vector<int> SortBigArray()
	{
		std::vector<int> bigArraySorted(bigArray.begin(), bigArray.end());
		std::sort(bigArraySorted.begin(), bigArraySorted.end());
		return bigArraySorted;
	}


	const int constexpr min = std::numeric_limits<int>::min();
	const int constexpr max = std::numeric_limits<int>::max();
	const std::vector<int> bigArrayUnSorted(bigArray.begin(), bigArray.end());
	const std::vector<int> bigArraySorted = SortBigArray();
}

namespace UnitTests
{
	const auto filterFunctionName = [](const testing::TestParamInfo<TestSortParam>& info) {
		auto param = static_cast<TestSortParam>(info.param);
		std::string name = param.name;
		std::replace_if(name.begin(), name.end(),
			[](char c) { return !std::isalnum(c); }, '_');
		return name;
	};

	INSTANTIATE_TEST_SUITE_P(TestSortFunctions, Suite_1,
		::testing::ValuesIn(
			{
				TestSortParam{	bubble_sort,
								"Bubble_Sort",
								{ 1, 5, 4, 0, 7, 2, 9, 3 },
								{ 0, 1, 2, 3, 4, 5, 7, 9 }
							},
				TestSortParam{	insertion_sort,
								"Insertion_Sort",
								{ 1, 5, 4, 0, 7, 2, 9, 3 },
								{ 0, 1, 2, 3, 4, 5, 7, 9 }
							},
				TestSortParam{	merge_sort,
								"Merge_Sort",
								{ 1, 5, 4, 0, 7, 2, 9, 3 },
								{ 0, 1, 2, 3, 4, 5, 7, 9 }
							},
				TestSortParam{	quick_sort,
								"Quick_Sort",
								{ 1, 5, 4, 0, 7, 2, 9, 3 },
								{ 0, 1, 2, 3, 4, 5, 7, 9 }
							},
				TestSortParam{	selection_sort,
								"Selection_Sort",
								{ 1, 5, 4, 0, 7, 2, 9, 3 },
								{ 0, 1, 2, 3, 4, 5, 7, 9 }
							}
			}
		), filterFunctionName
	);

	TEST_P(Suite_1, TestUnsortedArray)
	{
		sorting_alg(input_array.data(), static_cast<int>(input_array.size()));
		EXPECT_EQ(input_array, GetParam().expected_result);
	}

	INSTANTIATE_TEST_SUITE_P(TestSortFunctions, Suite_2,
		::testing::ValuesIn(
			{
				TestSortParam{	bubble_sort,
							"Bubble_Sort",
							{},
							{}
						},
			TestSortParam{	insertion_sort,
							"Insertion_Sort",
							{},
							{}
						},
			TestSortParam{	merge_sort,
							"Merge_Sort",
							{},
							{}
						},
			TestSortParam{	quick_sort,
							"Quick_Sort",
							{},
							{}
						},
			TestSortParam{	selection_sort,
							"Selection_Sort",
							{},
							{}
						}
			}
		), filterFunctionName
	);

	TEST_P(Suite_2, TestEmptyArray)
	{
		sorting_alg(input_array.data(), static_cast<int>(input_array.size()));
		EXPECT_EQ(input_array, GetParam().expected_result);
	}

	INSTANTIATE_TEST_SUITE_P(TestSortFunctions, Suite_3,
		::testing::ValuesIn(
			{
				TestSortParam{	bubble_sort,
								"Bubble_Sort",
								{ 1, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 1, 1 }
							},
				TestSortParam{	insertion_sort,
								"Insertion_Sort",
								{ 1, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 1, 1 }
							},
				TestSortParam{	merge_sort,
								"Merge_Sort",
								{ 1, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 1, 1 }
							},
				TestSortParam{	quick_sort,
								"Quick_Sort",
								{ 1, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 1, 1 }
							},
				TestSortParam{	selection_sort,
								"Selection_Sort",
								{ 1, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 1, 1 }
							}
			}
		), filterFunctionName
	);

	TEST_P(Suite_3, TestAllElementsSameArray)
	{
		sorting_alg(input_array.data(), static_cast<int>(input_array.size()));
		EXPECT_EQ(input_array, GetParam().expected_result);
	}	

	INSTANTIATE_TEST_SUITE_P(TestSortFunctions, Suite_4,
		::testing::ValuesIn(
			{
				TestSortParam{	bubble_sort,
								"Bubble_Sort",
								{ 0, 1, 2, 3, 4, 5, 7, 9 },
								{ 0, 1, 2, 3, 4, 5, 7, 9 }
							},
				TestSortParam{	insertion_sort,
								"Insertion_Sort",
								{ 0, 1, 2, 3, 4, 5, 7, 9 },
								{ 0, 1, 2, 3, 4, 5, 7, 9 }
							},
				TestSortParam{	merge_sort,
								"Merge_Sort",
								{ 0, 1, 2, 3, 4, 5, 7, 9 },
								{ 0, 1, 2, 3, 4, 5, 7, 9 }
							},
				TestSortParam{	quick_sort,
								"Quick_Sort",
								{ 0, 1, 2, 3, 4, 5, 7, 9 },
								{ 0, 1, 2, 3, 4, 5, 7, 9 }
							},
				TestSortParam{	selection_sort,
								"Selection_Sort",
								{ 0, 1, 2, 3, 4, 5, 7, 9 },
								{ 0, 1, 2, 3, 4, 5, 7, 9 }
							}
			}
		), filterFunctionName
	);

	TEST_P(Suite_4, TestPreSortedArray)
	{
		sorting_alg(input_array.data(), static_cast<int>(input_array.size()));
		EXPECT_EQ(input_array, GetParam().expected_result);
	}

	INSTANTIATE_TEST_SUITE_P(TestSortFunctions, Suite_5,
		::testing::ValuesIn(
			{
				TestSortParam{	bubble_sort,
								"Bubble_Sort",
								{ 0, 1, UnitTestData::min, UnitTestData::min +20, UnitTestData::max, 5, 7, 9 },
								{ UnitTestData::min, UnitTestData::min + 20, 0, 1, 5, 7, 9, UnitTestData::max }
							},
				TestSortParam{	insertion_sort,
								"Insertion_Sort",
								{ 0, 1, UnitTestData::min, UnitTestData::min + 20, UnitTestData::max, 5, 7, 9 },
								{ UnitTestData::min, UnitTestData::min + 20, 0, 1, 5, 7, 9, UnitTestData::max }
							},
				TestSortParam{	merge_sort,
								"Merge_Sort",
								{ 0, 1, UnitTestData::min, UnitTestData::min + 20, UnitTestData::max, 5, 7, 9 },
								{ UnitTestData::min, UnitTestData::min + 20, 0, 1, 5, 7, 9, UnitTestData::max }
							},
				TestSortParam{	quick_sort,
								"Quick_Sort",
								{ 0, 1, UnitTestData::min, UnitTestData::min + 20, UnitTestData::max, 5, 7, 9 },
								{ UnitTestData::min, UnitTestData::min + 20, 0, 1, 5, 7, 9, UnitTestData::max }
							},
				TestSortParam{	selection_sort,
								"Selection_Sort",
								{ 0, 1, UnitTestData::min, UnitTestData::min + 20, UnitTestData::max, 5, 7, 9 },
								{ UnitTestData::min, UnitTestData::min + 20, 0, 1, 5, 7, 9, UnitTestData::max }
							}
			}
		), filterFunctionName
	);

	TEST_P(Suite_5, TestLimitInputArray)
	{
		sorting_alg(input_array.data(), static_cast<int>(input_array.size()));
		EXPECT_EQ(input_array, GetParam().expected_result);
	}

	INSTANTIATE_TEST_SUITE_P(TestSortFunctions, Suite_6,
		::testing::ValuesIn(
			{
				TestSortParam{	bubble_sort,
							"Bubble_Sort",
							UnitTestData::bigArrayUnSorted,
							UnitTestData::bigArraySorted
						},
			TestSortParam{	insertion_sort,
							"Insertion_Sort",
							UnitTestData::bigArrayUnSorted,
							UnitTestData::bigArraySorted
						},
			TestSortParam{	merge_sort,
							"Merge_Sort",
							UnitTestData::bigArrayUnSorted,
							UnitTestData::bigArraySorted
						},
			TestSortParam{	quick_sort,
							"Quick_Sort",
							UnitTestData::bigArrayUnSorted,
							UnitTestData::bigArraySorted
						},
			TestSortParam{	selection_sort,
							"Selection_Sort",
							UnitTestData::bigArrayUnSorted,
							UnitTestData::bigArraySorted
						}
			}
		), filterFunctionName
	);

	TEST_P(Suite_6, TestLargeArray)
	{
		sorting_alg(input_array.data(), static_cast<int>(input_array.size()));
		EXPECT_EQ(input_array, GetParam().expected_result);
	}
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}