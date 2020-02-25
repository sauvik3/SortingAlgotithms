#include "stdafx.h"
#include "CppUnitTest.h"
#include <array>
#include <iterator>
#include <iostream>
#include <functional>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(TestSortFunctions)
	{
	public:

		TEST_METHOD(TestBubbleSort)
		{
			test_func(bubble_sort, test_array_);
		}

		TEST_METHOD(TestSelectionSort)
		{
			test_func(selection_sort, test_array_);
		}

		TEST_METHOD(TestInsertionSort)
		{
			test_func(insertion_sort, test_array_);
		}

		TEST_METHOD(TestMergeSort)
		{
			test_func(merge_sort, test_array_);
		}

		TEST_METHOD(TestQuickSort)
		{
			test_func(quick_sort, test_array_);
		}

	private:
		void test_func(const std::function<void(int *, int)> &sorting_alg, std::array<int, 8> test_array) const
		{
			const auto n = static_cast<int>(test_array.size());
			sorting_alg(test_array.data(), n);

			if (test_array != expected_array_) {
				const auto res = std::mismatch(test_array.begin(), test_array.end(), expected_array_.begin());
				wchar_t message[200];
				if (res.first != test_array.end()) {
					std::stringstream ss;
					ss << "Arrays not matching at " << std::distance(test_array.begin(), res.first) <<
						", expected: " << *res.second << ", got: " << *res.first << std::endl;
					swprintf_s(message, L"%S", ss.str().c_str());
					Assert::Fail(message);
				}
			}
		}

		const std::array<int, 8> test_array_ = { 1, 5, 4, 0, 7, 2, 9, 3 };
		const std::array<int, 8> expected_array_ = { 0, 1, 2, 3, 4, 5, 7, 9 };
	};
}