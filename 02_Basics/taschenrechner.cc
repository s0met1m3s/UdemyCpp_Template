#include <iostream>

int main()
{
    float Zahl_1 = 0;
    float Zahl_2 = 0;
    char rechner;
    float ergebnis = 0;

    std::cout << "Tippe deine rechnung ein: " << std::endl;
    std::cin >> Zahl_1 >> rechner >> Zahl_2;


    if (rechner == '+')
    {
        ergebnis = Zahl_1 + Zahl_2;
    }
    else if (rechner == '-')
    {
        ergebnis = Zahl_1 - Zahl_2;
    }
    else if (rechner == '*')
    {
        ergebnis = Zahl_1 * Zahl_2;
    }
    else if (rechner == '/')
    {
        ergebnis = Zahl_1 / Zahl_2;
    }
    else
    {
        std::cout << "Ungültiger Operator" << std::endl;
        return 1;
    }

    std::cout << "Dein Ergebnis: " << ergebnis << std::endl;

    return 0;
}
