#include <iostream>

int foo(int a)
{

    a = a * 2;
    return a;
}

int main()
{
    int a = 2;
    int b = foo(a);

    std::cout << b << std::endl;

    return 0;
}
