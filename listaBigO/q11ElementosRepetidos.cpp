/* Dado um array A de n elementos (1 ≤ n ≤ 10^6), você deve verificar se há elementos repetidos no array. 
Os elementos são números inteiros Ai (0 ≤ Ai ≤ 10^5) e não estão ordenados.
Descreva um algoritmo para determinar quantas vezes cada valor ocorre no array. */

#include <iostream>
#include <vector>

void elementosRepetidos(std::vector<int> &a, int qtdElementos) {
    int entradaLimite = 100001;
    std::vector<int> referenceArray(entradaLimite, 0);

    for (int i = 0; i < qtdElementos; i++) {
        referenceArray[a[i]]++;
    }

    for (int i = 0; i < entradaLimite; i++) {
        if (referenceArray[i] > 0) {
            std::cout << "Elemento: " << i << "| Quantidade repetida: " << referenceArray[i] << std::endl;
        }
    }
}

int main() {
    int qtdElementos;
    std::cin >> qtdElementos;
    std::vector<int> a(qtdElementos);

    for (int i = 0; i < qtdElementos; i++) {std::cin >> a[i];}
    elementosRepetidos(a, qtdElementos);
    return 0;
}