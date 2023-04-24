#include <cmath>
#include <iostream>
#include <vector>


// Exercise:
// 1.) Schreibe eine Function, die einen Vector mit aufsteigenden Werten befüllt
//     void fill_vector(std::vector<double> &vec)
// 2.) Schreibe eine Function, die die Werte eines Vectors ausgibt
//      void print_vector(const std::vector<double> &vec)
// 3.) Schreibe Funktionen, die die:
// - Exponential
// - Natural Logarithm
// Werte von einem double-Vector berechnet
//      void double_vector_exp(std::vector<double> &vec)
// verwendet std::exp, std::log aus <cmath>
// [exp(0.0), exp(1.0), ...]
// [log(0.0), log(1.0), ...]
int main()
{
    auto my_vector = std::vector<double>(3, 0.0);

    fill_vector(my_vector);
    print_vector(my_vector);

    exp_vector(my_vector);
    print_vector(my_vector);

    log_vector(my_vector);
    print_vector(my_vector);

    return 0;
}
