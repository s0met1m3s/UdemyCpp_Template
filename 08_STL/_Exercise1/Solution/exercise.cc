#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

#include "exercise.h"

// Exercise 2
std::vector<bool> shuffle_till_equal(const BinaryArray &target, BinaryArray input)
{
    auto equal = false;
    auto iteration = 1U;

    while (!equal)
    {
        if (iteration % 250000 == 0)
        {
            std::cout << std::endl << "Iteration: " << iteration;
        }
        ++iteration;

        std::shuffle(input.begin(), input.end(), std::default_random_engine(42));

        if (std::equal(input.begin(), input.end(), target.begin()))
        {
            equal = true;
        }
    }

    return input;
}

// Exercise 3
std::vector<bool> smart_shuffle_till_equal(const BinaryArray &target,
                                           BinaryArray input)
{
    auto equal = false;
    auto iteration = 1U;

    auto first = input.begin();
    auto last = input.end();

    while (!equal)
    {
        if (iteration % 100000 == 0)
        {
            std::cout << std::endl << "Iteration: " << iteration;
        }
        ++iteration;

        std::shuffle(first, last, std::default_random_engine(42));

        const auto index = std::distance(input.begin(), first);

        if (*first == target[index])
            ++first;

        if (first == last)
            equal = true;
    }

    return input;
}
