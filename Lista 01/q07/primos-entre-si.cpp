/* Sejam a e b dois números naturais positivos, eles são considerados primos entre sí se não possuírem divisores em
comum além do número 1 (um). */

#include <iostream>

bool primosEntreSi(int a, int b) {
    int menor = a;
    if (b < menor) {
        menor = b;
    }
    if (menor == 1) {return true;}

    bool validador = true;
    for (int i = 2; i <= menor; i++) {
        if (a % i == 0 && b % i == 0) {
            validador = false; 
            break;
        }
    }
    return validador;
}

int main() {
    int x, y;
    std::cout << "Enter X and Y: ";
    std::cin >> x >> y;
    std::cout << "Are " << x << " and " << y << " coprime? " << std::boolalpha << primosEntreSi(x, y) << std::endl;
    return 0;
}