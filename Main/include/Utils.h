#pragma once
#include "Sorting.h"
#include <random>
#include <algorithm>
#include <functional>

extern "C" SORTING_API void print_array(int *input_array, int length);

template <int n>
std::array<int, n> create_random_data(const int range_from = 0, const int range_to = 100) {
	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_int_distribution<int> distr(range_from, range_to);
	std::array<int, n> data_gen;

	std::generate(data_gen.begin(), data_gen.end(), std::bind(distr, generator));
	return  data_gen;
}

class SORTING_API logger
{
public:
	static logger& instance()
	{
		static logger entity;
		return entity;
	}

	void log(const char * format, ...) const;

	logger(logger &) = delete;
	logger(logger &&) = delete;
	logger &operator=(const logger &) = delete;
	logger &operator=(logger &&) = delete;

private:
	logger() {}
	~logger() {}
};

#define LOG(format, ...) logger::instance().log(format, ## __VA_ARGS__)