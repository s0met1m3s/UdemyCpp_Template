#include <iostream>
#include <cmath>

// Funktion zur Abfrage von Einführungsrunden
int abfrageEinfuehrungsrunden()
{
    int einfuehrungsrunden = 0;
    std::cout << "Gibt es Einfuehrungsrunden? (1 fuer Ja, 0 fuer Nein): ";
    std::cin >> einfuehrungsrunden;
    return einfuehrungsrunden;
}

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

    int einfuehrungsrunden = abfrageEinfuehrungsrunden();

    float Runden = (Renndauer * 60 / Rundenzeit);
    float gerundet = std::ceil(Runden);

    std::cout << "Das Rennen hat " << gerundet << " Runden." << std::endl;

    // Hinzufuegen einer Einfuehrungsrunde, wenn entsprechend ausgewaehlt
    if(einfuehrungsrunden)
    {
        gerundet += 1;
        std::cout << "Du hast eine Einfuehrungsrunde." << std::endl;
    }

    float ergebnis = gerundet * Verbrauch;

    std::cout << "Du brauchst " << ergebnis << " L." << std::endl;

    return 0;
}
