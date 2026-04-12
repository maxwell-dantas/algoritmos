#include <iostream>

int mdc_euclides(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int main() {
    int x, y;
    std::cout << "X and Y: ";
    std::cin >> x >> y;
    std::cout << "MDC: " << mdc_euclides(x, y) << std::endl;
    return 0;
}