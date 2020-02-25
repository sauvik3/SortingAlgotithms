#include "SelectionSort.h"
#include "Utils.h"

int min_ind(int *input_array, int length) {
	auto ind = 0;
	for (auto i = 1; i < length; ++i) {
		if (input_array[i] < input_array[ind]) {
			ind = i;
		}
	}
	return ind;
}

void selection_sort(int *input_array, int length) {
	for (auto i = 0; i < length - 1; ++i) {
		const auto ind = min_ind(input_array + i, length - i);
		std::swap(input_array[i + ind], input_array[i]);
#ifdef ENABLE_LOGGING
		LOG("Pass %d -> ", i);
		print_array(input_array, length);
#endif
	}
}