#include <cmath>
#include <iostream>
#include <vector>

void fill_double_vector(std::vector<double> &vec)
{
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        vec[i] = static_cast<double>(i);
    }
}

void print_double_vector(const std::vector<double> &vec)
{
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        std::cout << "Vec[" << i << "] = " << vec[i] << std::endl;
    }
    std::cout << std::endl;
}

void exp_double_vector(std::vector<double> &vec)
{
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        vec[i] = std::exp(vec[i]);
    }
}

void log_double_vector(std::vector<double> &vec)
{
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        vec[i] = std::log(vec[i]);
    }
}

int main()
{
    std::vector<double> my_vector(3, 0.0);

    fill_double_vector(my_vector);
    print_double_vector(my_vector);

    exp_double_vector(my_vector);
    print_double_vector(my_vector);

    log_double_vector(my_vector);
    print_double_vector(my_vector);

    return 0;
}
