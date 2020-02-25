#include <iostream>
#include <array>
#include <functional>
#include "Utils.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"

int main()
{
	auto test_array = create_random_data<8>(0, 50);
	//std::array<int, 8> test_array = { 1, 5, 4, 0, 7, 2, 9, 3 };
	auto lambda = [test_array](const std::function<void(int *, int)> &sorting_alg) mutable {
		auto n = static_cast<int>(test_array.size());
		std::cout << "Initial => ";
		print_array(test_array.data(), n);
		sorting_alg(test_array.data(), n);
		std::cout << "Result => ";
		print_array(test_array.data(), n);
		std::cout << std::endl;
	};

	auto do_bubble_sort = std::bind(lambda, bubble_sort);
	auto do_selection_sort = std::bind(lambda, selection_sort);
	auto do_insertion_sort = std::bind(lambda, insertion_sort);
	auto do_merge_sort = std::bind(lambda, merge_sort);

	std::cout << "Bubble Sort :" << std::endl;
	do_bubble_sort();
	std::cout << "Selection Sort :" << std::endl;
	do_selection_sort();
	std::cout << "Insertion Sort :" << std::endl;
	do_insertion_sort();
	std::cout << "Merge Sort :" << std::endl;
	do_merge_sort();

	system("pause");
	return 0;
}
