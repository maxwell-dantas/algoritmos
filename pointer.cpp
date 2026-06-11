#include <iostream>

int main() {
    int *p = new int;

    std::cout << p << std::endl;
    std::cout << *p << std::endl;
    std::cout << std::endl;

    int *pArray = new int[10];
    int *pAuxiliar = pArray;

    for (unsigned int i = 0; i < 10; i++) {
        *pAuxiliar = i * 10;
        pAuxiliar++;
    }

    pAuxiliar = pArray;

    for (unsigned int i = 0; i < 10; i++) {
        std::cout << *pAuxiliar << std::endl;
        std::cout << pAuxiliar << std::endl;
        pAuxiliar++;
    }

    delete[] pArray;


    return 0;
}