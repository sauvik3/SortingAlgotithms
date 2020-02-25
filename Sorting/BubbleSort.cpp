#include "BubbleSort.h"
#include "Utils.h"

void bubble_sort(int *input_array, int length) {
	for (auto i = 0; i < length - 1; ++i) {
		for (auto j = 0; j < length - i - 1; ++j) {
			if (input_array[j] > input_array[j + 1]) {
				std::swap(input_array[j], input_array[j + 1]);
			}
		}
#ifdef ENABLE_LOGGING
		LOG("Pass %d -> ", i);
		print_array(input_array, length);
#endif
	}
}
