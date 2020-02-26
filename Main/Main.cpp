#include <iostream>
#include <iomanip>
#include <array>
#include <functional>
#include <chrono>
#include "Utils.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

#define SHOW_SORT


int main()
{
	auto test_array = create_random_data<12>(0, 100);
	//std::array<int, 12> test_array = { 85, 52, 17, 25, 47, 99, 34, 85, 31, 57, 84, 74 };
	auto lambda = [test_array](const std::function<void(int *, int)> &sorting_alg) mutable {
		auto n = static_cast<int>(test_array.size());
#ifdef SHOW_SORT
		std::cout << "Initial => ";
		print_array(test_array.data(), n);
#endif
		const auto t1 = std::chrono::high_resolution_clock::now();

		sorting_alg(test_array.data(), n);

		const auto t2 = std::chrono::high_resolution_clock::now();
		const auto time_difference = t2 - t1;

#ifdef SHOW_SORT
		std::cout << "Result => ";
		print_array(test_array.data(), n);
#endif

		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(time_difference % std::chrono::seconds(1));
		auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time_difference % std::chrono::milliseconds(1));

		std::cout << "Time : " << std::setfill('0')
			<< std::setw(2) << msec.count() << "."
			<< std::setw(2) << ns.count() << " ms" << std::endl;
		std::cout << std::endl;
	};

	auto do_bubble_sort = std::bind(lambda, bubble_sort);
	auto do_selection_sort = std::bind(lambda, selection_sort);
	auto do_insertion_sort = std::bind(lambda, insertion_sort);
	auto do_merge_sort = std::bind(lambda, merge_sort);
	auto do_quick_sort = std::bind(lambda, quick_sort);

	std::cout << "Bubble Sort :" << std::endl;
	do_bubble_sort();
	std::cout << "Selection Sort :" << std::endl;
	do_selection_sort();
	std::cout << "Insertion Sort :" << std::endl;
	do_insertion_sort();
	std::cout << "Merge Sort :" << std::endl;
	do_merge_sort();
	std::cout << "Quick Sort :" << std::endl;
	do_quick_sort();

	system("pause");
	return 0;
}
