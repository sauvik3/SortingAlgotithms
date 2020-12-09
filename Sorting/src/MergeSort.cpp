#include <memory>
#include <cstring>
#include "MergeSort.h"
#include "Utils.h"

void merge(int *input_array, int length) {
	const auto mid = length / 2;
	if (mid > 0) {
		auto ar1 = input_array;
		auto ar2 = input_array + mid;
		auto buffer = std::make_unique<int[]>(length);
		auto i = 0;

		for (; ar1 < input_array + mid && ar2 < input_array + length;) {
			buffer[i++] = (*ar1 > *ar2 ? *ar2++ : *ar1++);
		}
		while (ar1 < input_array + mid) {
			buffer[i++] = *ar1++;
		}
		while (ar2 < input_array + length) {
			buffer[i++] = *ar2++;
		}
		std::memcpy(input_array, buffer.get(), length * sizeof(int));
	}
}

void merge_sort_recursive(int *input_array, int length, int &counter) {
	const auto mid = length / 2;
	if (mid > 0) {
		merge_sort_recursive(input_array, mid, counter);
		merge_sort_recursive(input_array + mid, length - mid, counter);
		merge(input_array, length);
#ifdef ENABLE_LOGGING
		LOG("Pass %d -> ", counter++);
		print_array(input_array, length);
#endif
	}
}

void merge_sort(int *input_array, int length) {
	auto i = 0;
	merge_sort_recursive(input_array, length, i);
}
