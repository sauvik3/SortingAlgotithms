#include <cstdarg>
#include <cstdio>
#include <memory>
#include "Utils.h"

void print_array(int *input_array, int length) {
	for (auto i = 0; i < length; ++i) {
		LOG("%d%s", input_array[i], (i == length - 1 ? "" : ", "));
	}
}

void logger::log(const char * format, ...) const
{
	va_list args;
	va_start(args, format);

	const auto length = vsnprintf(nullptr, 0, format, args) + 1;
	auto message = std::make_unique<char[]>(length);
	vsnprintf(message.get(), length, format, args);
	printf("%s", message.get());
	va_end(args);
}
