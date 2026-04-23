/* Escreva um algoritmo que, dado um array A de n números inteiros (1 ≤ n ≤ 10^5), determine a quantidade de elementos distintos em A. */

#include <iostream>
#include <vector>

int elementosDistintos(std::vector<int> a) {
    std::vector<int> b;
    for (unsigned i = 0; i < a.size(); i++) {
        bool elementoInArray = true;
        for (unsigned j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                elementoInArray = false;
                break;
            }
        }
        if (elementoInArray) {b.push_back(a[i]);}
    }
    return b.size();
}

int main() {
    int tamanhoArray;
    std::cin >> tamanhoArray;
    std::vector<int> arrayA(tamanhoArray);
    for  (int i = 0; i < tamanhoArray; i++) {
        std::cin >> arrayA[i];
    }
    std::cout << elementosDistintos(arrayA);
    return 0;
}