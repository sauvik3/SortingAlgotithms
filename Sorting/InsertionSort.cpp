#include "InsertionSort.h"
#include "Utils.h"

void insert_at_ind(int *input_array, int length, int ele) {
	auto ind = length;
	for (auto i = 0; i < length; ++i) {
		if (input_array[i] > ele) {
			ind = i;
			break;
		}
	}
	for (auto i = length; i > ind; --i) {
		input_array[i] = input_array[i - 1];
	}
	input_array[ind] = ele;
}

void insertion_sort(int *input_array, int length) {
	for (auto i = 1; i < length; ++i) {
		insert_at_ind(input_array, i, input_array[i]);
#ifdef ENABLE_LOGGING
		LOG("Pass %d -> ", i-1);
		print_array(input_array, length);
#endif
	}
}
