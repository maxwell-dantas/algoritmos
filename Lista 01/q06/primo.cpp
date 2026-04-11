/* No conjunto de números naturais positivos N+, um número n é considerado primo quando possui exatamente dois
divisores no conjunto, o número 1 e o próprio n. O número 1 não é considerado primo, pois possui apenas 1 divisor,
que é ele mesmo. O número 2 é considerado primo, pois possui exatamente 2 divisores no conjunto N+. O 2 é
também o único número par que é primo. Exemplos de números primos são 3, 5, 7, 11, 13, etc. Uma das formas
mais simples de determinar se um número é primo é contar quantos divisores o número tem, entre os possíveis
divisores, e verificar se a quantidade é igual a 2. Escreva uma função, em C++, que rebeba um número n ∈ N+ (1 ≤ n ≤ 10^9) 
e retorne um valor lógico (bool) informando se n é primo. */

#include <iostream>

bool primo(int num) {
    if (num <= 1) {return false;}
    bool validador = true;
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            validador = false; 
            break;
        }
    }
    return validador;
}

int main() {
    int x;
    std::cout << "Enter a number: ";
    std::cin >> x;
    std::cout << "Is the number " << x << " prime? " << std::boolalpha << primo(x) << std::endl;
    return 0;
}