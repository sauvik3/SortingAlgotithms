#include <benchmark/benchmark.h>
#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <functional>
#include "BenchmarkTests.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"

namespace BenchmarkTestData
{
	template <typename T>
	const std::vector<T> create_random_data(const std::size_t sz
		, const T range_from = std::numeric_limits<T>::min()
		, const T range_to = std::numeric_limits<T>::max())
	{
		std::random_device rand_dev;
		std::mt19937 generator(rand_dev());
		std::uniform_int_distribution<T> distr(range_from, range_to);
		std::vector<T> data_gen(sz);

		std::generate(data_gen.begin(), data_gen.end(), std::bind(distr, generator));
		return  data_gen;
	}
}

namespace BenchmarkTests
{
	static void BM_Random_BubbleSort(benchmark::State& state)
	{
		auto input_array = BenchmarkTestData::create_random_data<int>(state.range(0));
		while (state.KeepRunning())
		{
			bubble_sort(input_array.data(), static_cast<int>(input_array.size()));
		}
		state.SetComplexityN(state.range(0));
		state.SetLabel("Bubble_Sort");
	}
	BENCHMARK(BM_Random_BubbleSort)->RangeMultiplier(2)->Range(1 << 7, 1 << 14)->Unit(benchmark::kMillisecond)
		->Complexity([](benchmark::IterationCount n) { return static_cast<double>(n); });

	static void BM_Random_InsertionSort(benchmark::State& state)
	{
		auto input_array = BenchmarkTestData::create_random_data<int>(state.range(0));
		while (state.KeepRunning())
		{
			insertion_sort(input_array.data(), static_cast<int>(input_array.size()));
		}
		state.SetComplexityN(state.range(0));
		state.SetLabel("Insertion_Sort");
	}
	BENCHMARK(BM_Random_InsertionSort)->RangeMultiplier(2)->Range(1 << 7, 1 << 14)->Unit(benchmark::kMillisecond)
		->Complexity([](benchmark::IterationCount n) { return static_cast<double>(n); });

	static void BM_Random_MergeSort(benchmark::State& state)
	{
		auto input_array = BenchmarkTestData::create_random_data<int>(state.range(0));
		while (state.KeepRunning())
		{
			merge_sort(input_array.data(), static_cast<int>(input_array.size()));
		}
		state.SetComplexityN(state.range(0));
		state.SetLabel("Merge_Sort");
	}
	BENCHMARK(BM_Random_MergeSort)->RangeMultiplier(2)->Range(1 << 7, 1 << 14)->Unit(benchmark::kMillisecond)
		->Complexity([](benchmark::IterationCount n) { return static_cast<double>(n); });

	static void BM_Random_QuickSort(benchmark::State& state)
	{
		auto input_array = BenchmarkTestData::create_random_data<int>(state.range(0));
		while (state.KeepRunning())
		{
			quick_sort(input_array.data(), static_cast<int>(input_array.size()));
		}
		state.SetComplexityN(state.range(0));
		state.SetLabel("Quick_Sort");
	}
	BENCHMARK(BM_Random_QuickSort)->RangeMultiplier(2)->Range(1 << 7, 1 << 14)->Unit(benchmark::kMillisecond)
		->Complexity([](benchmark::IterationCount n) { return static_cast<double>(n); });

	static void BM_Random_SelectionSort(benchmark::State& state)
	{
		auto input_array = BenchmarkTestData::create_random_data<int>(state.range(0));
		while (state.KeepRunning())
		{
			selection_sort(input_array.data(), static_cast<int>(input_array.size()));
		}
		state.SetComplexityN(state.range(0));
		state.SetLabel("Selection_Sort");
	}
	BENCHMARK(BM_Random_SelectionSort)->RangeMultiplier(2)->Range(1 << 7, 1 << 14)->Unit(benchmark::kMillisecond)
		->Complexity([](benchmark::IterationCount n) { return static_cast<double>(n); });
}

BENCHMARK_MAIN();
