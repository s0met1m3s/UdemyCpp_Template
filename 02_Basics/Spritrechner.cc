#include <iostream>
#include <cmath>

int main()
{
    float Renndauer = 0;
    float Verbrauch = 0;
    float Rundenzeit = 0;

    std::cout << "Wie lange dauert dein Rennen in Minuten: ";
    std::cin >> Renndauer;

    std::cout << "Wie lange dauert eine Runde in Sekunden: ";
    std::cin >> Rundenzeit;

    std::cout << "Wie hoch ist dein Verbrauch pro Runde: ";
    std::cin >> Verbrauch;

    float Runden = (Renndauer * 60 / Rundenzeit);
    float gerundet = std::ceil(Runden);

    std::cout << "Das Rennen hat " << gerundet << " Runden." << std::endl;

    float ergebnis = gerundet * Verbrauch;

    std::cout << "Du brauchst " << ergebnis << " L." << std::endl;

    return 0;
}
