#include <iostream>

int main()
{
     for (std::uint32_t i = 0; i < 5; i++)
     {
        std::cout << i << std::endl;
     }

     std::uint32_t i = 0;

     i = i + 1;
     i += 1;
     i++; //increment

     i = - 1;
     i -= 1;
     i--; //decrement


    return 0;
}
