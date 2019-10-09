#include <itsy/benchmarks/opaque.hpp>

#include <benchmark/benchmark.h>

#include <itsy/bitsy.hpp>

#include <bitset>
#include <vector>
#include <array>
#include <cstdlib>
#include <climits>

static void
pop_front_vector_bool(benchmark::State& state)
{
	using C = std::vector<bool>;
	C c(state.iterations());

	for (auto _ : state)
		{
			c.erase(c.begin());
		}
	if (!c.empty())
		{
			state.SkipWithError("bad benchmark result");
		}
}

static void
pop_front_itsy_bitsy(benchmark::State& state)
{
	using C = bitsy::bit_vector<std::size_t>;
	C c(state.iterations());

	for (auto _ : state)
		{
			c.pop_front();
		}
	if (!c.empty())
		{
			state.SkipWithError("bad benchmark result");
		}
}

static void
pop_front_itsy_bitsy_sbv(benchmark::State& state)
{
	using C = bitsy::small_bit_vector<std::size_t>;
	C c(state.iterations());

	for (auto _ : state)
		{
			c.pop_front();
		}
	if (!c.empty())
		{
			state.SkipWithError("bad benchmark result");
		}
}

BENCHMARK(pop_front_vector_bool);
BENCHMARK(pop_front_itsy_bitsy);
BENCHMARK(pop_front_itsy_bitsy_sbv);
