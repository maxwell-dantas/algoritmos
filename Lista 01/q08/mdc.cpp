/* Escreva um algoritmo para determinar o MDC (máximo divisor comum) entre 2 números naturais positivos a e b.
Implemente e teste seu algoritmo em C++. */

#include <iostream>

int mdc(int a, int b) {
    int menor = a;
    if (b < menor) {menor = b;}
    if (menor <= 1) {return 1;}

    int divisorMaximo = 1; 
    for (int i = 2; i <= menor; i++) {
        if (a % i == 0 && b % i == 0) {
            divisorMaximo = i;
        }
    }

    return divisorMaximo;
}

int main() {
    int x, y;
    std::cout << "Enter X and Y: ";
    std::cin >> x >> y;
    std::cout << "MDC: " << mdc(x, y) << std::endl;
    return 0;
}