#include <iostream>

int main()
{
    auto k = double{0.0F};
    std::cout << k << std::endl;

    // Bad
    int m = k;
    std::cout << m << std::endl;

    // Sermi-Bad
    auto n = static_cast<int>(k);
    std::cout << n << std::endl;

    // Good
    auto l = int{k};
    std::cout << l << std::endl;

    return 0;
}
