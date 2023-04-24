#include <iostream>
#include <cstdint>

constexpr int VALUE = 2;

int func(const int val)
{
    const int temp = val * 2;

    return temp / 3;
}

int main()
{

    std::cout << func(VALUE) << '\n';

    return 0;
}
