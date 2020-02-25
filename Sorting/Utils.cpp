#include <iostream>
#include "Utils.h"

void print(int *input_array, int length) {
	for (auto i = 0; i < length; ++i) {
		std::cout << input_array[i] << (i == length - 1 ? "" : ", ");
	}
	std::cout << std::endl;
}