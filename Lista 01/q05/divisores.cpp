/* 
Escreva um programa leia um número natural positivo n (1 ≤ n ≤ 109) e mostre a quantidade de divisores de n.
• Determine o tipo da variável que deve armaenar n.
• Escreva uma função que receba n e retorne a quantidade de divisores.
• Faça testes e verifique se seu programa funciona corretamente. 
*/

#include <iostream>
int divisores(int num) {
    if (num == 1) {return 1;}
    int qtdDivisores = 2;
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            qtdDivisores++;
        }
    }
    return qtdDivisores;
};

int main() {
    int x;
    std::cout << "Numero: ";
    std::cin >> x;
    std::cout << "Quantidade de divisores: " << divisores(x) << std::endl;
    return 0;
}