#include <cstdarg>
#include <cstdio>
#include <memory>
#include "Utils.h"

void print_array(int *input_array, int length)
{
	LOG("%s", "[");
	for (auto i = 0; i < length; ++i) {
		LOG("%d%s", input_array[i], (i == length - 1 ? "" : ", "));
	}
	LOG("%s", "]");
}

void logger::log(const char * format, ...) const
{
	va_list args1, args2;
	va_start(args1, format);
    	va_copy(args2, args1);

	const auto length = vsnprintf(nullptr, 0, format, args1) + 1;
	va_end(args1);

	auto message = std::make_unique<char[]>(length);
	vsnprintf(message.get(), length, format, args2);
	printf("%s", message.get());
	va_end(args2);
}
