#include <iostream>

// 1.) User-Input: unsigned integer number
// 2.) Compute if the number is a prime number
// 3.) Print out the result

// Prime Number: Only divisble by itself and 1 with a remainder of 0

int main()
{
    bool is_prime = true;

    unsigned int number = 0;
    std::cout << "Please give me a nummber: " << std::endl;
    std::cin >> number;

    if (number == 0 || number == 1)
    {
        is_prime = false;
    }

    for(unsigned int i=2; i < number; i++)
    {
        if(number % i == 0)
        {
            is_prime = false;
        }
    }

    std::cout << "The number " << number << " is a prime number?" << is_prime << std::endl;
    
    return 0;
}
