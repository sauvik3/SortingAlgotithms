#include <benchmark/benchmark.h>
#include <algorithm>
#include <functional>
#include <array>
#include <vector>
#include <random>
#include <cctype>
#include <limits>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"

namespace BenchmarkTestData
{
	template <int n>
	const std::array<int, n> create_random_data(const int range_from = 0, const int range_to = 100) {
		std::random_device rand_dev;
		std::mt19937 generator(rand_dev());
		std::uniform_int_distribution<int> distr(range_from, range_to);
		std::array<int, n> data_gen;

		std::generate(data_gen.begin(), data_gen.end(), std::bind(distr, generator));
		return  data_gen;
	}

	const auto bigArray = create_random_data<2048>(std::numeric_limits<int>::min(),
		std::numeric_limits<int>::max());
	const std::vector<int> SortBigArray()
	{
		std::vector<int> bigArraySorted(bigArray.begin(), bigArray.end());
		std::sort(bigArraySorted.begin(), bigArraySorted.end());
		return bigArraySorted;
	}


	const int constexpr min = std::numeric_limits<int>::min();
	const int constexpr max = std::numeric_limits<int>::max();
	const std::vector<int> bigArrayUnSorted(bigArray.begin(), bigArray.end());
	const std::vector<int> bigArraySorted = SortBigArray();
}

static void BM_Random_BubbleSort(benchmark::State& state)
{
	const auto data = BenchmarkTestData::bigArrayUnSorted;
	while (state.KeepRunning())
	{
		auto input_array = data;
		bubble_sort(input_array.data(), static_cast<int>(input_array.size()));
	}
}
BENCHMARK(BM_Random_BubbleSort);

static void BM_Random_InsertionSort(benchmark::State& state)
{
	const auto data = BenchmarkTestData::bigArrayUnSorted;
	while (state.KeepRunning())
	{
		auto input_array = data;
		insertion_sort(input_array.data(), static_cast<int>(input_array.size()));
	}
}
BENCHMARK(BM_Random_InsertionSort);

static void BM_Random_MergeSort(benchmark::State& state)
{
	const auto data = BenchmarkTestData::bigArrayUnSorted;
	while (state.KeepRunning())
	{
		auto input_array = data;
		merge_sort(input_array.data(), static_cast<int>(input_array.size()));
	}
}
BENCHMARK(BM_Random_MergeSort);

static void BM_Random_QuickSort(benchmark::State& state)
{
	const auto data = BenchmarkTestData::bigArrayUnSorted;
	while (state.KeepRunning())
	{
		auto input_array = data;
		quick_sort(input_array.data(), static_cast<int>(input_array.size()));
	}
}
BENCHMARK(BM_Random_QuickSort);

static void BM_Random_SelectionSort(benchmark::State& state)
{
	const auto data = BenchmarkTestData::bigArrayUnSorted;
	while (state.KeepRunning())
	{
		auto input_array = data;
		selection_sort(input_array.data(), static_cast<int>(input_array.size()));
	}
}
BENCHMARK(BM_Random_SelectionSort);

BENCHMARK_MAIN();
