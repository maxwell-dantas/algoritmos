#include <iostream>
#include <cmath>

int main() {
    int population;
    std::cin >> population;
    std::cout << ceil(std::log2(population));
    return 0;
}