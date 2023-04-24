#include <iostream>

// 1.) User-Input: Länge von einem Quadrat
// 2.) Berechne Umfang und Fläche
// 3.) Ausgabe in der Console.

int main()
{
    float a = 0.0;

    std::cout << "Geben sie die Länge ihres Quaders an: ";
    std::cin >> a;

    float surface_square = a * a;
    std::cout << "Die Fläche deines Quaders beträgt: " << surface_square << std::endl;

    float perimeter_square = a *4;
    std::cout << "Der Umfang deines Quaders beträgt: " << perimeter_square << std::endl;

    return 0;
}
