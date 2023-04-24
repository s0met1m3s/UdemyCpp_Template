#include <iostream>
#include <string>
#include <variant>

using namespace std::string_literals;

int main()
{
    auto v = std::variant<int, double, std::string>{42};
    auto i1 = std::get<int>(v);
    // auto i2 = std::get<double>(v);
    std::cout << i1 << '\n';
    // std::cout << i2 << '\n';

    try
    {
        auto f = std::get<double>(v);
        std::cout << f << '\n';
    }
    catch (std::bad_variant_access const &e)
    {
        std::cout << e.what() << '\n'; // Unexpected index
    }

    v = 42.0;
    if (std::holds_alternative<double>(v))
    {
        std::cout << std::get<double>(v) << '\n';
    }

    return 0;
}
