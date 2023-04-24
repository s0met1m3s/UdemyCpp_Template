#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <random>
#include <thread>
#include <vector>

#include "Timer.h"

/*
Serial time:      4.569ms

2: Own time:      3.336ms
4: Own time:      3.071ms
6: Own time:      3.008ms
8: Own time:      2.975ms
*/

namespace
{
constexpr static auto NUM_THREADS = std::uint32_t{2};
constexpr static auto NUM_RUNS = std::uint32_t{1'000};
} // namespace

template <typename T>
void random_vector(std::vector<T> &vec)
{
    constexpr static auto seed = std::int32_t{42};
    constexpr static auto lower_bound = std::int32_t{-10};
    constexpr static auto upper_bound = std::int32_t{10};

    static auto random_generator = std::mt19937{seed};
    static auto random_distribution =
        std::uniform_int_distribution<T>(lower_bound, upper_bound);

    for (auto &val : vec)
    {
        val = random_distribution(random_generator);
    }
}

template <typename T>
T serial_sum(std::vector<T> &vec)
{
    auto local_sum = T{};
    const auto n = static_cast<std::uint32_t>(vec.size());

    for (std::uint32_t i = 0; i != n; ++i)
    {
        local_sum = local_sum + vec[i];
    }

    return local_sum;
}

template <typename T>
T parallel_sum(std::vector<T> &vec)
{
    auto final_sum = T{};
    std::array<T, NUM_THREADS> local_sums{};
    std::array<std::thread, NUM_THREADS> threads;

    const auto slice_size = vec.size() / NUM_THREADS;
    auto prev_last = vec.begin();

    for (std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        auto first = prev_last;
        auto last = prev_last + slice_size;

        if (i == (NUM_THREADS - 1))
        {
            last = vec.end();
        }

        threads[i] = std::thread(
            [](auto first_, auto last_, T &result) {
                result = std::accumulate(first_, last_, T{});
            },
            first,
            last,
            std::ref(local_sums[i]));

        prev_last = prev_last + slice_size;
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    for (const auto local_sum : local_sums)
    {
        final_sum += local_sum;
    }

    return final_sum;
}

int main()
{
    static auto my_vector = std::vector<std::int32_t>(30'000'000, 0);
    random_vector(my_vector);

    auto time = 0.0;
    volatile std::int32_t sum = 0;

    {
        for (std::uint32_t i = 0; i < NUM_RUNS / 10; ++i)
        {
            const auto t = cpptiming::Timer{};
            sum = serial_sum(my_vector);
            time += t.elapsed_time<cpptiming::millisecs, double>();
        }
        std::cout << "Mean Serial: " << time / (NUM_RUNS / 10)
                  << "ms sum: " << sum << '\n';
        time = 0.0;
    }

    {
        for (std::uint32_t i = 0; i < NUM_RUNS; ++i)
        {
            const auto t = cpptiming::Timer{};
            sum = parallel_sum(my_vector);
            time += t.elapsed_time<cpptiming::millisecs, double>();
        }
        std::cout << "Own MT: " << time / NUM_RUNS << "ms sum: " << sum << '\n';
    }

    return 0;
}
