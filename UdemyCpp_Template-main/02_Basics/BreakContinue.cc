#include <iostream>

int main()
{
    std::int32_t sum = 0U;

    do
    {
        std::cout << "\nCurrent Sum: " << sum <<  " Enter the next value: ";
        std::int32_t input = 0U;
        std::cin >> input;

        if(input < 0)
        {
            std::cout << "Canceld while loop!" << std::endl;
            break;     // beendet die Komplette schleife
            continue;; // beendet aktuellen durchlauf
        }

        sum+= input;
    }while (true); // unedliche schleife

    return 0;
}
