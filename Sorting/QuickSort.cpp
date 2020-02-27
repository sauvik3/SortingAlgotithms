#include "QuickSort.h"
#include "Utils.h"

int get_partition_ind(int input_array[], int left, int right)
{
	auto &pivot = input_array[right];
	auto next_ind = left;

	for (auto i = left; i < right; ++i) {
		if (input_array[i] < pivot) {
			std::swap(input_array[next_ind++], input_array[i]);
		}
	}
	std::swap(input_array[next_ind], pivot);
	return next_ind;
}

void quick_sort_recursive(int * input_array, int left, int right, int &counter)
{
	if (left < right) {
		const auto pivot = get_partition_ind(input_array, left, right);
		quick_sort_recursive(input_array, left, pivot - 1, counter);
		quick_sort_recursive(input_array, pivot + 1, right, counter);
#ifdef ENABLE_LOGGING
		LOG("Pass %d -> ", counter++);
		print_array(input_array, right - left + 1);
#endif
	}
}

void quick_sort(int * input_array, int length)
{
	auto i = 0;
	quick_sort_recursive(input_array, 0, length - 1, i);
}
