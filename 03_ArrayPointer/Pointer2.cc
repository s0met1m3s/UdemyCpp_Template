#include <iostream>

int main()
{
    // Heap allocation
    int *p = new int;
    *p = 4;

    std::cout << "Memory address of p: " << &p << std::endl;                     // 0xc38
    std::cout << "Memory address of pointed value: " << p << std::endl;          // 0x440
    std::cout << "Value of the memory address p points to: " << *p << std::endl; // 4

    *p = 1337;

    std::cout << "Memory address of p: " << &p << std::endl;                     // 0xc38
    std::cout << "Memory address of pointed value: " << p << std::endl;          // 0x440
    std::cout << "Value of the memory address p points to: " << *p << std::endl; // 4

    // Heap de-allocation
    delete p;

    return 0;
}
